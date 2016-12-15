#ifndef _RAYCAST_H_
#define _RAYCAST_H_

#include "sphere.h"
#include "ray.h"

typedef struct rayHit{
  int objIndex;
  float distSqr;
}rayHit;

void raycast();
//float sphereHit(ray* r, sphere* s);
void findNearest();

#endif
