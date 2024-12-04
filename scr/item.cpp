#include "Item.hpp"
#include "raylib.h"

Item::Item(float x, float y, float r, int score) {
    position = {x, y};
    radius = r;
    scoreValue = score;
}

void Item::Draw() {
    DrawCircleV(position, radius, GREEN);
}

bool Item::CheckCollision(Vector2 playerPosition, float playerRadius) {
    float distance = Vector2Distance(playerPosition, position);
    return (distance <= (playerRadius + radius));
}

void Item::Destroy() {
    // Item is collected, you can set position off-screen or simply destroy it by not drawing
    position = {-1000, -1000};  // Move the item out of the screen
}
