#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"
#include "ConwayRule.h"
#include "GridRenderer.h"

class SfmlApp
{
public:
    // stepDelaySeconds a une valeur par défaut 
    SfmlApp(int width, int height, float cellSize, float stepDelaySeconds = 0.05f);

    void run();

private:
    sf::RenderWindow m_window;
    Game            m_game;
    GridRenderer    m_renderer;

    float           m_stepDelay;   // intervalle entre deux itérations 
};
