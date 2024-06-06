#include "GameState.hpp"

extern GameState* currentState;

// setup base class for game states
void GameState::load()
{
}

void GameState::unload()
{
}

void GameState::update()
{
}

void GameState::draw()
{
}

void GameState::mousePressed(int x, int y)
{
}

void GameState::mouseReleased(int x, int y)
{
}

void SwitchState(GameState* newState)
{
    if (currentState != nullptr)
    {
        currentState->unload();
    }

    currentState = newState;
    currentState->load();
}