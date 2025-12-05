#pragma once

#include <memory>
#include "CellState.h"

class Cell
{
public:
    Cell();
    explicit Cell(bool alive);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);

    bool isAlive() const;
    bool isObstacle() const;     
    char toChar() const;

    void setAlive();
    void setDead();
    void setObstacle();          
    void setState(std::unique_ptr<CellState> state);

private:
    std::unique_ptr<CellState> m_state;
};
