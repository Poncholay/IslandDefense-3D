//
//  Camera.hpp 
//  IslandDefense3D
//
//  Created by Mathieu Corti on 5/1/18.
//

#pragma once

#include <cmath>
#include "../helpers/Glut.hpp"
#include "../helpers/Movable.hpp"
#include "../helpers/Displayable.hpp"

class Camera : public Movable {
private:
  float _rotationSpeed;
  float _translationSpeed;
  float _xRot;
  float _yRot;
  float _time;
  int _lastMouseX;
  int _lastMouseY;

public:

  Camera();

  bool update() override;

  void draw() const override;

  void move(Direction direction) override;

  void rotation(int x, int y);
};
