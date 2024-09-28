#pragma once

#include <stdlib.h>

#define MALLOC(p, s)\
if ((p = malloc(s)) == NULL) {\
    fprintf(stderr, "Insufficient memory");\
    exit(EXIT_FAILURE);\
}

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1)
