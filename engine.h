#ifndef ENGINE_H
#define ENGINE_H

namespace ENGINE {
    enum Figures { figNone, figPoint };

    void Init();
    void ClearChart();
    void GetUserData(Figures _Figure);
    void DrawChart(Figures _Figure);
}

#endif 