#pragma once
#include "CellState.h"

class ObstacleState : public CellState
{
public:
    // Un obstacle n'est jamais vivant
    bool isAlive() const override;

    // Caractère utilisé en mode console
    char toChar() const override;

    // Indique qu'il s'agit d'un obstacle
    bool isObstacle() const override;

    // Pour un obstacle, ces opérations ne changent rien :
    void makeAlive(Cell& cell) override;
    void makeDead(Cell& cell) override;
};
