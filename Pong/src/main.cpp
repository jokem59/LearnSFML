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

    auto paddle = Paddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 350);
    auto ball = Ball(WINDOW_WIDTH / 2, 1);

    Text hud;
    Font font;
    font.loadFromFile("../res/RobotoMono-Medium.ttf");
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
            paddle.moveLeft();
        } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            paddle.moveRight();
        } else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        //
        // Update the frame
        //

        // Ball hits the bottom
        if (ball.getPosition().top < 0) {
            ball.reboundBatOrTop();

            score++; // player get's a point
        }

        // Ball hits the side, 10 is hardcoded size in Ball class so it appears here
        Vector2u size = window.getSize();
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > size.x) {
            ball.reboundSides();
        }

        // Ball hits the paddle maybe
        if (ball.getPosition().intersects(paddle.getPosition())) {
            ball.reboundBatOrTop();
        }

        ball.update();
        paddle.update();

        // Update the HUD
        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());

        //
        // Draw the frame
        //

        // Clear everything from last frame
        window.clear(Color(26, 128, 182, 255));
        window.draw(paddle.getShape());
        window.draw(ball.getShape());
        window.draw(hud);

        // Show everything we drew
        window.display();
    }

    return 0;
}
