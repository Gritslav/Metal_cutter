#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>
#include<QFile>


#include "mainHeader.h"
#include "place.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Enter_N_clicked()
{
    MainWindow::N1 = (ui->N_set->text()).toInt();
    MainWindow::W_m = (ui->W_main->text()).toDouble();
    MainWindow::H_m = (ui->H_main->text()).toDouble();
	
	if (MainWindow::H_m > MainWindow::W_m)
	{
		double temp = MainWindow::W_m;
		MainWindow::W_m = MainWindow::H_m;
		MainWindow::H_m = temp;
	}

    MainWindow::H_mass = new QLineEdit[MainWindow::N1];
    MainWindow::W_mass = new QLineEdit[MainWindow::N1];

    for (unsigned int i = 0; i< MainWindow::N1; i++)
    {

        ui->mass_h->addWidget(&MainWindow::H_mass[i]);
        ui->mass_w->addWidget(&MainWindow::W_mass[i]);
    }

}
unsigned int MainWindow::Get_N(){
    return N1;
}
double MainWindow::Get_w(){
    return W_m;
}
double MainWindow::Get_h(){
    return H_m;
}

void MainWindow::on_Set_HW_det_clicked()
{
    H_z = new double[MainWindow::N1];
    W_z = new double[MainWindow::N1];

    std::vector<Det> v(MainWindow::N1);
    for (unsigned int i = 0; i < MainWindow::N1; i++)
    {

        MainWindow::H_z[i] = (MainWindow::H_mass[i].text()).toDouble();

        MainWindow::W_z[i] = (MainWindow::W_mass[i].text()).toDouble();

        v[i].Set_h(H_z[i], W_z[i]);

    }

    if ((MainWindow::N1 != 0) && (MainWindow::H_m != 0) && (MainWindow::W_m != 0))
    {
        int max = 0;
        Det temp;
        for (unsigned int i = 0; i < MainWindow::N1; i++)
        {
            max = i;
            for (unsigned int j = i; j < MainWindow::N1; j++)
            {
                if (v[j].S > v[max].S)
                {
                    max = j;
                }
            }
            temp = v[i];
            v[i] = v[max];
            v[max] = temp;
        }
        place p;
        p.find_place(H_m, W_m, v);

        int scale = 1;
        double test_H = H_m;
        double test_W = W_m;
        bool hok = false;
        bool wok = false;
        while ((test_H >= MainWindow::win_H-1)&&(test_W >= MainWindow::win_W-1))
        {
            scale++;
            test_H = H_m/(double)scale;
            test_W = W_m/(double)scale;
            if (test_H < MainWindow::win_H-1){ hok = true;}
            if (test_W < MainWindow::win_W-1){ wok = true;}
        }
        while ((test_W >= MainWindow::win_W-1))
        {
            scale++;
            test_H = H_m/(double)scale;
            test_W = W_m/(double)scale;
            if (test_H < MainWindow::win_H-1){ hok = true;}
            if (test_W < MainWindow::win_W-1){ wok = true;}
        }


        PicDraw col(v,MainWindow::N1, MainWindow::H_m, MainWindow::W_m,
                    MainWindow::win_H, MainWindow::win_W, scale);
        QFile flog("result.txt");
        if (flog.open(QIODevice::WriteOnly))
        {
            flog.write("Масштаб: 1:");
            flog.write(QString::number(scale).toUtf8());
            flog.write("\n");
            flog.write("№   x   y   Ориент.    Выс. Шир.    Созд.\n");
            for(unsigned int i = 0; i < MainWindow::N1; i++)
            {

                flog.write(QString::number(i).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_x()).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_y()).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_ori()).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_h()).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_w()).toUtf8());
                flog.write("    ");
                flog.write(QString::number(v[i].Get_ok()).toUtf8());
                flog.write("\n");
            }
            flog.close();
        }


        QMessageBox::information(this, "Window", "Done!");
        MainWindow::close();

    }







}






