/*---------------------------------------------------------*\
|  Definitions for MSI SteelSeries Keyboard Interface       |
|                                                           |
|  Adam Honse (calcprogrammer1@gmail.com), 12/11/2016       |
\*---------------------------------------------------------*/

#ifndef MSI_KEYBOARD_H
#define MSI_KEYBOARD_H

#include <sstream>
#include <wchar.h>
#include <string.h>
#include <Windows.h>
extern "C"
{
#include <hidsdi.h>
}
#include <setupapi.h>
#include <cfgmgr32.h>

#include "VisualizerDefines.h"

class MSIKeyboard
{
public:
    MSIKeyboard();
    ~MSIKeyboard();

    int Initialize();
    bool SetLEDs(COLORREF pixels[64][256]);

private:
    HANDLE dev;
    void send_usb_msg(char * data_pkt);
};

#endif