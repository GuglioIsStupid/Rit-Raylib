/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <tuple>

Camera camera = { 0 };
Vector3 cubePosition = { 0 };

RenderTexture2D target = { 0 };

Vector2 mousePosition = { 0 };

float ratio = 1.0f;

const int screenWidth = 1280;
const int screenHeight = 720;
const int gameWidth = 1920;
const int gameHeight = 1080;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void mainUpdate(void);
static void mainDraw(void);          // Update and draw one frame
/* static std::tuple<int, int> ConvertToGameCoords(int x, int y); */

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main()
{
    

    const int targetFramerate = 1000; // <- Make this a setting

    ratio = (float)gameWidth / (float)gameHeight;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Rit");
    SetTargetFPS(targetFramerate);

    camera.position = { 10.0f, 10.0f, 8.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    mousePosition = { 0.0f, 0.0f };

    target = LoadRenderTexture(gameWidth, gameHeight);

    while (!WindowShouldClose())
    {
        mainUpdate();

        mainDraw();
    }

    CloseWindow();

    return 0;
}

// Update and draw game frame

static void mainUpdate(void)
{
    mousePosition = GetMousePosition();
    float ratio = std::min((float)GetScreenWidth() / (float)gameWidth, (float)GetScreenHeight() / (float)gameHeight);

    mousePosition.x -= (GetScreenWidth()/2);
    mousePosition.y -= (GetScreenHeight()/2);
    mousePosition.x /= ratio;
    mousePosition.y /= ratio;
    mousePosition.x += (float)gameWidth/2;
    mousePosition.y += (float)gameHeight/2;
}

static void mainDraw(void)
{
    UpdateCamera(&camera, CAMERA_ORBITAL);

    BeginTextureMode(target);
        ClearBackground(BLACK);

        BeginMode3D(camera);

            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);

        EndMode3D();

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
            { (GetScreenWidth() - ((float)target.texture.width * scale)) / 2, (GetScreenHeight() - ((float)target.texture.height * scale)) / 2, (float)target.texture.width * scale, (float)target.texture.height * scale },
            { 0.0f, 0.0f },
            0.0f,
            WHITE
        );

        ratio = (float)gameWidth / (float)gameHeight;
    EndDrawing();
}
