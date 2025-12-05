#pragma once
#include "CellState.h"

class AliveState : public CellState
{
public:
    bool isAlive() const override { return true; }
    char toChar() const override { return 'O'; }

    void makeAlive(Cell& cell) override {}
    void makeDead(Cell& cell) override;
};
