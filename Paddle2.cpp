#include "Paddle2.h"

Paddle2::Paddle2(float x, float y, Color c) {
	position = { x, y };
	size = { 25.0f, 120.0f };
	speed = 7;
	color = c;
}

void Paddle2::Update() {
	if (IsKeyDown(KEY_UP)) position.y -= speed;
	if (IsKeyDown(KEY_DOWN)) position.y += speed;
	if (position.y < 0) position.y = 0;
	if (position.y + size.y > GetScreenHeight()) position.y = GetScreenHeight() - size.y;
}

void Paddle2::Draw() {
	DrawRectangleV(position, size, color);
}

Rectangle Paddle2::GetRect() {
	return Rectangle{ position.x, position.y, size.x, size.y };
}
