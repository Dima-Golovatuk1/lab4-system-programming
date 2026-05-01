#include "engine.h"
#include "../bin/models/axles.h"
#include "../bin/models/point.h"
#include "../bin/actions/render.h"
#include <iostream>
#include <string>
#include <windows.h>

namespace ENGINE {
    CHART::Point LocalPoint = { 0, 0 };

    void ClearChart() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (0 << 4) | 15);
        system("cls");
    }

    void GetUserData(Figures _Figure) {
        if (_Figure == figPoint) {
            std::cout << "Enter point X: ";
            std::cin >> LocalPoint.X;
            std::cout << "Enter point Y: ";
            std::cin >> LocalPoint.Y;
        }
    }

    void DrawChart(Figures _Figure) {
        if (_Figure == figPoint) {
            CHART::DrawPoint(LocalPoint);
        }
    }

    void Init() {
        unsigned short userW = 0, userH = 0;

        do {
            std::cout << "Enter chart width (>= 20): ";
            int tmp; std::cin >> tmp;
            if (tmp >= 20) userW = tmp;
            else std::cout << "Must be >= 20!" << std::endl;
        } while (userW == 0);

        do {
            std::cout << "Enter chart height (>= 10): ";
            int tmp; std::cin >> tmp;
            if (tmp >= 10) userH = tmp;
            else std::cout << "Must be >= 10!" << std::endl;
        } while (userH == 0);

        CHART::SetChartSize(userW, userH);

        std::string choice;
        while (true) {
            std::cout << std::endl;
            std::cout << "1 - Enter the point" << std::endl;
            std::cout << "------------------" << std::endl;
            std::cout << "q - Exit" << std::endl;
            std::cout << std::endl;
            std::cout << "Select the Item: ";
            std::cin >> choice;

            ClearChart();

            if (choice == "1") {
                GetUserData(figPoint);
                DrawChart(figPoint);
            }
            else if (choice == "q" || choice == "Q") {
                break;
            }
        }
    }
}