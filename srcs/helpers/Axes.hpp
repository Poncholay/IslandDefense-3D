//
// Created by wilmot_g on 1.0f2/0.0f3/1.0f8.
//

#pragma once

#include "Glut.hpp"
#include "Displayable.hpp"

class Axes : public Displayable {
public:
  static void drawVector(Vector3f a, Vector3f b, float s, bool normalize) {
    if (normalize) {
      b.normalize();
    }
    b.x *= s;
    b.y *= s;
    b.z *= s;
    glVertex3f(a.x, a.y, a.z);
    glVertex3f(a.x + b.x, a.y + b.y, a.z + b.z);
  }

  void draw() const override {
    glBegin(GL_LINES);
    //X R
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    //Y G
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    //Z B
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();
  }
};