#pragma once

#include "Game.h"
#include "ConwayRule.h"

class LifeApp
{
public:
    LifeApp(int width, int height);

    void step();
    void clear();
    void randomize();

    Game& game();
    const Game& game() const;

private:
    Game m_game;
};
