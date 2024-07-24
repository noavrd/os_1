#include <stdio.h>
#include "poisson.h"

int main() {
    printf("%.20Lf\n", poisson(2,1));
    printf("%.20Lf\n", poisson(2,10));
    printf("%.20Lf\n", poisson(2,2));
    printf("%.20Lf\n", poisson(3,3));
    printf("%.20Lf\n", poisson(100,3));

    return 0;
}
