#ifndef POINT_H
#define POINT_H

namespace CHART {
    struct Point { int X; int Y; };

    void SetPoint(int _X, int _Y);
    Point GetPoint();
}

#endif