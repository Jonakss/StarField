#include "Star.hpp"
#include <math.h>
#include "consts.hpp"


Star::Star(float r = 0){
  this->r = r;
  this->lpos = this->_pos = this->pos = sf::Vector2f(rand()%HEIGTH, rand()%WIDTH);
  this->z = rand()%10;
  this->center = sf::Vector2f(HEIGTH / 2, WIDTH/2);

  this->circle = sf::CircleShape(this->r, this->r+10);
  this->circle.setPosition(this->pos);
};

void Star::draw(sf::RenderWindow& w){
  w.draw(this->line, 2, sf::Lines);
  w.draw(this->circle);
};

void Star::update(){

  this->_pos = this->pos;
  if(this->pos.x < this->center.x)
    this->lpos.x = this->pos.x -= this->z*this->z;
  else
    this->lpos.x = this->pos.x += this->z*this->z;
  if(this->pos.y < this->center.x)
    this->lpos.y = this->pos.y -= this->z*this->z;
  else
    this->lpos.y = this->pos.y += this->z*this->z;


  if(this->z > 10 || this->pos.y>HEIGTH || this->pos.x > WIDTH){
    this->z = 0;
    this->lpos.x = this->_pos.x = this->pos.x = rand()%WIDTH;
    this->lpos.y = this->_pos.y = this->pos.y = rand()%HEIGTH;
  }
  else
    this->z += 1;

  this->line[0] = sf::Vertex(this->_pos);
  this->line[1] = sf::Vertex(this->lpos);


  this->circle.setPosition(this->pos);
  this->circle.setRadius(this->r * this->z/10*this->z);
};
