#include "Enemy.hpp"
#include "raylib.h"

Enemy::Enemy(float x, float y, float r) {
    position = {x, y};
    radius = r;
}

void Enemy::Draw() {
    DrawCircleV(position, radius, DARKGRAY);
}

void Enemy::Update() {
    position.x -= 3.0f; // Move left (can be modified for more logic)
}
