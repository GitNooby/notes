#ifndef _PACKT_INPUTHANDLER_HPP_
#define _PACKT_INPUTHANDLER_HPP_

#include <android/input.h>

namespace packt {
    class InputHandler {
    public:
        virtual ~InputHandler() {};

        virtual bool onTouchEvent(AInputEvent* pEvent) = 0;
    };
}
#endif
