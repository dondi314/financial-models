#include <iostream>
#include "Random.h"
#include <cmath>

double CallOptionPricer(double Expiracy, 
			double Strike, 
			double Spot, 
			double Volatility, 
			double r, 
			int NumberOfPaths)
{
    double variance = Volatility * Volatility * Expiracy;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    double movedSpot = Spot * exp(r * Expiracy + itoCorrection);	
    double thisSpot;
    double runningSum = 0;

    for (int i=0; i < NumberOfPaths; i++)
    {
    double thisGaussian = gaussianRandom(0, 1);
    thisSpot = movedSpot * exp(rootVariance * thisGaussian);
    double thisPayoff = thisSpot - Strike;
    thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
    runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiracy);
    return mean;
}

int main(void)
{
    double Expiracy;
    double Strike;
    double Spot;
    double Volatility;
    double r;
    int NumberOfPaths;
    double result;

    std::cout << "\nEnter Expiracy\n";
    std::cin >> Expiracy;

    std::cout << "\nEnter Strike\n";
    std::cin >> Strike;

    std::cout << "\nEnter Spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter Volatility\n";
    std::cin >> Volatility;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nEnter NumberOfPaths\n";
    std::cin >> NumberOfPaths;

    result = CallOptionPricer(Expiracy, 
			      Strike,
			      Spot,
			      Volatility,
                              r, 
                              NumberOfPaths);
    
    std::cout << "the price is " << result << "\n";

    return 0;
}			
