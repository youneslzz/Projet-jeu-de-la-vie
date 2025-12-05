#pragma once

#include <memory>
#include "Grid.h"
#include "Rule.h"

class Game
{
public:
    Game(int width, int height, std::unique_ptr<Rule> rule);

    void clear();
    void randomize();
    void step();

    const Grid& getGrid() const;
    Grid& getGrid()
    {
        return m_grid;
    }

private:
    int m_width;
    int m_height;
    Grid m_grid;
    std::unique_ptr<Rule> m_rule;
};
