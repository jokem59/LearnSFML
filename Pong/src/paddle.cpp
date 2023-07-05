#include <paddle.h>

Paddle::Paddle(float startX, float startY) {
    _paddleSpeed = 0.3f;
    _position.x = startX;
    _position.y = startY;

    _paddleShape.setSize(sf::Vector2f(100, 5));
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
    auto delta = _position.x - _paddleSpeed;
    if (delta <= 0) {
        _position.x = 0;
    } else {
        _position.x -= _paddleSpeed;
    }
    return;
}

void Paddle::moveRight() {
    auto delta = _position.x + _paddleSpeed;

    // TODO: Window width is actually 1024
    if (delta + 100 >= 1024) {
        _position.x = 1024 - 100;
    } else {
        _position.x += _paddleSpeed;
    }
    return;
}

void Paddle::update() {
    _paddleShape.setPosition(_position);
    return;
}
