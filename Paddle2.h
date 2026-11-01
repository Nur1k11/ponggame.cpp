#pragma once
#pragma once
#ifndef PADDLE2_H
#define PADDLE2_H

#include "raylib.h"

class Paddle2 {
private:
	Vector2 position;
	int speed;
	Vector2 size;
	Color color;
public:
	Paddle2(float x, float y, Color c);
	void Update();
	void Draw();
	Rectangle GetRect();
};

#endif