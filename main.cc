#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "being.h"
#include "waddleblockus.h"

void draw_being(Being being, sf::RenderWindow *window) {
    std::vector<Rectangle> worldBoxes = being.getPartWorldBoxes();
    for (int i = 0; i < worldBoxes.size(); i++) {
        int x = worldBoxes.at(i).x;
        int y = worldBoxes.at(i).y;
        int width = worldBoxes.at(i).width;
        int height = worldBoxes.at(i).height;
        sf::RectangleShape shape(sf::Vector2f(width, height));
        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(sf::Color(100, 250, 50));
        (*window).draw(shape);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600),
                      "Lobbit: Little Hunter of Big Things");

    WaddleBlockus waddler(10, 10);

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

        draw_being(waddler, &window);

        window.display();
    }

    return 0;
}
