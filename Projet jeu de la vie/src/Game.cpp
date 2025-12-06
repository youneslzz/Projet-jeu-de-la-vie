// Game.cpp
#include "Game.h"

Game::Game(int width, int height, std::unique_ptr<Rule> rule)
    : m_width(width)
    , m_height(height)
    , m_grid(width, height)
    , m_rule(std::move(rule))
{
     
    int cx = width / 2;
    int cy = height / 2;
    m_grid.at(cx, cy).setObstacle();
}

const Grid& Game::getGrid() const
{
    return m_grid;
}

void Game::clear()
{
    m_grid.clear();
}

void Game::randomize()
{
    m_grid.randomize();
}

void Game::step()
{
    Grid next = m_grid;   // copie des cellules (avec obstacles)

    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            const Cell& current = m_grid.at(x, y);

            // Si obstacle : on le garde tel quel et on passe à la case suivante
            if (current.isObstacle())
            {
                next.at(x, y).setObstacle();
                continue;
            }

            int neighbours = m_rule->countAliveNeighbours(m_grid, x, y);
            bool aliveNext = m_rule->apply(current.isAlive(), neighbours);

            if (aliveNext)
                next.at(x, y).setAlive();
            else
                next.at(x, y).setDead();
        }
    }

    m_grid = std::move(next);
}


