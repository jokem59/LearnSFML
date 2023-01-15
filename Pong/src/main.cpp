#include "paddle.h"
#include "ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

constexpr int WINDOW_HEIGHT = 1024;
constexpr int WINDOW_WIDTH = 768;

int main()
{
    RenderWindow window(VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Pong");

    auto score = 0;
    auto lives = 3;

    auto paddle = Paddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 20);
    auto ball = Ball(WINDOW_WIDTH / 2, 1);

    Text hud;
    Font font;
    font.loadFromFile("/home/jokem/.local/share/fonts/RobotoMono-Medium.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Handle keyboard updates
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            bat.moveLeft();
        } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            bat.moveRight();
        } else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Update the frame
    }

    return 0;
}
