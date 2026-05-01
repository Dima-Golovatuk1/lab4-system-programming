#include "axles.h"

namespace CHART {
    unsigned short CHART_WIDTH = 0;
    unsigned short CHART_HEIGHT = 0;

    void SetChartSize(unsigned short _W, unsigned short _H) {
        CHART_WIDTH = _W;
        CHART_HEIGHT = _H;
    }
}