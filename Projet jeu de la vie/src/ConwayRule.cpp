#include "ConwayRule.h"

// Ici on réutilise directement le calcul déjà codé dans Grid
int ConwayRule::countAliveNeighbours(const Grid& grid, int x, int y) const
{
    return grid.countAliveNeighbours(x, y);
}

bool ConwayRule::apply(bool alive, int neighbours) const
{
    // Règles de Conway :
    // 1. Une cellule vivante avec 2 ou 3 voisins reste vivante.
    // 2. Une cellule morte avec exactement 3 voisins devient vivante.
    // 3. Sinon : morte.

    if (alive)
        return (neighbours == 2 || neighbours == 3);
    else
        return (neighbours == 3);
}
