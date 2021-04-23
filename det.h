#ifndef DET_H
#define DET_H


class Det
{
private:
    double h;
    double w;
    double x;
    double y;

    bool ok;

    bool ori; //ориентация, 0 - не поворачиваем, 1 - поворачиваем
public:
    double S;
    Det();
    void Set_xy(double a, double b);
    void Set_h(double a, double b);
    void Set_ori(bool a);
    void Set_ok(bool a);
    void S_print();
    double Get_h();
    double Get_w();
    double Get_x();
    double Get_y();
    bool Get_ori();
    bool Get_ok();
    double x1;
    double y1;
};

#endif // DET_H
