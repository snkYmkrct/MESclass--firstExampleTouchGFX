#include <gui/screen3_screen/Screen3View.hpp>
#include <stdlib.h>

Screen3View::Screen3View()
{
    tickCounter = 0;
}

void Screen3View::handleTickEvent()
{
    tickCounter++;

    // Insert each second tick
    if (tickCounter % 5 == 0)
    {
      // Insert data point
      dynamicGraph.addDataPoint(rand() % 100);
    }
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
