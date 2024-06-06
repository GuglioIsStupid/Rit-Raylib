#include <iostream>
#include <string>
/* #include "rapidyaml.hpp" */

#include "Globals.hpp"
#include "GameState.hpp"
#include "states/TestState.hpp"

RenderTexture2D target = { 0 };
Vector2 mousePosition = { 0 };

Camera camera = { 0.0f };
float ratio = 1.0f;

static void mainUpdate(void);
static void mainDraw(void);

std::string songPath = "songs/D_AAN_-_Another_Me_-_607400/audio.mp3";
std::string chartPath = "songs/D_AAN_-_Another_Me_-_607400/74767.qua";

// GLOBALS
GameState* currentState = nullptr;
extern void SwitchState(GameState* newState);

int main()
{
    ratio = (float)GAME_WIDTH / (float)GAME_HEIGHT;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rit");
    SetTargetFPS(TARGET_FRAMERATE);

    mousePosition = { 0.0f, 0.0f };

    target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);

    SwitchState(new TestState());

    while (!WindowShouldClose())
    {
        mainUpdate();

        mainDraw();
    }

    CloseWindow();

    return 0;
}

static void mainUpdate(void)
{
    mousePosition = GetMousePosition();
    float ratio = std::min((float)GetScreenWidth() / (float)GAME_WIDTH, (float)GetScreenHeight() / (float)GAME_HEIGHT);

    mousePosition.x -= (GetScreenWidth()/2);
    mousePosition.y -= (GetScreenHeight()/2);
    mousePosition.x /= ratio;
    mousePosition.y /= ratio;
    mousePosition.x += (float)GAME_WIDTH/2;
    mousePosition.y += (float)GAME_HEIGHT/2;

    currentState->update();
}

static void mainDraw(void)
{
    UpdateCamera(&camera, CAMERA_ORBITAL);

    BeginTextureMode(target);
        ClearBackground(BLACK);

        currentState->draw();

        DrawText(TextFormat("Mouse Pos: [%i , %i]", (int)mousePosition.x, (int)mousePosition.y), 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);
    EndTextureMode();

    BeginDrawing();
        // letterbox'd resolution
        ClearBackground(BLACK);

        float targetRatio = (float)target.texture.width / (float)target.texture.height;
        float screenRatio = (float)GetScreenWidth() / (float)GetScreenHeight();
        float scale = 1.0f;

        scale = (targetRatio >= screenRatio) ? (float)GetScreenWidth() / (float)target.texture.width : 
                (float)GetScreenHeight() / (float)target.texture.height;

        DrawTexturePro(
            target.texture,
            { 0.0f, 0.0f, (float)target.texture.width, (float)-target.texture.height },
            { 
                (GetScreenWidth() - ((float)target.texture.width * scale)) / 2, 
                (GetScreenHeight() - ((float)target.texture.height * scale)) / 2, 
                (float)target.texture.width * scale, 
                (float)target.texture.height * scale 
            },
            { 0.0f, 0.0f },
            0.0f,
            WHITE
        );

        ratio = (float)GAME_WIDTH / (float)GAME_HEIGHT;
    EndDrawing();
}
