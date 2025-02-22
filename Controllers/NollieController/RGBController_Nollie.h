﻿/*-----------------------------------------*\
|  RGBController_Nollie.h                   |
|                                           |
|  Driver for Nollie32 LED strip controller |
|                                           |
|  Name (cnn1236661)          25th Jun 2023 |
\*-----------------------------------------*/

#pragma once

#include "RGBController.h"
#include "NollieController.h"

#define NOLLIE_CHANNELS_LED_NUM    256

#define NOLLIE32_CHANNELS_NUM      32
#define NOLLIE32_PID               0x4714
#define NOLLIE32_VID               0x3061

#define NOLLIE16_CHANNELS_NUM      16
#define NOLLIE16_PID               0x4716
#define NOLLIE16_VID               0x3061

class RGBController_Nollie : public RGBController
{
public:
    RGBController_Nollie(NollieController* controller_ptr);
    ~RGBController_Nollie();

    void        SetupZones();
    void        ResizeZone(int zone, int new_size);

    void        DeviceUpdateLEDs();
    void        UpdateZoneLEDs(int zone);
    void        UpdateSingleLED(int led);

    void        DeviceUpdateMode();

private:
    NollieController*           controller;
    std::vector<unsigned int>   leds_channel;
    std::vector<unsigned int>   zones_channel;

    int* channel_index;

    int ch32[32] = {5, 4, 3, 2, 1, 0, 15, 14, 26, 27, 28, 29, 30, 31, 8, 9, 19, 18, 17, 16, 7, 6, 25, 24, 23, 22, 21, 20, 13, 12, 11, 10};
    int ch16[32] = {19, 18, 17, 16, 24, 25, 26, 27, 20, 21, 22, 23, 31, 30, 29, 28, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
};
