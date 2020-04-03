#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Mouse.hpp>

class Star{
  public:
    Star(float r);
    void draw(sf::RenderWindow& w);
    void update();
  private:
    // int _x,_y,x,y, lx, ly;
    static const int HEIGTH = 600;
    static const int WIDTH = 800;
    int a;
    sf::Vector2f _pos, pos, lpos, center;
    float z,r;
    sf::Vertex line[2];
    sf::CircleShape circle;
};
