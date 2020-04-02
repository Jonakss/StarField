#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Star.hpp"
#include <unistd.h>

using star_ptr = std::unique_ptr<Star>;

int main(int argc, char *argv[]){
    const int stars = 50;
    std::array<std::unique_ptr<Star>, stars> s;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    for (int i = 0; i < stars; i++) {
      s[i] = star_ptr(new Star(1));
    }

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        for (int i = 0; i < stars; i++) {
          s[i]->update();
          s[i]->draw(window);
        }
        // Update the window
        window.display();

        usleep(100000);
    }

    return 0;
}
