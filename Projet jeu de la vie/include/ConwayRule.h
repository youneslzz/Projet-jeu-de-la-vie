#pragma once

#include "Rule.h"
#include "Grid.h"

class ConwayRule : public Rule
{
public:
    // Règle de Conway : retourne vrai si la cellule sera vivante
    bool apply(bool alive, int neighbours) const override;

    // Compte les voisins vivants
    int countAliveNeighbours(const Grid& grid, int x, int y) const override;
};
