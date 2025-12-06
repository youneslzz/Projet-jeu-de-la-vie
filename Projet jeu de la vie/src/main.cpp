#include "SfmlApp.h"
#include "GameIO.h"      
#include "Tests.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <exception>
#include <cstdlib>
#include <ctime>

namespace fs = std::filesystem;

// Définie dans Tests.cpp
void runUnitTests();

// --------- MODE CONSOLE (fichier d'entrée) ---------
static void runConsoleMode(const std::string& inputPath, int iterations)
{
    try
    {
        // 1) On charge le jeu à partir du fichier
        Game game = loadGameFromFile(inputPath);

        // 2) On prépare le dossier de sortie <nom_fichier>_out
        fs::path inPath(inputPath);
        std::string baseName = inPath.stem().string();   // nom sans extension
        fs::path outDir = baseName + "_out";

        fs::create_directories(outDir);

        // 3) Sauvegarde de l'état initial (itération 0)
        saveGridToFile(game, (outDir / "step_0.txt").string());

        // 4) On fait les itérations et on sauve chaque état
        for (int i = 1; i <= iterations; ++i)
        {
            game.step();

            fs::path outFile = outDir / ("step_" + std::to_string(i) + ".txt");
            saveGridToFile(game, outFile.string());
        }

        std::cout << "Mode console termine. "
            << iterations << " iterations ecrites dans le dossier "
            << outDir << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Erreur en mode console : " << ex.what() << '\n';
    }
}

// --------- MAIN ---------
int main(int argc, char* argv[])
{
    // Seed pour la randomisation (mode graphique / randomize)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // === 1) CAS AVEC ARGUMENTS (compatibilité) ==========================
    //    Mode tests unitaires : 
    //    ProjetJeuDeLaVie.exe --test
    if (argc == 2 && std::string(argv[1]) == "--test")
    {
        runUnitTests();
        return 0;
    }

    //  Mode console :
    //   1) ProjetJeuDeLaVie.exe input.txt        -> 10 iterations
    //   2) ProjetJeuDeLaVie.exe input.txt 30     -> 30 iterations
    if (argc == 2)
    {
        std::string inputPath = argv[1];
        int iterations = 10;   // valeur par défaut
        runConsoleMode(inputPath, iterations);
        return 0;
    }

    if (argc == 3)
    {
        std::string inputPath = argv[1];
        int iterations = std::stoi(argv[2]);
        runConsoleMode(inputPath, iterations);
        return 0;
    }

    // === 2) AUCUN ARGUMENT -> MENU INTERACTIF ===========================
    std::cout << "==============================\n";
    std::cout << "       JEU DE LA VIE\n";
    std::cout << "==============================\n";
    std::cout << "Choisissez un mode :\n";
    std::cout << "1 - Mode console (fichier d'entree)\n";
    std::cout << "2 - Mode graphique SFML\n";
    std::cout << "3 - Mode tests unitaires\n";
    std::cout << "> ";

    int choix = 0;
    std::cin >> choix;

    switch (choix)
    {
    case 1:
    {
        std::string inputPath;
        int iterations;

        std::cout << "Chemin du fichier d'entree : ";
        std::cin >> inputPath;

        std::cout << "Nombre d'iterations a generer : ";
        std::cin >> iterations;

        runConsoleMode(inputPath, iterations);
        break;
    }
    case 2:
    {
        const int width = 100;
        const int height = 100;
        const float cellSize = 7.0f;

        SfmlApp app(width, height, cellSize);
        app.run();
        break;
    }
    case 3:
    {
        std::cout << "Execution des tests unitaires...\n";
        runUnitTests();
        break;
    }
    default:
        std::cout << "Choix invalide, fin du programme.\n";
        break;
    }

    return 0;
}
