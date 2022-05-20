#include <gui/screen2_screen/Screen2View.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen2View::Screen2View():
    counter(0), i(0),
    flag(true)
{
	}


void Screen2View::updateTxt(int newValue)
{
  Unicode::snprintf(txtBuffer, 10, "%d", newValue);
  //txt.invalidate();
}

void Screen2View::handleTickEvent()
{
    counter++;

    if(counter%120 == 0) // every 2s
    {
    	i++;
    	updateTxt(i);
    	textArea1.resizeToCurrentText();
    	textArea1.invalidate();
    	txt.resizeToCurrentText();
    	txt.invalidate();
    	//textArea1.setWildcard(txtBuffer);

        if(flag)
        {
        	textArea2.setWildcard(touchgfx::TypedText(T_VALUEINPPM2).getText());
            //Unicode::snprintf(textArea2Buffer, TEXTAREA_SIZE, "%s", touchgfx::TypedText(T_STMICROID).getText());
            flag = false;
/*            remove(txt);
            txt.invalidate();*/
        }
        else
        {
            textArea2.setWildcard(touchgfx::TypedText(T_VALUEINPPM1).getText());
            //Unicode::snprintf(textArea2Buffer, TEXTAREA_SIZE, "%s", touchgfx::TypedText(T_TOUCHGFXID).getText());
            flag = true;
/*            add(txt);
            txt.invalidate();*/
        }
        textArea2.resizeToCurrentText();
        textArea2.invalidate();

        counter = 0;
    }
}

void Screen2View::setupScreen()
{
    //Screen2ViewBase::setupScreen();
    txt.setTypedText(TypedText(T_LEFT_TEXT));
    txt.setXY(10, 20);
    txt.setWildcard(txtBuffer);
    add(txt);

    updateTxt(5);
	txt.resizeToCurrentText();
	txt.invalidate();

    textArea1.setWildcard(txtBuffer);
	textArea1.resizeToCurrentText();
	textArea1.invalidate();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}
