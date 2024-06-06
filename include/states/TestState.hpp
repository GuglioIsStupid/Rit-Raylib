#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP

#include "GameState.hpp"

class TestState : public GameState
{
public:
    void load() override;
    void unload() override;

    void update() override;
    void draw() override;

    void mousePressed(int x, int y) override;
    void mouseReleased(int x, int y) override;
};

#endif