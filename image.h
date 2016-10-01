#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "raycast.h"

typedef struct color{
  char r;
  char g;
  char b;
}color;

typedef struct image {
  int width;
  int height;
  color* rgb;
  char* filename;
}image;

void colorFlat();

#endif
