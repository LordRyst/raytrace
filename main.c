#include <pthread.h>
#include <stdlib.h>
#include "image.h"
#include "camera.h"
#include "ray.h"
#include "raycast.h"
#include "triangle.h"
#include "bmp.h"
#include "main.h"

int main() {
  bitmap.filename = "image.bmp";
  bitmap.rgb = malloc(3 * numR);
  triangles = malloc(sizeof(triangle) * numT);
  triangles[0].a = vecZero();
  triangles[0].b = vecNew(50, 100, 0);
  triangles[0].c = vecNew(-50, 100, 0);
  triangles[1].a = vecZero();
  triangles[1].b = vecNew(-100, 0, 0);
  triangles[1].c = vecNew(-50, -100, 0);
  triangles[2].a = vecZero();
  triangles[2].b = vecNew(50, -100, 0);
  triangles[2].c = vecNew(100, 0, 0);
  origin = vecZero();
  origin.z = -100;
  initRays = malloc(sizeof(ray) * numR);
  cameraRays();
  dists = malloc(sizeof(float)*numR*numT);
  raycast();
  hits = malloc(sizeof(rayHit) * numR);
  findNearest();
  colorFlat();
  return write_bmp(bitmap);
}
