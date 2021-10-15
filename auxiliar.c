#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "auxiliar.h"

double distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

float max(float n1, float n2)
{
    if(n1 > n2)
    {
        return n1;
    }
    return n2;
}

float min(float n1, float n2)
{
    if(n1 > n2)
    {
        return n2;
    }
    return n1;
}