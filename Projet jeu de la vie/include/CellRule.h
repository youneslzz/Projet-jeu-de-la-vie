#pragma once

class CellRule {
public:
    virtual ~CellRule() = default;

    // Retourne true si la cellule sera vivante au prochain tour
    virtual bool willBeAlive(bool currentlyAlive, int aliveNeighbours) const = 0;
};
