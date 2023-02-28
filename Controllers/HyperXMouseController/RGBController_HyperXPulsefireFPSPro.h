/*-----------------------------------------*\
|  RGBController_HyperXPulsefireFPSPro.h    |
|                                           |
|  Generic RGB Interface for HyperX         |
|  Pulsefire FPS Pro                        |
|                                           |
|  Adam Honse (CalcProgrammer1) 12/26/2020  |
\*-----------------------------------------*/

#pragma once
#include <chrono>

#include "RGBController.h"
#include "HyperXPulsefireFPSProController.h"

class RGBController_HyperXPulsefireFPSPro : public RGBController
{
public:
    RGBController_HyperXPulsefireFPSPro(HyperXPulsefireFPSProController* controller_ptr);
    ~RGBController_HyperXPulsefireFPSPro();

    void        SetupZones();

    void        ResizeZone(int zone, int new_size);
    
    void        DeviceUpdateLEDs();
    void        UpdateZoneLEDs(int zone);
    void        UpdateSingleLED(int led);

    void        DeviceUpdateMode();

    void        KeepaliveThread();
    
private:
    HyperXPulsefireFPSProController*                    controller;
    std::thread*                                        keepalive_thread;
    std::atomic<bool>                                   keepalive_thread_run;
    std::chrono::time_point<std::chrono::steady_clock>  last_update_time;
};
