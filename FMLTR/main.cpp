#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create the window in full screen mode
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Bouncing Square", sf::Style::Fullscreen);

    // Set the square position and size
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(50, 50));
    square.setPosition(window.getSize().x / 2 - square.getSize().x / 2, window.getSize().y / 2 - square.getSize().y / 2);

    // Set the fill color of the square
    square.setFillColor(sf::Color::Red);

    // Initial velocity for the square
    sf::Vector2f velocity(100.0f, 100.0f);

    // Create a clock to measure the elapsed time
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Measure the elapsed time
        float elapsedTime = clock.restart().asSeconds();

        // Update the square position
        square.move(velocity * elapsedTime);

        // Check if the square has hit the edge of the window
        if (square.getPosition().x <= 0 || square.getPosition().x + square.getSize().x >= window.getSize().x)
        {
            velocity.x = -velocity.x;
            square.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (square.getPosition().y <= 0 || square.getPosition().y + square.getSize().y >= window.getSize().y)
        {
            velocity.y = -velocity.y;
            square.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
        }

        // Check if the square has fallen into a corner of the window
        if ((square.getPosition().x <= 0 && square.getPosition().y <= 0) ||
            (square.getPosition().x + square.getSize().x >= window.getSize().x && square.getPosition().y <= 0) ||
            (square.getPosition().x <= 0 && square.getPosition().y + square.getSize().y >= window.getSize().y) ||
            (square.getPosition().x + square.getSize().x >= window.getSize().x && square.getPosition().y + square.getSize().y >= window.getSize().y))
        {
            window.close();
        }

        // Clear the window
        window.clear();

        // Draw the square
        window.draw(square);

        // Display the changes
        window.display();
    }

    std::cout << "Program terminated." << std::endl;
    return 0;
}
