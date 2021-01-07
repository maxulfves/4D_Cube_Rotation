#ifndef TESSERACT_H
#define TESSERACT_H

#include <QVector4D>

class Tesseract
{
public:
    Tesseract();
    QVector4D vertexes[16];
    std::pair<int, int> edges[32];

private:


};

#endif // TESSERACT_H
