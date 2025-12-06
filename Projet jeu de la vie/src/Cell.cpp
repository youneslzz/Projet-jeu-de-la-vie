#include "Cell.h"
#include "AliveState.h"
#include "DeadState.h"
#include "ObstacleState.h"

// Constructeur par défaut : cellule morte
Cell::Cell()
    : m_state(std::make_unique<DeadState>())
{
}

// Constructeur explicite
Cell::Cell(bool alive)
{
    if (alive)
        m_state = std::make_unique<AliveState>();
    else
        m_state = std::make_unique<DeadState>();
}


Cell::Cell(const Cell& other)
{
   
    if (dynamic_cast<AliveState*>(other.m_state.get()))
        m_state = std::make_unique<AliveState>();
    else if (dynamic_cast<ObstacleState*>(other.m_state.get()))
        m_state = std::make_unique<ObstacleState>();
    else
        m_state = std::make_unique<DeadState>();
}

Cell& Cell::operator=(const Cell& other)
{
    if (this != &other)
    {
        if (dynamic_cast<AliveState*>(other.m_state.get()))
            m_state = std::make_unique<AliveState>();
        else if (dynamic_cast<ObstacleState*>(other.m_state.get()))
            m_state = std::make_unique<ObstacleState>();
        else
            m_state = std::make_unique<DeadState>();
    }
    return *this;
}

// La cellule est-elle vivante 
bool Cell::isAlive() const
{
    return m_state->isAlive();
}

// La cellule est-elle un obstacle 
bool Cell::isObstacle() const
{
    return dynamic_cast<ObstacleState*>(m_state.get()) != nullptr;
}

// Retour en caractère pour l'affichage console
char Cell::toChar() const
{
    return m_state->toChar();
}

// Devient vivante
void Cell::setAlive()
{
    m_state = std::make_unique<AliveState>();
}

// Devient morte
void Cell::setDead()
{
    m_state = std::make_unique<DeadState>();
}

// Devient un obstacle
void Cell::setObstacle()
{
    m_state = std::make_unique<ObstacleState>();
}

// Change l'état avec polymorphisme
void Cell::setState(std::unique_ptr<CellState> state)
{
    m_state = std::move(state);
}
