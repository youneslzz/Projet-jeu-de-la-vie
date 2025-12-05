#pragma once
#include "CellState.h"

class DeadState : public CellState
{
public:
    bool isAlive() const override { return false; }
    char toChar() const override { return '.'; }

    void makeAlive(Cell& cell) override;
    void makeDead(Cell& cell) override {}
};
