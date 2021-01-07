#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

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


void MainWindow::on_slider_angle_valueChanged(int value)
{
    ui->canvas_widget->angle = value;
}

void MainWindow::on_horizontalSlider_valueChanged(int value){
    float val = (float)value/10;
    ui->canvas_widget->dis = val;
}

void MainWindow::on_slider_i_valueChanged(int value)
{
    float val = (float)value / 100;
    ui->canvas_widget->vect.setX(val);
    //ui->canvas_widget->vect.normalize();

    updateUI();

}

void MainWindow::on_slider_j_valueChanged(int value)
{
    float val = (float)value / 100;
    ui->canvas_widget->vect.setY(val);
    //ui->canvas_widget->vect.normalize();

    updateUI();

}


void MainWindow::on_slider_k_valueChanged(int value)
{
    float val = (float)value / 100;
    ui->canvas_widget->vect.setZ(val);
    //ui->canvas_widget->vect.normalize();

    updateUI();

}

void MainWindow::updateUI()
{
    QString bob = QString("Vect(%1, %2, %3)")
            .arg(ui->canvas_widget->vect.x())
            .arg(ui->canvas_widget->vect.y())
            .arg(ui->canvas_widget->vect.z());

    QString bob2 = QString("%1").arg(ui->canvas_widget->vect.length());

    ui->label_vector->setText(bob);

}

void MainWindow::on_sbox_time_valueChanged(double arg1)
{
    ui->canvas_widget->delta_t = arg1;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("This program was developed by Max Ulfves in winter 2021");
    msgBox.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("1. Use the sliders to change the vector and angle of rotation. \n2. W dis determines the distance of the stereographic 4-3D projection. \n3. Change time to increase the delta.  ");
    msgBox.exec();
}
