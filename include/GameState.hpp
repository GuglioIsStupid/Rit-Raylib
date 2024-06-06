#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

// setup base class for game states
class GameState
{
public:
    virtual void load() = 0;
    virtual void unload() = 0;

    virtual void update() = 0;
    virtual void draw() = 0;

    virtual void mousePressed(int x, int y) = 0;
    virtual void mouseReleased(int x, int y) = 0;
};

#endif