#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"

class Enemy {
public:
    Vector2 position;
    float radius;

    Enemy(float x, float y, float r);
    void Draw();
    void Update();
};

#endif
