#include "ObstacleState.h"
#include "Cell.h"

// Un obstacle n'est jamais vivant
bool ObstacleState::isAlive() const
{
    return false;
}

// Caractère d'affichage en mode console
char ObstacleState::toChar() const
{
    return '#';   
}
bool ObstacleState::isObstacle() const
{
    return true;
}

void ObstacleState::makeAlive(Cell& /*cell*/)
{

}

void ObstacleState::makeDead(Cell& /*cell*/)
{
    
}
