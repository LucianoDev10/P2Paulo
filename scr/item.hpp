#ifndef ITEM_HPP
#define ITEM_HPP

#include "raylib.h"

class Item {
public:
    Vector2 position;
    float radius;
    int scoreValue;

    Item(float x, float y, float r, int score);
    void Draw();
    bool CheckCollision(Vector2 playerPosition, float playerRadius);
    void Destroy();
};

#endif
