#include "tesseract.h"

Tesseract::Tesseract()
{

    //Inner 3D Cube.

    //Outer lower 2D rectangle
    this->vertexes[0] = QVector4D(-1, -1, -1, -1);
    this->vertexes[1] = QVector4D(1, -1, -1,  -1);
    this->vertexes[2] = QVector4D(-1, -1, 1,  -1);
    this->vertexes[3] = QVector4D(1, -1, 1,   -1);

    this->edges[0] = std::pair<float, float>(0, 1);
    this->edges[1] = std::pair<float, float>(1, 3);
    this->edges[2] = std::pair<float, float>(3, 2);
    this->edges[3] = std::pair<float, float>(2, 0);

    //Outer upper rectangle
    this->vertexes[4] = QVector4D(-1, 1, -1, -1);
    this->vertexes[5] = QVector4D(1, 1, -1,  -1);
    this->vertexes[6] = QVector4D(-1, 1, 1,  -1);
    this->vertexes[7] = QVector4D(1, 1, 1,   -1);

    this->edges[4] = std::pair<float, float>(4, 5);
    this->edges[5] = std::pair<float, float>(5, 7);
    this->edges[6] = std::pair<float, float>(7, 6);
    this->edges[7] = std::pair<float, float>(6, 4);

    //Joining edges
    this->edges[8] =  std::pair<float, float>(0, 4);
    this->edges[9] =  std::pair<float, float>(1, 5);
    this->edges[10] = std::pair<float, float>(2, 6);
    this->edges[11] = std::pair<float, float>(3, 7);


    //--------------------------------------------------
    //Inner 3D Cube

    //Outer lower rectangle
    this->vertexes[8] = QVector4D(-1, -1, -1, 1);
    this->vertexes[9] = QVector4D(1, -1, -1,  1);
    this->vertexes[10] = QVector4D(-1, -1, 1,  1);
    this->vertexes[11] = QVector4D(1, -1, 1,   1);

    this->edges[12] = std::pair<float, float>(8, 9);
    this->edges[13] = std::pair<float, float>(9, 11);
    this->edges[14] = std::pair<float, float>(11, 10);
    this->edges[15] = std::pair<float, float>(10, 8);

    //Outer upper rectangle
    this->vertexes[12] = QVector4D(-1, 1, -1, 1);
    this->vertexes[13] = QVector4D(1, 1, -1,  1);
    this->vertexes[14] = QVector4D(-1, 1, 1,  1);
    this->vertexes[15] = QVector4D(1, 1, 1,   1);

    this->edges[16] = std::pair<float, float>(12, 13);
    this->edges[17] = std::pair<float, float>(13, 15);
    this->edges[18] = std::pair<float, float>(15, 14);
    this->edges[19] = std::pair<float, float>(14, 12);

    //Joining edges
    this->edges[20] =  std::pair<float, float>(8, 12);
    this->edges[21] =  std::pair<float, float>(9, 13);
    this->edges[22] = std::pair<float, float>(10, 14);
    this->edges[23] = std::pair<float, float>(11, 15);


    //----------------
    //Joining edges of both 3D cubes
    this->edges[24] =  std::pair<float, float>(0, 8);
    this->edges[25] =  std::pair<float, float>(1, 9);
    this->edges[26] = std::pair<float, float>(2, 10);
    this->edges[27] = std::pair<float, float>(3, 11);

    this->edges[28] =  std::pair<float, float>(4, 12);
    this->edges[29] =  std::pair<float, float>(5, 13);
    this->edges[30] = std::pair<float, float>(6, 14);
    this->edges[31] = std::pair<float, float>(7, 15);


}
