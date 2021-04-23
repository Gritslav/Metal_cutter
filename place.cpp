#include "place.h"
#include <QMessageBox>


void place::find_place(double h_max, double w_max, std::vector<Det> &v)
{
    std::vector<coord> v1;
    coord buff;
    coord buff1;
    buff.Set_co(0, 0);
    v1.push_back(buff);
    for (unsigned int i = 0; i < v.size(); i++)
    {

        unsigned int count = 0;
        int item = 0;
        double h_new = 0;
        double w_new = 0;

        bool ori = false;
        for (unsigned int j = 0; j < v1.size(); j++)
        {
            if (h_new < v1[j].Get_y())
            {
                h_new = v1[j].Get_y();
            }
            if (w_new < v1[j].Get_x())
            {
                w_new = v1[j].Get_x();
            }
        }
        for (unsigned int j = 0; j < v1.size(); j++)
        {
            if (((v[i].Get_h() + v1[j].Get_y() > h_max) || (v[i].Get_w() + v1[j].Get_x() > w_max))
                    && ((v[i].Get_w() + v1[j].Get_y() > h_max) || (v[i].Get_h() + v1[j].Get_x() > w_max)))
            {
                count++;
                if (count == v1.size())
                {
                    place::ok = false;
                    break;
                }
                continue;
            }
            if (v[i].Get_h()>v[i].Get_w())
            {
                if (v[i].Get_h() + v1[j].Get_y() < h_max)
                {
                    item = j;
                    ori = false;
                    break;
                }

            }
            else {
                if (v[i].Get_w() + v1[j].Get_y() < h_max)
                {
                    item = j;
                    ori = true;
                    break;
                }

            }
        }
        place::item = item;
        place::ok = true;
        place::ori = ori;




        v[i].Set_xy(v1[place::item].Get_x(), v1[place::item].Get_y());
        v[i].Set_ori(place::ori);
        v[i].Set_ok(place::ok);
        buff.Set_co(v1[place::item].Get_x(),v1[place::item].Get_y());

        if (place::ok)
        {

            v1.erase(v1.begin() + place::item);
            if (!place::ori)
            {

                bool cre = true;
                for(unsigned int k = 0; k<v.size(); k++)
                {

                    if ((v[k].x1 == buff.Get_x() + v[i].Get_w())&&(buff.Get_y() == v[k].y1))
                    {

                        cre = false;
                        break;
                    }
                }
                if (cre)
                {
					buff1.Set_co(buff.Get_x() + v[i].Get_w(), buff.Get_y());
                    v1.push_back(buff1);
                   //v1[place::item].Set_co(buff.Get_x() + v[i].Get_w(), buff.Get_y());
                }


                cre = true;
                for(unsigned int k = 0; k<v.size(); k++)
                {
                    if ((v[k].x1 == buff.Get_x())&&(buff.Get_y() + v[i].Get_h() == v[k].y1))
                    {

                        cre = false;
                        break;
                    }
                }
                if (cre)
                {
                    buff1.Set_co(buff.Get_x(), buff.Get_y() + v[i].Get_h());
                    v1.push_back(buff1);
                }


            }
            else{
                bool cre = true;
                for(unsigned int k = 0; k<v.size(); k++)
                {
                    if ((v[k].y1 == buff.Get_x() + v[i].Get_h())&&(buff.Get_y() == v[k].x1))
                    {

                        cre = false;
                        break;
                    }
                }
                if (cre)
                {
                    buff1.Set_co(buff.Get_x() + v[i].Get_h(), buff.Get_y());
                    v1.push_back(buff1);
                    //v1[place::item].Set_co(buff.Get_x() + v[i].Get_h(), buff.Get_y());
                }

                cre = true;
                for(unsigned int k = 0; k<v.size(); k++)
                {
                    if ((v[k].y1 == buff.Get_x())&&(buff.Get_y() + v[i].Get_w() == v[k].x1))
                    {

                        cre = false;
                        break;
                    }
                }
                if (cre)
                {
                    buff1.Set_co(buff.Get_x(), buff.Get_y() + v[i].Get_w());
                    v1.push_back(buff1);
                }


            }
        }

        int max = 0;
        coord temp;
        QString s;
        for (unsigned int l = 0; l < v1.size(); l++)
        {
            max = l;
            for (unsigned int k = l; k < v1.size(); k++)
            {
                if (v1[k].Get_y() > v1[max].Get_y())
                {
                    max = k;
                } else if(v1[k].Get_x()< v1[max].Get_x()){
                    max = k;
                }
            }
            temp.Set_co(v1[l].Get_x(),v1[l].Get_y());
            v1[l].Set_co(v1[max].Get_x(), v1[max].Get_y());
            v1[max].Set_co(temp.Get_x(), temp.Get_y());

        }




    }










};

