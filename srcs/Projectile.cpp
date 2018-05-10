//
// Created by wilmot_g on 23/03/18.
//

#include "helpers/Glut.hpp"

#include <cmath>
#include "includes/Projectile.hpp"
#include "includes/Game.hpp"

#define PROJECTILE_DAMAGES 1

Projectile::Projectile(float t, Vector3f coordinates, Vector3f velocity, Color c) : Displayable(coordinates),
                                                                                    Alive(1),
                                                                                    _color(c),
                                                                                    _startT(t),
                                                                                    _start(coordinates),
                                                                                    _startVelocity(velocity),
                                                                                    _velocity(velocity) {}

Shape Projectile::getCircle(float radius, Vector3f center) {
//  Shape shape;
//  Vector3f coordinates;
//
//  shape._mode = GL_LINE_STRIP;
//  coordinates.x = static_cast<float>(radius * std::cos(359 * M_PI / 180.0f));
//  coordinates.y = static_cast<float>(radius * std::sin(359 * M_PI / 180.0f));
//  coordinates.z = 0;
//  shape._parts.emplace_back(center.x + coordinates.x, center.y + coordinates.y, center.z + coordinates.z);
//  for (int j = 0; j < 360; j++) {
//    coordinates.x = static_cast<float>(radius * std::cos(j * M_PI / 180.0f));
//    coordinates.y = static_cast<float>(radius * std::sin(j * M_PI / 180.0f));
//    shape._parts.emplace_back(center.x + coordinates.x, center.y + coordinates.y, center.z + coordinates.z);
//  }
//  return shape;
  return Shape({});
}

void Projectile::update() {
  if (getCurrentHealth() == 0) {
    return;
  }

  float t = Game::getInstance().getTime() - _startT;
  _coordinates.x = _start.x + _startVelocity.x * t;
  _coordinates.y = _start.y + _startVelocity.y * t + g * t * t / 2.0f;

  //TODO : collisions

  if (_coordinates.y < -0.8 || _coordinates.x < -1 || _coordinates.x > 1) {
    _currentHealth = 0;
  }
}

void Projectile::draw() const {
  //TODO
}