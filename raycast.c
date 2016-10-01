#include "raycast.h"
#include "math.h"
#include "main.h"

float triangleHit(int rayI, int triI) {
  vector3 origin = initRays[rayI].origin;
  vector3 direction = initRays[rayI].direction;
  vector3 a = triangles[triI].a;
  vector3 b = triangles[triI].b;
  vector3 c = triangles[triI].c;
  vector3 e1 = vecSub(b, a);
  vector3 e2 = vecSub(c, a);

  vector3 h = vecCross(direction, e2);
  float g = vecDot(e1, h);
  if (g == 0) {
    return INFINITY;
  }
  float f = 1 / g;
  vector3 s = vecSub(origin, a);
  float u = f * vecDot(s, h);
  if (u < 0 || u > 1.0) {
    return INFINITY;
  }
  vector3 q = vecCross(s, e1);
  float v = f * vecDot(direction, q);
  if (v < 0 || u + v > 1.0) {
    return INFINITY;
  }
  return f * vecDot(e2, q);
}

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
      dists[i * numT + obj] = triangleHit(i, obj);
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
