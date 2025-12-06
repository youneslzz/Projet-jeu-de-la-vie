#include "Game.h"
#include "ConwayRule.h"
#include "Grid.h"      
#include <cassert>
#include <iostream>

void runUnitTests()
{
    std::cout << "Lancement des tests unitaires...\n";

    // =========================
    // Test 1 : bloc 2x2 stable
    // =========================
    {
        Game game(4, 4, std::make_unique<ConwayRule>());
        game.clear();

        Grid& g = game.getGrid();

        // On allume un bloc 2x2 au centre
        g.at(1, 1).setAlive();
        g.at(2, 1).setAlive();
        g.at(1, 2).setAlive();
        g.at(2, 2).setAlive();

        // On fait quelques iterations
        for (int i = 0; i < 5; ++i)
        {
            game.step();
        }

        // Le bloc 2x2 doit rester identique
        assert(g.at(1, 1).isAlive());
        assert(g.at(2, 1).isAlive());
        assert(g.at(1, 2).isAlive());
        assert(g.at(2, 2).isAlive());

        std::cout << "Test bloc 2x2 stable : OK\n";
    }

    // ==========================================
    // Test 2 : grille torique (voisins du coin)
    // ==========================================
    {
        Grid grid(3, 3);
        grid.clear();

        // On allume seulement les 4 coins
        grid.at(0, 0).setAlive(); // coin haut gauche
        grid.at(2, 0).setAlive(); // haut droite
        grid.at(0, 2).setAlive(); // bas gauche
        grid.at(2, 2).setAlive(); // bas droite

        // On compte les voisins de (0,0)
        int neighbours = grid.countAliveNeighbours(0, 0);

        // Sur une grille NON torique : 0 voisins vivants
        // Sur une grille TORIQUE : (2,0), (0,2), (2,2) sont voisins => 3 vivants
        assert(neighbours == 3);

        std::cout << "Test grille torique (coin 0,0, voisins = 3) : OK\n";
    }

    std::cout << "Tous les tests unitaires se sont termines avec succes.\n";
}
