#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QWidget>

#include "mainHeader.h"
#include <vector>
#include "place.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double Get_h();
    double Get_w();
    unsigned int Get_N();
    QLineEdit* H_mass;
    QLineEdit* W_mass;
    double* H_z;
    double* W_z;
    place find_place(double h, double w, double h_max, double w_max, std::vector<coord> &v);

    double win_H = 210;
    double win_W = 297;




private slots:

    void on_Enter_N_clicked();

    void on_Set_HW_det_clicked();

private:
    Ui::MainWindow *ui;
    unsigned int N1;
    double H_m;
    double W_m;

};

#endif // MAINWINDOW_H

