#include "Paddle.h"

Paddle::Paddle(float x, float y, Color c) {
	position = { x, y };
	speed = 7;
	size = { 25.0f, 120.0f };
	color = c;
}

void Paddle::Update() {
	if (IsKeyDown(KEY_W)) position.y -= speed;
	if (IsKeyDown(KEY_S)) position.y += speed;
	if (position.y < 0) position.y = 0;
	if (position.y + size.y > GetScreenHeight()) position.y = GetScreenHeight() - size.y;
}

void Paddle::Draw() {
	DrawRectangleV(position, size, color);
}

Rectangle Paddle::GetRect() {
	return Rectangle{ position.x, position.y, size.x, size.y };
}