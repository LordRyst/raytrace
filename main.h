#ifndef _MAIN_H_
#define _MAIN_H_

#include "image.h"
#include "triangle.h"
#include "ray.h"
#include "camera.h"
#include "raycast.h"
#define numT 3
#define width 200
#define height 200
#define numR 200*200
image bitmap;
triangle* triangles;
ray* initRays;
float* dists;
rayHit* hits;
vector3 origin;

#endif
