#ifndef _RAYCAST_H_
#define _RAYCAST_H_

#include "sphere.h"
#include "ray.h"

typedef struct rayHit{
  int objIndex;
  float distSqr;
}rayHit;

void raycast(ray* rays, int numr, sphere* targets, int numt, float* dists);
float sphereHit(ray* r, sphere* s);
void findNearest(float* dists, int numr, int numt, rayHit* hits);

#endif
