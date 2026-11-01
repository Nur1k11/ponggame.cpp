#include "Ball.h"

Ball::Ball(float x, float y, float r, Color c) {
	position = { x, y };
	speed = { 5.0f, 5.0f };
	radius = r;
	color = c;
}

void Ball::Update() {
	position.x += speed.x;
	position.y += speed.y;
	
	if (position.y - radius < 0) {
		position.y = radius;
		speed.y = -speed.y;    
	}

	if (position.y + radius > GetScreenHeight()) {
		position.y = GetScreenHeight() - radius;
		speed.y = -speed.y;
	}

	if (position.x + radius < 0 || position.x - radius > GetScreenWidth()) {
		position.x = GetScreenWidth() / 2.0f;
		position.y = GetScreenHeight() / 2.0f;
		speed.x = -speed.x;
	}
}

void Ball::Draw() {
	DrawCircleV(position, radius, color);
}

void Ball::BounceX(float targetX) {
	speed.x = -speed.x;
	position.x = targetX; 
}