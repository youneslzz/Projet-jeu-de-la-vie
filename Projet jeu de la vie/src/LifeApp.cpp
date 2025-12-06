#include "LifeApp.h"

LifeApp::LifeApp(int width, int height)
    : m_game(width, height, std::make_unique<ConwayRule>())
{
    m_game.randomize();
}

void LifeApp::step() { m_game.step(); }
void LifeApp::clear() { m_game.clear(); }
void LifeApp::randomize() { m_game.randomize(); }

Game& LifeApp::game() { return m_game; }
const Game& LifeApp::game() const { return m_game; }
