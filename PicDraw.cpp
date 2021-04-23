#include "PicDraw.h"

double PicDraw::mmPix(double a)
{
    return a*3.793627;
}
PicDraw::PicDraw(std::vector<Det> v, int N, double h0, double w0, double win_H, double win_W, int scale)
{



    QPixmap pic((int)(PicDraw::mmPix(win_W)+1),(int)(PicDraw::mmPix(win_H)+1));
    QPainter painter(&pic);
    painter.setPen(QColor("#000000"));
    painter.setBrush(QBrush("#ffffff"));
    painter.drawRect(0,0,(int)(PicDraw::mmPix(win_W)),(int)(PicDraw::mmPix(win_H)));

    painter.setPen(QColor("#000000"));

    painter.setBrush(QBrush("#ffffff"));
    painter.drawRect(0,0,(int)(PicDraw::mmPix(w0)/(double)scale),(int)(PicDraw::mmPix(h0)/(double)scale));
    for (int i = 0; i<N; i++)
    {
        if (v[i].Get_ok())
        {
            if (!v[i].Get_ori())
            {
                painter.drawRect((int)(PicDraw::mmPix(v[i].Get_x())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_y())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_w())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_h())/(double)scale));

            } else {
                painter.drawRect((int)(PicDraw::mmPix(v[i].Get_x())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_y())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_h())/(double)scale),
                                 (int)(PicDraw::mmPix(v[i].Get_w())/(double)scale));
            }
        }
    }

    pic.save("img.jpg");
}
