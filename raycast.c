#include "raycast.h"
#include "math.h"
#include "main.h"
#include "triangle.h"

float sphereHit(ray* r, sphere* s) { //returns distSquared
  vector3 p = vecSub(r->origin,s->loc);
  float rS = s->rad * s->rad;
  float pD = vecDot(p, r->direction);
  if (pD < 0 || vecDot(p,p) < rS) {
    return INFINITY;
  }
  vector3 a = vecSub(p, vecScale(pD, r->direction));
  float aS = vecDot(a,a);
  if (aS > rS)
    return INFINITY;
  float h = rS - aS;
  return h;
}

void raycast() {
  for (int i = 0; i < numR; i++) {
    for (int obj = 0; obj < numT; obj++) {
      dists[i * numT + obj] = triangleHit(&initRays[i], &triangles[obj]);
    }
  }
}

void findNearest() {
  for (int i = 0; i < numR; i++) {
    int smallest = 0;
    float distance = dists[i * numT];
    for (int obj = 1; obj < numT; obj++) {
      if (dists[i * numT + obj] < distance) {
	distance = dists[i * numT + obj];
	smallest = obj;
      }
    }
    hits[i].objIndex = smallest;
    hits[i].distSqr = distance;
  }
}
