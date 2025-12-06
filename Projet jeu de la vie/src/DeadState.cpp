#include "DeadState.h"
#include "AliveState.h"
#include "Cell.h"

void DeadState::makeAlive(Cell& cell)
{
    cell.setState(std::make_unique<AliveState>());
}
