#include "Player.hpp"
#include "raylib.h"

Player::Player(float x, float y, float r) {
    position = {x, y};
    radius = r;
    score = 0;
}

void Player::Move() {
    if (IsKeyDown(KEY_RIGHT)) position.x += 5.0f;
    if (IsKeyDown(KEY_LEFT)) position.x -= 5.0f;
    if (IsKeyDown(KEY_UP)) position.y -= 5.0f;
    if (IsKeyDown(KEY_DOWN)) position.y += 5.0f;

    // Clamp the player's position inside the screen
    position.x = Clamp(position.x, radius, GetScreenWidth() - radius);
    position.y = Clamp(position.y, radius, GetScreenHeight() - radius);
}

void Player::Draw() {
    DrawCircleV(position, radius, YELLOW);
}

void Player::CollectItem(int itemScore) {
    score += itemScore;
}
