#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "being.h"
#include "waddleblockus.h"

void draw_being(Being being, sf::Texture texture, sf::RenderWindow *window) {
    std::vector<Rectangle> worldBoxes = being.getPartWorldBoxes();
    for (int i = 0; i < worldBoxes.size(); i++) {
        int x = worldBoxes.at(i).x;
        int y = worldBoxes.at(i).y;
        int width = worldBoxes.at(i).width;
        int height = worldBoxes.at(i).height;
        /*sf::RectangleShape shape(sf::Vector2f(width, height));
        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(sf::Color(52, 101, 36));
        shape.setOutlineColor(sf::Color(117, 113, 97));
        shape.setOutlineThickness(4);*/
        sf::Sprite sprite;
        sprite.setTexture(texture);
        if (width == 16 && height == 16) {
            sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        } else if (width == 128 && height == 96) {
            sprite.setTextureRect(sf::IntRect(0, 16, 128, 96));
        }
        sprite.setPosition(sf::Vector2f(x, y));
        //(*window).draw(shape);
        (*window).draw(sprite);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600),
                      "Lobbit: Little Hunter of Big Things");

    WaddleBlockus waddler(10, 10);

    sf::Texture body_parts_texture;
    if (!body_parts_texture.loadFromFile("img/bodyparts.png"))
    {
        std::cout << "Error loading texture, dawg." << std::endl;
    }

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last
        // iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        int time_delta = clock.restart().asMilliseconds();

        waddler.update(time_delta);

        window.clear(sf::Color::Black);

        draw_being(waddler, body_parts_texture, &window);

        window.display();
    }

    return 0;
}
