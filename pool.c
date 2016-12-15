#include "pool.h"

bool poolAdd(pool* space, void* element) {
  if (!poolEmpty(*pool.free)) {
    int index = (int)poolPop(*pool.free);
    charCopy(*pool.data[*pool.size * index], *pool.size, *element);
  } else if (!poolFull(pool)) {
    charCopy(*pool.data[*pool.size * *pool.next], *pool.size, *element);
    *pool.next++;
  } else {
    return false;
  }
  return true;
}
