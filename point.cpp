#include "point.h"

namespace CHART {
    Point LAST_POINT = { 0, 0 };

    void SetPoint(int _X, int _Y) {
        LAST_POINT.X = _X;
        LAST_POINT.Y = _Y;
    }

    Point GetPoint() {
        return LAST_POINT;
    }
}