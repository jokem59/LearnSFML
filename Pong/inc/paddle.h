#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle {
private:
    Vector2f _position;
    RectangleShape _paddleShape;
    float _paddleSpeed;

public:
    Paddle(float startX, float startY);

    FloatRect getPosition() const;
    RectangleShape getShape() const;
    void moveLeft();
    void moveRight();
    void update();
};
