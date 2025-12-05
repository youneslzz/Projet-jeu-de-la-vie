#pragma once

#include <vector>
#include "Cell.h"

class Grid
{
public:
    Grid(int width, int height);
    bool inBounds(int x, int y) const;

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    Cell& at(int x, int y);
    const Cell& at(int x, int y) const;

    int countAliveNeighbours(int x, int y) const;

    void clear();
    void randomize();

private:
    int m_width;
    int m_height;
    std::vector<Cell> m_cells;

    int index(int x, int y) const;
};
