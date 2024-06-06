#include "Classes/Sprite.hpp"
#include "Globals.hpp"

#include <iostream>

Sprite::Sprite()
{
    x = 0;
    y = 0;
}

Sprite::Sprite(int x, int y, const std::string &filename)
{
    this->x = x;
    this->y = y;

    load(filename);
}

Sprite::~Sprite()
{
    UnloadTexture(texture);
}

void Sprite::load(const std::string filename)
{
    exists = true;
    alive = true;
    visible = true;
    texture = LoadTexture(filename.c_str());
    SetTextureFilter(texture, TEXTURE_FILTER_TRILINEAR);

    width = texture.width;
    height = texture.height;
}

void Sprite::centerOrigin()
{
    origin.x = width / 2;
    origin.y = height / 2;
}

void Sprite::draw()
{
    if (exists && alive && visible) {
        int x, y;
        x = this->x;
        y = this->y;

        float sx, sy;
        int ox, oy;
        sx = scale.x;
        sy = scale.y;
        ox = origin.x;
        oy = origin.y;

        std::cout << "x: " << x << " y: " << y << " sx: " << sx << " sy: " << sy << " ox: " << ox << " oy: " << oy << std::endl;
        
        Color c = color;
        c.a = alpha * 255;

        x += ox - offset.x;
        y += oy - offset.y;

        if (flipX)
        {
            sx = -sx;
            x += width;
        }

        if (flipY)
        {
            sy = -sy;
            y += height;
        }

        DrawTexturePro(
            texture,
            { 0.0f, 0.0f, (float)texture.width, (float)texture.height },
            { 
                (float)x,
                (float)y, 
                (float)width * sx, 
                (float)height * sy 
                },
            { (float)ox* sx, (float)oy * sy },
            angle,
            c
        );
    }
}