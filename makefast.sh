#!/bin/bash

ccache gcc -O3 -march=native -Wall -Werror -Wshadow -o tracer main.c bmp.c ray.c camera.c raycast.c image.c triangle.c -lpthread -DNDEBUG

if [ $? = 0 ]; then
    cppcheck .
fi

if [ $? = 0 ]; then
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./server.out
fi

if [ $? = 0 ]; then
    git status
fi
