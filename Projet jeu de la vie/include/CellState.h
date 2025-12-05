#pragma once

class Cell; // forward declaration

class CellState
{
public:
    virtual ~CellState() = default;

    virtual bool isAlive() const = 0;
    virtual char toChar() const = 0;
    virtual bool isObstacle() const { return false; }

    virtual void makeAlive(Cell& cell) = 0;
    virtual void makeDead(Cell& cell) = 0;
};
