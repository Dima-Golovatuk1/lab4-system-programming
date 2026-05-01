#include "render.h"
#include "../models/axles.h"
#include "../models/point.h"
#include <iostream>
#include <windows.h>

namespace CHART {
    extern unsigned short CHART_WIDTH;
    extern unsigned short CHART_HEIGHT;

    void SetConsoleColor(int bg, int fg) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (bg << 4) | fg);
    }

    void DrawAxles() {
        int halfW = CHART_WIDTH / 2;
        int halfH = CHART_HEIGHT / 2;

        std::string indent(halfW + 3, ' ');
        std::cout << indent << "Y (" << halfH << ")" << std::endl;
        std::cout << indent << "^" << std::endl;

        for (int row = halfH; row >= -halfH; row--) {
            if (row == 0) {
                for (int col = -halfW; col <= halfW; col++) {
                    if (col == -halfW) std::cout << "   ";
                    if (col == 0) std::cout << "+";
                    else std::cout << "-";
                }
                std::cout << "---> X (" << halfW << ")" << std::endl;
            }
            else {
                for (int col = -halfW; col <= halfW; col++) {
                    if (col == -halfW) std::cout << "   ";
                    if (col == 0) std::cout << "|";
                    else std::cout << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    void DrawPoint(Point _Point) {
        int halfW = CHART_WIDTH / 2;
        int halfH = CHART_HEIGHT / 2;

        if (_Point.X < -halfW || _Point.X > halfW ||
            _Point.Y < -halfH || _Point.Y > halfH) {
            SetConsoleColor(4, 15);
            std::cout << std::endl;
            std::cout << " * * * * * * * * * * * * * * * *" << std::endl;
            std::cout << "*   POINT OUTSIDE THE CHART    *" << std::endl;
            std::cout << " * * * * * * * * * * * * * * * *" << std::endl;
            std::cout << std::endl;
            return;
        }

        CHART::SetPoint(_Point.X, _Point.Y);

        std::string indent(halfW + 3, ' ');
        std::cout << indent << "Y (" << halfH << ")" << std::endl;
        std::cout << indent << "^" << std::endl;

        for (int row = halfH; row >= -halfH; row--) {
            if (row == 0) {
                for (int col = -halfW; col <= halfW; col++) {
                    if (col == -halfW) std::cout << "   ";
                    if (col == _Point.X && _Point.Y == 0)
                        std::cout << "*";
                    else if (col == 0)
                        std::cout << "+";
                    else
                        std::cout << "-";
                }
                std::cout << "---> X (" << halfW << ")" << std::endl;
            }
            else {
                for (int col = -halfW; col <= halfW; col++) {
                    if (col == -halfW) std::cout << "   ";
                    bool isPoint = (col == _Point.X && row == _Point.Y);
                    bool isAxisY = (col == 0);
                    bool isDotX = (col == _Point.X);
                    bool isDotY = (row == _Point.Y);

                    if (isPoint)
                        std::cout << "*";
                    else if (isAxisY && isDotY)
                        std::cout << "+";
                    else if (isAxisY)
                        std::cout << "|";
                    else if (isDotX || isDotY)
                        std::cout << ".";
                    else
                        std::cout << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}