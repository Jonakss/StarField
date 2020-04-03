#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>

class Star{
  public:
    Star(float r);
    void draw(sf::RenderWindow& w);
    void update();
  private:
    sf::Vector2f _pos, pos, lpos, center;
    float z,r;
    sf::Vertex line[2];
    sf::CircleShape circle;
};
