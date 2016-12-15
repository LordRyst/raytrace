#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "debug.h"

typedef struct vector {
  char* data;
  int cap;
  char size;
  int next;
}vector;

void vectorPop(vector* v, void* element);
void vectorNew(vector* v, int cap, char size);
void vectorAdd(vector* v, void* element);

#endif
