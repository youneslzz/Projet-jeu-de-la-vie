#include "AliveState.h"
#include "DeadState.h"
#include "Cell.h"

void AliveState::makeDead(Cell& cell)
{
    cell.setState(std::make_unique<DeadState>());
}
