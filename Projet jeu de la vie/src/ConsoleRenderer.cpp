#include "ConsoleRenderer.h"
#include <iostream>

ConsoleRenderer::ConsoleRenderer(const Game& game)
    : m_game(game)
{
}

void ConsoleRenderer::render() const
{
    const Grid& grid = m_game.getGrid();

    for (int y = 0; y < grid.getHeight(); ++y)
    {
        for (int x = 0; x < grid.getWidth(); ++x)
        {
            std::cout << grid.at(x, y).toChar();
        }
        std::cout << "\n";
    }

    std::cout << "-----------------------\n";
}
