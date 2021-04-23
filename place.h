#ifndef PLACE_H
#define PLACE_H

#include <vector>

#include <det.h>
#include "coord.h"
#include<QString>
class place{
public:
    bool ori;
    int item;
    bool ok;


    void find_place(double h_max, double w_max, std::vector<Det> &v);
};


#endif // PLACE_H
