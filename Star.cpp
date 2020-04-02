#include "Star.hpp"
#include <math.h>

Star::Star(float r = 0){
  this->r = r;
  this->lx = this->_x = this->x = rand()%800;
  this->ly = this->_y = this->y = rand()%600;
  this->z = rand()%10;

  this->circle = sf::CircleShape(this->r, this->r+10);
};

void Star::draw(sf::RenderWindow& w){
  w.draw(this->circle);
  w.draw(this->line, 2, sf::Lines);
};

void Star::update(){
  if(this->x < 400)
    this->lx = this->x -= this->z*10;
  else
    this->lx = this->x += this->z*10;
  if(this->y < 300)
    this->ly = this->y -= this->z*10;
  else
    this->ly = this->y += this->z*10;

  // if (this->x > 400 && this->y < 300){
  //   this->lx += this->r * this->z;
  //   this->ly -= this->r * this->z * this->z;
  // }
  // if (this->x < 400 && this->y > 300){
  //   this->lx -= this->r * this->z;
  //   this->ly += this->r * this->z;
  // }

  if(this->z > 50){
    this->z = 0;
    this->lx = this->_x = this->x = rand()%800;
    this->ly = this->_y = this->y = rand()%600;
  }else{
    this->z += 1;
  }

    this->line[0] = sf::Vertex(sf::Vector2f(this->_x, this->_y));
    this->line[1] = sf::Vertex(sf::Vector2f(this->lx, this->ly));

  this->circle.setPosition(this->x, this->y);
  this->circle.setRadius(this->r * this->z);
};
