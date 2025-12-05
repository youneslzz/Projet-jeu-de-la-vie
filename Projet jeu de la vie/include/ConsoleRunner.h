#pragma once

#include "Game.h"
#include "ConsoleRenderer.h"
#include "InputHandler.h"

class ConsoleRunner
{
public:
    ConsoleRunner(int width, int height);
    void run();

private:
    Game m_game;
    ConsoleRenderer m_renderer;
    InputHandler m_input;
};
