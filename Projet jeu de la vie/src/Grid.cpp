#include "Grid.h"
#include "AliveState.h"
#include "DeadState.h"

#include <cstdlib>   
#include <memory>   



bool Grid::inBounds(int x, int y) const
{
    return x >= 0 && x < m_width &&
        y >= 0 && y < m_height;
}


Grid::Grid(int width, int height)
    : m_width(width), m_height(height), m_cells(width* height)
{
}

int Grid::index(int x, int y) const
{
    return y * m_width + x;
}

Cell& Grid::at(int x, int y)
{
    return m_cells[index(x, y)];
}

const Cell& Grid::at(int x, int y) const
{
    return m_cells[index(x, y)];
}

int Grid::countAliveNeighbours(int x, int y) const
{
    int count = 0;

    for (int dy = -1; dy <= 1; ++dy)
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            if (dx == 0 && dy == 0)
                continue; // on ignore la cellule elle-même

            // Calcul des coordonnées voisines avec wrap torique
            int nx = (x + dx + m_width) % m_width;   // 0 .. m_width  - 1
            int ny = (y + dy + m_height) % m_height;  // 0 .. m_height - 1

            // Accès correct à la cellule voisine
            if (at(nx, ny).isAlive())
                ++count;
            
        }
    }

    return count;
}


void Grid::clear()
{
    for (auto& cell : m_cells)
        cell.setDead();
}

void Grid::randomize()
{
    for (auto& cell : m_cells)
    {
        int r = std::rand() % 200;  

        if (r == 0)
        {
            cell.setObstacle();
        }
        else if (r < 52)
        {
            cell.setAlive();
        }
        else
        {
            cell.setDead();
        }
    }
}



