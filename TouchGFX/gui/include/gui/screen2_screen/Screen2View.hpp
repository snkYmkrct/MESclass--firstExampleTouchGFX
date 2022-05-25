#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    virtual void updateTxt(int newValue);

    virtual void functia_mea();

protected:
    uint8_t counter, i;
    bool flag;
    TextAreaWithOneWildcard txt;
    Unicode::UnicodeChar txtBuffer[10];
};

#endif // SCREEN2VIEW_HPP
