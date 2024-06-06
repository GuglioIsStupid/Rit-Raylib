#include "states/TestState.hpp"
#include "Classes/Sprite.hpp"
#include "Globals.hpp"

Sprite testSprite;

extern Vector2 mousePosition;

void TestState::load()
{
    testSprite.load("assets/testAsset.png");
    testSprite.centerOrigin();
    testSprite.scale = { 0.5f, 0.5f };

}

void TestState::unload()
{
}

void TestState::update()
{
    float px, py;
    px = (-mousePosition.x / 50);
    py = (-mousePosition.y / 50);

    testSprite.x = GAME_WIDTH/2-300 + px;
    testSprite.y = GAME_HEIGHT/2 + py;

    testSprite.angle += 1;
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
