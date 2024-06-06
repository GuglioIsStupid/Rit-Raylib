#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Globals.hpp" // Includes raylib.h and raymath.h
#include <string>
#include <vector>

class Sprite
{
public:
    Sprite();
    Sprite(int x, int y, const std::string &filename);
    ~Sprite();

    int x, y = 0;
    int width, height = 0;
    Texture2D texture;

    int frame = 0;
    int frameWidth, frameHeight;
    //frame frames[];
    //animation animations[];
    //animation curAnim;
    //frame curFrame;
    int indexFrame = 0;
    bool animFinished = false;
    float alpha = 1.0f;

    Vector2 origin = {0, 0};
    Vector2 scale = {1, 1};
    Vector2 offset = {0, 0};
    
    Color color = WHITE; // in reality only uses the rgb values, alpha is handled by the alpha variable

    std::string type = "Sprite";

    bool flipX, flipY = false;
    float angle = 0.0f;

    bool alive, exists, visible = true;

    std::string blend = "alpha";
    std::string blendAlpha = "alphamultiply";

    void load(std::string filename);
    std::tuple<int, int> getMidpoint();
    void update(double dt);
    void play(const std::string &animName);
    int getFrameWidth();
    int getFrameHeight();
    std::tuple<int, int> getFrameDimensions();

    void setGraphicSize(float w, float h);
    void setGraphicSize(float w);

    void updateHitbox();
    void centerOffsets();
    void centerOrigin();
    void setScale(float x, float y);
    void setScale(float x);

    void kill();
    void revive();
    void destroy();

    bool isCollidingWithPosition(int x, int y);

    void screenCenter(std::string axis = "XY");

    void draw();
};

#endif