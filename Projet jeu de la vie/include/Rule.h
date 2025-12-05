#pragma once

class Grid; // déclaration avancée

class Rule
{
public:
    virtual ~Rule() = default;

    // Décide si la cellule sera vivante au prochain tour
    virtual bool apply(bool alive, int neighbours) const = 0;

    // Compte les voisins vivants autour de (x, y)
    virtual int countAliveNeighbours(const Grid& grid, int x, int y) const = 0;
};
