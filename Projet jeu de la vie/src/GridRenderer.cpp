#include "GridRenderer.h"
#include "Grid.h"
#include "Cell.h"

GridRenderer::GridRenderer(const Game& game, float cellSize)
    : m_game(game)
    , m_cellSize(cellSize)
    , m_cellShape(sf::Vector2f(cellSize - 1.f, cellSize - 1.f))
{
    m_cellShape.setOutlineThickness(0.f);
}

void GridRenderer::draw(sf::RenderWindow& window)
{
    const Grid& g = m_game.getGrid();

    for (int y = 0; y < g.getHeight(); ++y)
    {
        for (int x = 0; x < g.getWidth(); ++x)
        {
            const Cell& cell = g.at(x, y);

            if (cell.isObstacle())
                m_cellShape.setFillColor(sf::Color::Red);      //  obstacle
            else if (cell.isAlive())
                m_cellShape.setFillColor(sf::Color::Green);    //  vivant
            else
                m_cellShape.setFillColor(sf::Color(30, 30, 30)); //  mort

            m_cellShape.setPosition(sf::Vector2f(
                x * m_cellSize,
                y * m_cellSize
            ));

            window.draw(m_cellShape);
        }
    }
}

