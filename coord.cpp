#include "coord.h"

void coord::Set_co(double x, double y)
{
    coord::x = x;
    coord::y = y;
}
double coord::Get_x()
{
    return coord::x;
}
double coord::Get_y()
{
    return coord::y;
}
