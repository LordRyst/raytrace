#include <pthread.h>
#include <stdlib.h>
#include "image.h"
#include "camera.h"
#include "ray.h"
#include "raycast.h"
#include "sphere.h"
#include "bmp.h"

image bitmap;
sphere* spheres;
int numS = 1;
ray* initRays;

int main() {
  bitmap.width = 300;
  bitmap.height = 200;
  bitmap.filename = "image.bmp";
  bitmap.rgb = malloc(3*bitmap.width*bitmap.height);
  int numr = bitmap.width * bitmap.height;
  spheres = malloc(sizeof(sphere) * numS);
  spheres[0].loc = vecZero();
  spheres[0].rad = 75;
  vector3 origin = vecZero();
  origin.z = -100;
  camera cam;
  cameraCreate(&cam, origin, &bitmap);
  initRays = malloc(sizeof(ray) * numr);
  cameraRays(&cam, initRays);
  float* dists = malloc(sizeof(float)*numr*numS);
  raycast(initRays, numr, spheres, numS, dists);
  rayHit* hits = malloc(sizeof(rayHit) * numr);
  findNearest(dists, numr, numS, hits);
  colorFlat(hits, numr, bitmap);
  return write_bmp(bitmap);
}
