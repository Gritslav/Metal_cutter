#ifndef PICDRAW_H
#define PICDRAW_H


#include <QPainter>
#include <qmath.h>
#include <QWidget>



#include "det.h"

#include <vector>

class PicDraw /*: public QPainter */{
 // static std::vector<Det> v1;
  public:
    PicDraw(/*QPainter *parent = 0,*/ std::vector<Det> v, int N, double h0, double w0, double win_H, double win_W, int scale);
    double mmPix(double a);
};

#endif // PICDRAW_H
