#pragma once
#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

class Paddle {
private:
	Vector2 position;
	int speed;
	Vector2 size;
	Color color;
public:
	Paddle(float x, float y, Color c);
	void Update();
	void Draw();
	Rectangle GetRect();
};

#endif
