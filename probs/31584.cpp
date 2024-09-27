#include "bulb.h"

int n;

void Init(int N) {
    n = N;
}

int MakeTurn(int M) {
    return n - M + 1;
}
