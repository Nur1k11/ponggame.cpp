#pragma once
#ifndef BALL_H
#define BALL_H
#include "raylib.h"

class Ball {
private:
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;
public:
    Ball(float x, float y, float r, Color c);
    void Update();
    void Draw();
    void BounceX(float targetX);

    Vector2 GetPosition() const { return position; }
    float GetRadius() const { return radius; }
};
#endif
