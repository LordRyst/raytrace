#include "raycast.h"
#include "math.h"

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

void raycast(ray* rays, int numr, sphere* targets, int numt, float* dists) {
  for (int i = 0; i < numr; i++) {
    for (int obj = 0; obj < numt; obj++) {
      dists[i * numt + obj] = sphereHit(&rays[i], &targets[obj]);
    }
  }
}

void findNearest(float* dists,int numr, int numt, rayHit* hits) {
  for (int i = 0; i < numr; i++) {
    int smallest = 0;
    float distance = dists[i * numt];
    for (int obj = 1; obj < numt; obj++) {
      if (dists[i * numt + obj] < distance) {
	distance = dists[i * numt + obj];
	smallest = obj;
      }
    }
    hits[i].objIndex = smallest;
    hits[i].distSqr = distance;
  }
}
