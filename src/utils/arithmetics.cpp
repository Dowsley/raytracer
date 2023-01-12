#include "arithmetics.h"

double Arithmetics::scale(double num,double in_min, double in_max,double out_min,double out_max)
{
    return (double) (num - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
