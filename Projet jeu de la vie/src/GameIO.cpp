#include "GameIO.h"

#include <fstream>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

Game loadGameFromFile(const std::string& filePath)
{
    std::ifstream in(filePath);
    if (!in)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier d'entree : " + filePath);
    }

    int height = 0;
    int width = 0;

    
    in >> height >> width;
    if (!in || width <= 0 || height <= 0)
    {
        throw std::runtime_error("Dimensions invalides dans le fichier d'entree");
    }

    Game game(width, height, std::make_unique<ConwayRule>());
    game.clear(); 

    Grid& grid = game.getGrid();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int value = 0;
            in >> value;
            if (!in)
            {
                throw std::runtime_error("Format de matrice invalide dans le fichier d'entree");
            }

            if (value == 1)
            {
                grid.at(x, y).setAlive();
            }
            else
            {
                grid.at(x, y).setDead();
            }
        }
    }

    return game;
}

void saveGridToFile(const Game& game, const std::string& filePath)
{
    std::ofstream out(filePath);
    if (!out)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier de sortie : " + filePath);
    }

    const Grid& grid = game.getGrid();
    const int width = grid.getWidth();
    const int height = grid.getHeight();

    out << height << ' ' << width << '\n';

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            const Cell& c = grid.at(x, y);
            out << (c.isAlive() ? 1 : 0);

            if (x + 1 < width)
                out << ' ';
        }
        out << '\n';
    }
}
