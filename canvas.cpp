#include "canvas.h"

#include <QQuaternion>
#include <QMatrix4x4>
#include <QtMath>
#include <QDebug>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{


}


float t = 0;


bool comparer (QVector4D i,QVector4D j) { return (i.z() < j.z()); }

void Canvas::paintEvent(QPaintEvent *)
{
    //Setup QPainter
    QPainter painter(this);

    QTransform bob;
    bob.translate(250, 250);
    painter.setTransform(bob);


    painter.setPen(QPen(Qt::blue, 2));


    std::vector<QVector4D> projected;

    //LOOP THROGUH EDGES
    for(auto edge : tesseract.edges) {
        painter.setPen(QPen(Qt::blue, 2));

        auto p1 = tesseract.vertexes[edge.first];
        auto p2 = tesseract.vertexes[edge.second];

        QMatrix4x4 pro1, pro2, mat4d;

        //ROTATE IN 4D:

        float period = (float)t / 2000; //2000 is arbitrary. Fix?
        mat4d = mat4d * qCos(period);
        //mat4d(2, 2) = qCos(period);
        //mat4d(3, 3) = qCos(period);

        mat4d(0, 1) = -qSin(period);
        mat4d(1, 0) = qSin(period);
        mat4d(2, 3) = -qSin(period);
        mat4d(3, 2) = qSin(period);


        p1 = p1 * mat4d;
        p2 = p2 * mat4d;

        //PROJECT ONTO 3D:
        pro1(3, 3) = 0;
        pro2(3, 3) = 0;

        pro1 /= (dis - p1.w());
        pro2 /= (dis - p2.w());

        p1 = p1 * pro1;
        p2 = p2 * pro2;

        //ROTATE 3D PROJECTION
        QQuaternion quat = QQuaternion::fromAxisAndAngle(vect, angle);

        p1 = quat.rotatedVector(p1.toVector3D());
        p2 = quat.rotatedVector(p2.toVector3D());


        //PLOT EACH POINT AND ADD TO VECTOR

        auto direction = p2 - p1;
        auto start = p1;

        for(int i = 0; i < 150; i++){
            projected.push_back(start);
            start += direction / 150;
        }


    }

    //Sort the points by z-value.
    std::sort(projected.begin(), projected.end(), comparer);


    for(auto point: projected){

        //Chose a factor for representing the depth.
        float factor = ( ( 1.0 + point.z())/ 2.0); //Completely arbitrary range. TODO: better estimate the depth.
        factor = std::min(1.0f, std::max(0.0f, factor)); // Clamp to [0, 1]

        //Use same factor to determine size and gradient of each point.
        int gradient = std::min( std::max(0, (int)(factor * 255)), 255);
        int thickness = std::min(std::max(2, 1 + (int)(factor * 10  )), 11  );

        QColor depth = QColor(0, gradient, 0);
        painter.setPen(QPen(depth, thickness));

        //PROJECT 3D TO 2D
        QMatrix4x4 scale;
        scale.scale(100, 100, 100);
        auto p1 = point * scale;

        //DRAW PROJECTION.
        painter.drawPoint(p1.x(), p1.y());
    }


    t += delta_t;
    qDebug() << dis;
    update();



}
