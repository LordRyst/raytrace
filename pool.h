#ifndef _POOL_H_
#define _POOL_H_

typedef struct pool {
  char* data = 0;
  int cap = 0;
  char size = 0;
  int next = 0;
  pool* free = 0;
}pool;

#endif
