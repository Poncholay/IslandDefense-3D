//
//  Game.hpp 
//  IslandDefense
//
//  Created by Mathieu Corti on 3/12/18.
//

#pragma once

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <functional>
#include <map>
#include <memory>

#include "../helpers/Glut.hpp"
#include "../helpers/Displayable.hpp"
#include "../helpers/Movable.hpp"
#include "../includes/Entities.hpp"
#include "Config.hpp"
#include "Waves.hpp"
#include "Boat.hpp"

class Game {

// TYPEDEFS
private:
  typedef std::map<unsigned char, std::function<void(int x, int y)> > KeyboardMap;
  typedef std::map<GameEntity, Displayable::Ptr> EntityList;

public:
  static Game &getInstance() {
    static Game instance;
    return instance;
  }

  int start(int argc, char **argv);

  void draw();

  void keyboard(unsigned char key, int x, int y) const;

  void mouse(int x, int y);

  std::shared_ptr<Entities<Boat> > generateBoats();

  void mouseClick(int button, int state);

  const float getTime() const;

  const float &getDeltaTime() const;

  const float &getFrameRate() const;

  const bool getShowTangeant() const;

  const bool getShowNormal() const;

  const bool getShowLight() const;

  const EntityList &getEntities() const;

  Game(const Game &) = delete;

  Game &operator=(const Game &) = delete;

private:
  KeyboardMap _keyboardMap;
  EntityList _entities;
  float _time, _lastTime, _deltaTime = 0.0;
  float _lastFrameRateT, _frameRateInterval, _frameRate, _frames;
  bool _showWireframe = false;
  bool _showTangeant = false;
  bool _showNormal = false;
  bool _showLight = true;

  void initDrawCallback() const;

  void initReshapeCallback() const;

  void initKeyboardCallback() const;

  void initMouseCallback() const;

  void initKeyboardMap();

  void initBlend();

  void initEntities();

  void update();

  void updateTime();

  static void idleFunc();

  // Helpers

  void move(const GameEntity &entityName, Direction direction, int coef = 1) {
    std::dynamic_pointer_cast<Movable>(_entities[entityName])->move(direction, coef);
  }

  void toggleAnimation(const GameEntity &entityName) {
    std::dynamic_pointer_cast<Waves>(_entities[entityName])->toggleAnimation();
  }

  void doubleVertices(const GameEntity &entityName) {
    std::dynamic_pointer_cast<Waves>(_entities[entityName])->doubleVertices();
  }

  void halveSegments(const GameEntity &entityName) {
    std::dynamic_pointer_cast<Waves>(_entities[entityName])->halveSegments();
  }

  template<class T>
  void fire(const GameEntity &entityName) {
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->blast(1);
  }

  template<class T>
  void defend(const GameEntity &entityName) {
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->defend();
  }

  template<class T>
  void setCannonRotation(const GameEntity &entityName, float y, float z) {
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->setAngle({0.0f, -y + 90, 0.0f});
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->setRotation(z);
  }

  template<class T>
  void changeCannonPower(const GameEntity &entityName, float delta) {
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->speed(delta);
  }

  template<class T>
  void changeCannonDirection(const GameEntity &entityName, float delta) {
    std::dynamic_pointer_cast<T>(_entities[entityName])->getCannon()->rotation(delta);
  }

  // Singleton
  Game() : _frameRateInterval(0), _time(0), _lastTime(0), _lastFrameRateT(0), _frameRate(0), _frames(0) {}

  ~Game() = default;

  bool gameOver() const;
};

// Extern C
extern "C" {
static void drawCallback();
static void reshapeCallback(int w, int h);
static void keyboardCallback(unsigned char key, int x, int y);
static void mouseCallback(int x, int y);
static void mouseClickCallback(int button, int state, int x, int y);
}