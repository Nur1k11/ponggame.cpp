#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Paddle2.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Pong Game - C++ & Raylib");
    SetTargetFPS(60);

    Ball ball(screenWidth / 2.0f, screenHeight / 2.0f, 10.0f, WHITE);

    Paddle leftPaddle(30.0f, screenHeight / 2.0f - 50.0f, RED);
    Paddle2 rightPaddle(screenWidth - 30.0f - 20.0f, screenHeight / 2.0f - 50.0f, BLUE);

    while (!WindowShouldClose()) {
        ball.Update();
        leftPaddle.Update();
        rightPaddle.Update();

        Rectangle leftRect = leftPaddle.GetRect();
        Rectangle rightRect = rightPaddle.GetRect();

        if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), leftRect)) {
            ball.BounceX(leftRect.x + leftRect.width + ball.GetRadius());
        }

        if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), rightRect)) {
            ball.BounceX(rightRect.x - ball.GetRadius());
        }

        // 3. Отрисовка
        BeginDrawing();
        ClearBackground(BLACK);

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, DARKGRAY);

        leftPaddle.Draw();
        rightPaddle.Draw();
        ball.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}