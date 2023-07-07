#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    Vector2f _position;

    // A RectangleShape object called ref
    RectangleShape _ballShape;

    float _xVelocity;
    float _yVelocity;

public:
    Ball(float startX, float startY);

    FloatRect getPosition();

    RectangleShape getShape();

    void setPosition(float newX, float newY);

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update();

    float getY() const;
};
