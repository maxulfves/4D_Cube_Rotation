#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_slider_angle_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_slider_i_valueChanged(int value);

    void on_slider_j_valueChanged(int value);

    void on_slider_k_valueChanged(int value);

    void on_sbox_time_valueChanged(double arg1);

    void on_actionAbout_triggered();

    void on_actionHelp_triggered();

private:
    Ui::MainWindow *ui;
    void updateUI();
};
#endif // MAINWINDOW_H
