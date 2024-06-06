#include "states/TestState.hpp"
#include "Classes/Sprite.hpp"
#include "Globals.hpp"

Sprite testSprite;

void TestState::load()
{
    testSprite.load("assets/logo.png");
    //testSprite.centerOrigin();

}

void TestState::unload()
{
}

void TestState::update()
{
}

void TestState::draw()
{
    testSprite.draw();

    DrawText("Test State", 10, 100, 50, RED);
}

void TestState::mousePressed(int x, int y)
{
}

void TestState::mouseReleased(int x, int y)
{
}
