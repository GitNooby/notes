#ifndef _PACKT_INPUTSERVICE_HPP_
#define _PACKT_INPUTSERVICE_HPP_

#include "Configuration.hpp"
#include "Context.hpp"
#include "InputHandler.hpp"
#include "Sensor.hpp"
#include "Types.hpp"

#include <android_native_app_glue.h>

namespace packt {
    class InputService : public InputHandler {
    public:
        InputService(android_app* pApplication,
          Configuration* pConfiguration, Sensor* pAccelerometer,
          const int32_t& pWidth, const int32_t& pHeight);

        float getHorizontal();
        float getVertical();
        void setRefPoint(Location* pTouchReference);

        status start();
        status update();
        void stop();

    public:
        bool onTouchEvent(AInputEvent* pEvent);
        bool onKeyboardEvent(AInputEvent* pEvent);
        bool onTrackballEvent(AInputEvent* pEvent);
        bool onAccelerometerEvent(ASensorEvent* pEvent);

    private:
        void toScreenCoord(screen_rot pRotation,
            ASensorVector* pCanonical, ASensorVector* pScreen);

    private:
        android_app* mApplication;

        // Input values.
        float mHorizontal, mVertical;

        // Reference point to evaluate touch distance.
        Location* mRefPoint;
        const int32_t& mWidth, &mHeight;

        // Keys.
        bool mMenuKey;

        // Sensors.
        screen_rot mRotation;
        Sensor* mAccelerometer;
    };
}
#endif
