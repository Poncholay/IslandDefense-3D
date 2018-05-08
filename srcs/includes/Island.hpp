//
// Created by wilmot_g on 03/05/18.
//

#pragma once

#include <cmath>
#include <iostream>
#include "../helpers/Displayable.hpp"

class Island : public Displayable {
public:

  typedef struct s_vertex {
    s_vertex(Vector3f &p1, Vector3f &p2, Vector3f n) : p1(p1), p2(p2), n(n) {}

    typedef std::shared_ptr<s_vertex> Ptr;

    Vector3f &p1;
    Vector3f &p2;
    Vector3f n;
  } Vertex;

  typedef std::vector<Vertex::Ptr> Vertices;

  typedef struct s_triangle {
    s_triangle(Vertex::Ptr v1, Vertex::Ptr v2, Vertex::Ptr v3, Vector3f n) : v1(v1),
                                                                             v2(v2),
                                                                             v3(v3),
                                                                             n(n) {}

    Vertex::Ptr v1;
    Vertex::Ptr v2;
    Vertex::Ptr v3;
    Vector3f n;
  } Triangle;

  typedef std::vector<std::vector<Triangle>> Triangles;

  typedef std::vector<std::vector<Vector3f>> PointMap;

  Island();

  void draw() const override;

private:

  Vector3f computeNormal(const Vector3f &p1, const Vector3f &p2, const Vector3f &p3);

  float islandPerlin(float x, float y) const;

  float _zmax, _xmax, _tess;
  Triangles _triangles;
  PointMap _points;
  Vertices _vertices;
};

inline std::ostream &operator<<(std::ostream &os, const Island::Vertex &v) {
  os << v.p1 << "\t" << v.p2 << "\t" << v.n;
  return os;
}