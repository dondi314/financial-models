#include <cstdlib>
#include <cmath>

double uniformRandom(void)
{
    return (double)(rand() + 1.0) / (double)(RAND_MAX + 1.0);
}

double gaussianRandom(double mu, double sigma)
{
    static const double two_pi = 2.0 * 3.14159265358979323846;

    double u1 = uniformRandom();
    double u2 = uniformRandom();
    
    double z0;
    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);   
    return z0 * sigma + mu;
}
