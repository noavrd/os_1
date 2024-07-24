#include <math.h>

long double poisson(long double lambda, int k) {
    if (k < 0) {
        return 0;
    }
    
    return expl(-lambda) * powl(lambda, k) / tgammal(k + 1);
}
