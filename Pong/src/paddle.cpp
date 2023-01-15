#include <paddle.h>

Paddle::Paddle(float startX, float startY) {
    _paddleSpeed = 0.3f;
    _position.x = startX;
    _position.y = startY;

    _paddleShape.setSize(sf::Vector2f(50, 5));
    _paddleShape.setPosition(_position);
    return;
}

FloatRect Paddle::getPosition() const {
    return _paddleShape.getGlobalBounds();
}

RectangleShape Paddle::getShape() const {
    return _paddleShape;
}

void Paddle::moveLeft() {
    _position.x -= _paddleSpeed;
    return;
}

void Paddle::moveRight() {
    _position.x += _paddleSpeed;
    return;
}

void Paddle::update() {
    _paddleShape.setPosition(_position);
    return;
}
