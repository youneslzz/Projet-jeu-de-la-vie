#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class GridRenderer
{
public:
    GridRenderer(const Game& game, float cellSize);

    void draw(sf::RenderWindow& window);

private:
    const Game& m_game;
    float            m_cellSize;
    sf::RectangleShape m_cellShape;
};
