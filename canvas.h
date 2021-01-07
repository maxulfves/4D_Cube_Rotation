#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QtMath>
#include <QVector4D>
#include <QVector3D>

#include "tesseract.h"

#include <QMatrix>


/*
 * For the purposes of this simple simulation, I decided that using public member variables was the easiest way to get the point accross.
 * If this project were to be expaned further, it'd be wise to pay better attention to encapsulation.
 */

class Canvas : public QWidget
{
    Q_OBJECT
public:

    explicit Canvas(QWidget *parent = nullptr);

    float dis = 2.0;
    float angle = 0.0;

    QVector3D vect = QVector3D(0, 0, 0);

    float delta_t = 1.0;

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Tesseract tesseract;


};

#endif // CANVAS_H
