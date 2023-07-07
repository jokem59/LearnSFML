#include <ball.h>

Ball::Ball(float startX, float startY)
{
    _xVelocity = 0.2f;
    _yVelocity = 0.2f;
    _position.x = startX;
    _position.y = startY;

    _ballShape.setSize(sf::Vector2f(10, 10));
    _ballShape.setPosition(_position);
}

FloatRect Ball::getPosition()
{
    return _ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
    return _ballShape;
}

void Ball::setPosition(float newX, float newY)
{
    _position.x = newX;
    _position.y = newY;
}

float Ball::getXVelocity()
{
    return _xVelocity;
}

void Ball::reboundSides()
{
    _xVelocity *= -1;
    return;
}

void Ball::reboundBatOrTop()
{
    _position.y -= (_yVelocity * 30);
    _yVelocity *= -1;
    return;
}

void Ball::hitBottom()
{
    _position.y = 1;
    _position.x = 500;
    return;
}

void Ball::update()
{
    // Update the ball position variables
    _position.y += _yVelocity;
    _position.x += _xVelocity;

    // Move the ball and the bat
    _ballShape.setPosition(_position);
    return;
}

float Ball::getY() const {
    return _position.y;
}
