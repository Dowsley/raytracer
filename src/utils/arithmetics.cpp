#include "arithmetics.h"

double Arithmetics::scale(double num, double inMin, double inMax, double outMin, double outMax)
{
    return (double) (num - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}
