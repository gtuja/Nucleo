[SyRS_001][Heading]
# Overview

[SyRS_002][ReqInformation]
NPA(Nucleo Playground Application) is an application that provides features,i.e., button LED control.

[SyRS_003][Heading]
# Environment

[SyRS_004][ReqFunctional]
NPA shall run on the EVB(Evaluation Board), nucleo-f429ZI.

[SyRS_005][ReqFunctional]
NPA shall be implemented with CubeIDE version 1.51 provided by ST.

[SyRS_006][ReqFunctional]
NPA shall implement features with 1 button and 3 LEDs on the EVB.

[SyRS_007][Heading]
# Features

[SyRS_008][Heading]
## LED Control

[SyRS_009][Heading]

## Button Control

[SyRS_010][ReqFunctional]
NPA shall define button states below
- STT_BTN_RELEASED
- STT_BTN_PRESSED

[SyRS_011][ReqFunctional]
NPA shall monitor button state and notify events below.
- EVT_BTN_SINGLE : Button is pressed for less than 1 second and released.
- EVT_BTN_PET1S : Button is pressed for 1 second and still pressed.
- EVT_BTN_PET2S : Button is pressed for 2 second and still pressed.
- EVT_BTN_PET3S : Button is pressed for 3 second and still pressed.

[SyRS_012][ReqFunctional]
NPA shall implement hysteresis, i.e., repeated 5 times in a row, both states of pressed and released.

[SyRS_013][ReqFunctional]
NPA shall respond every 1ms.

[SyRS_0xx][Heading]
# LED Control

[SyRS_0xx][ReqFunctional]
NPA shall define LEDs below.
- STT_LED_OFF
- STT_LED_FADE_IN
- STT_LED_FADE_OFF
- STT_LED_ON

[SyRS_0xx][ReqFunctional]
NPA shall fade in LEDs when LED state is off and EVT_BTN_SINGLE is invoked.

[SyRS_0xx][ReqFunctional]
NPA shall fade off LEDs when LED state is on and EVT_BTN_SINGLE is invoked.

[SyRS_0xx][ReqFunctional]
NPA shall fade in LEDs for 500ms.

[SyRS_0xx][ReqFunctional]
NPA shall fade out LEDs for 800ms.



