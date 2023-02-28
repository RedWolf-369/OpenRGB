/*-----------------------------------------*\
|  GalaxGPUController.h                     |
|                                           |
|  Driver for Galax / KFA2 RGB on GPUs      |
|                                           |
|  Niels Westphal (crashniels)  12.07.2020  |
\*-----------------------------------------*/

#include <string>
#include "i2c_smbus.h"

#pragma once

typedef unsigned char galax_gpu_dev_id;

enum
{
    /* RGB Registers */
    GALAX_RED_REGISTER                      = 0x02, /* Red Register */
    GALAX_GREEN_REGISTER                    = 0x03, /* Green Register */
    GALAX_BLUE_REGISTER                     = 0x04, /* Blue Register */
    /* MODE Registers */
    GALAX_MODE_REGISTER_1                   = 0x05, /* Mode Register 1 */
    GALAX_MODE_REGISTER_2                   = 0x06, /* Mode Register 2 */
};

enum
{
    /* Static Mode Values */
    GALAX_MODE_STATIC_VALUE_1               = 0x00,
    GALAX_MODE_STATIC_VALUE_2               = 0x01,
    /* Breathing Mode Values */
    GALAX_MODE_BREATHING_VALUE_1            = 0x04,
    GALAX_MODE_BREATHING_VALUE_2            = 0x00,
    /* Rainbow Mode Values */
    GALAX_MODE_RAINBOW_VALUE_1              = 0x84,
    GALAX_MODE_RAINBOW_VALUE_2              = 0x02,
    /* Cycle Breathing Mode Values */
    GALAX_MODE_CYCLE_BREATHING_VALUE_1      = 0x84,
    GALAX_MODE_CYCLE_BREATHING_VALUE_2      = 0x40,
};

class GalaxGPUController
{
public:
    GalaxGPUController(i2c_smbus_interface* bus, galax_gpu_dev_id);
    ~GalaxGPUController();

    std::string   GetDeviceName();
    std::string   GetDeviceLocation();
    unsigned char GetLEDRed();
    unsigned char GetLEDGreen();
    unsigned char GetLEDBlue();
    void          SetLEDColorsDirect(unsigned char red, unsigned char green, unsigned char blue);
    void          SetLEDColorsEffect(unsigned char red, unsigned char green, unsigned char blue);
    void          SetMode(unsigned char mode);

    unsigned char GalaxGPURegisterRead(unsigned char reg);
    void          GalaxGPURegisterWrite(unsigned char reg, unsigned char val);

    bool          direct = false;                                                // Temporary solution to check if we are in "Direct" mode

private:
    char                    device_name[16];
    i2c_smbus_interface *   bus;
    galax_gpu_dev_id        dev;
};
