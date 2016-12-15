#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "ray.h"
#include "vector.h"

typedef struct triangle {
  vector3 a;
  vector3 b;
  vector3 c;
  vector2 at;
  vector2 bt;
  vector2 ct;
  int texture;
}triangle;

void triangleSplit(vector* triangles, char dir, float center, vector* less, vector* more);
vector* triangleOct(vector* triangles, vector3* center);
float triangleHit(ray* rayI, triangle* triI);
#endif
