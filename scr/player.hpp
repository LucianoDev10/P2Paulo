#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

class Player {
public:
    Vector2 position;
    float radius;
    int score;

    Player(float x, float y, float r);
    void Move();
    void Draw();
    void CollectItem(int itemScore);
};

#endif
