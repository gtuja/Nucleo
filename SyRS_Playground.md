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
[SyRS_009][ReqFunctional]

## Button Control
NPA shall monitor button state and notify events below.
- EVT_BTN_SINGLE : Button is pressed for less than 1 second and released.
- EVT_BTN_PET1S : Button is pressed for 1 second and still pressed.
- EVT_BTN_PET2S : Button is pressed for 2 second and still pressed.
- EVT_BTN_PET3S : Button is pressed for 3 second and still pressed.
NPA shall implement hysteresis, i.e., repeated 5 times in a row, both states of pressed and released.
# LED Control
NPA shall implement fade in when EVT_BTN_SINGLE is invoked.




