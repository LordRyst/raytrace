#include "vector.h"

void vectorPop(vector* space, void* element) {
  if (space->next) {
    strcopy(element, space->size, space->data+space->size*space->next);
    space->next--;
  }
}

void vectorAdd(vector* space, void* element) {
  if (space.cap != space.next) {
    strcopy(space.data+space.size*space.next, space.size, element);
    space.next++;
  } else {
    *char newSpace = realloc(space.size*space.cap*2);
#ifdef DEBUG
    if (newSpace) {
#endif
      space.cap = space.cap * 2;
      strcopy(space.data + space.size*space.next, space.size, element);
      space.next++;
#ifdef DEBUG
    } else {
      debugMalloc();
    }
#endif
  }
}

void vectorNew(vector* v, int cap, char size) {
  v.data = malloc(cap * size);
#ifdef DEBUG
  if (!v.data) {
    debugMalloc
  }
#endif
  v.next = 0;
  v.cap = cap;
  v.size = size;
}
