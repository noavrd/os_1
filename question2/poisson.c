#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

int main(int argc, char *argv[]) {
    // check if the program got more or less than 2 arguments
    if (argc != 3) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    // get the 2 arguments
    long double lambda = atof(argv[1]);
    int k = atoi(argv[2]);

    // calculate power & factorial
    long double power = powl(lambda, k);
    long double factorial;

    if (k < 0) {
        factorial = 0;
    } else if (k == 0) {
        factorial = 1;
    } else {
        factorial = tgammal(k + 1);
    }

    // calculate the poisson probability
    long double poisson = expf(-lambda) * power / factorial;

    printf("P(%d) = %.20Lf\n", k, poisson);

    return 0;
}
