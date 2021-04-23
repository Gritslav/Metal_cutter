#include "Det.h"

Det::Det()
{
}

void Det::Set_xy(double x, double y)
{
    Det::x = x;
    Det::y = y;
    if (!Det::ori)
    {
        Det::x1 = Det::x + Det::w;
        Det::y1 = Det::y + Det::h;
    }
    else {
        Det::x1 = Det::x + Det::h;
        Det::y1 = Det::y + Det::w;
    }

}
void Det::Set_h(double h, double w)
{
    Det::h = h;
    Det::w = w;
    Det::S = h*w;
}
void Det::Set_ori(bool ori)
{
    Det::ori = ori;
}
void Det::Set_ok(bool ok)
{
    Det::ok = ok;
}

double Det::Get_h()
{
    return Det::h;
}
double Det::Get_w()
{
    return Det::w;
}
double Det::Get_x()
{
    return Det::x;
}
double Det::Get_y()
{
    return Det::y;
}
bool Det::Get_ori()
{
    return Det::ori;
}
bool Det::Get_ok()
{
    return Det::ok;
}



