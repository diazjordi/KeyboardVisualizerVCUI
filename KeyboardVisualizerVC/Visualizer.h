/*---------------------------------------------------------*\
|  Definitions for Keyboard Visualizer                      |
|                                                           |
|  Adam Honse (calcprogrammer1@gmail.com), 12/11/2016       |
\*---------------------------------------------------------*/

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "stdafx.h"
#include <math.h>
#include "chuck_fft.h"
#include "hsv.h"
#include "net_port.h"

#include <string>
#include <vector>

#include "VisualizerDefines.h"

typedef struct
{
    int amplitude;
    int avg_mode;
    int avg_size;
    int window_mode;
    int decay;
    int delay;
    float anim_speed;
    int bkgd_bright;
    int bkgd_mode;
    int single_color_mode;
    float nrml_ofst;
    float nrml_scl;
    int frgd_mode;
    float bkgd_step;
} settings_pkt_type;

typedef int net_mode;
enum
{
    NET_MODE_DISABLED,
    NET_MODE_CLIENT,
    NET_MODE_SERVER
};

class Visualizer
{
public:
	Visualizer();
	
	//Initializes the visualizer
	void Initialize();

	//Function to start thread
	void StartThread();

	//Visualizer Thread
	void VisThread();

    //Network Threads
    void NetConnectThread();
    void NetUpdateThread();

	//Keyboard Update Thread
	void RazerChromaUpdateThread();
    void CorsairKeyboardUpdateThread();
    void CmKeyboardUpdateThread();
    void SteelSeriesKeyboardUpdateThread();
    void MSIKeyboardUpdateThread();
    void LEDStripUpdateThread();

    //Called when settings changed
    void OnSettingsChanged();

    //Initialize Server
    void InitServer(char * serverstring);

    //Initialize CLient
    void InitClient(char * clientstring);

	//Update function
	void Update();

    //Draw Pattern
    void Visualizer::DrawPattern(VISUALIZER_PATTERN pattern, int bright, vis_pixels *pixels);

    //Add LED strip
    void AddLEDStrip(char* ledstring);
    void AddLEDStripXmas(char * ledstring);

    //Save Settings File
    void SaveSettings();

    //Compute normalization line
    void SetNormalization(float offset, float scale);

	//Calculated FFT
	float fft[256];
	
	//Amplitude of input waveform
	int amplitude;
    int avg_mode;
	int avg_size;
	int window_mode;
	int decay;
	int delay;

    //Visualizer Background
    vis_pixels pixels_bg;

    //Visualizer Foreground
    vis_pixels pixels_fg;

	//Visualizer Image 1
    vis_pixels pixels_vs1;

    //Visualizer Image 2
    vis_pixels pixels_vs2;

    //Visualizer Output Image Pointer
    vis_pixels *pixels_out;

    //Visualizer Render Image Pointer
    vis_pixels *pixels_render;

	//Background Variables
    float anim_speed;
	int bkgd_bright;
	int bkgd_mode;

    //Single Color Mode
    int single_color_mode;

    //Normalization Offset and Scale
    float nrml_ofst;
    float nrml_scl;

    //Foreground Variables
    int frgd_mode;

private:
	//Background Step
	float bkgd_step;

    //Network Port Pointer
    net_port * port;

    //Network Mode
    net_mode netmode;

	//FFT Variables
	float win_hanning[256];
	float win_hamming[256];
	float win_blackman[256];
	float fft_tmp[512];

	//Audio Sample Buffer
	unsigned char buffer[256];

    void DrawSingleColorForeground(float amplitude, vis_pixels *fg_pixels, vis_pixels *out_pixels);
};

#endif
