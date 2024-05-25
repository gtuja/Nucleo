[SyRS_001][Heading]
# Overview

[SyRS_002][ReqInformation]
NPA(Nucleo Playground Application) is a collection of application with nucleo evaluation boards for self-improvement.

[SyRS_003][Heading]
# Environment

[SyRS_004][ReqFunctional]
NPA shall run on the STM(ST microcontroller), e.g., nucleo-f429ZI.
NPA shall be implemented with CubeIDE version 1.51 provided by STM.
Feature specific restrictions, e.g., clock, ROM, RAM, shall be defined during evaluation phase.

[SyRS_007][Heading]
# Features
## NBB

[SyRS_xxx][Heading]
## GSML

[SyRS_xxx][ReqFunctional]
GSML(G? State Machine Library) is to provide state control for components, e.g., button, LED.

[SyRS_xxx][ReqFunctional]
GSML is platform independent library written in portable language, C.

[SyRS_xxx][Heading]
### Concept

[SyRS_xxx][ReqFunctional]
It could be a common story that components with the same state control, e.g, buttons, LEDs.
GSML shall play a relay role between driver, e.g., button, LEDs, periodic ISR, and application.
GSML shall provide a general state machine for each component.
Device specific configuration should 

[SyRS_xxx][ReqFunctional]
GSML is composed of modules below.
- GSML_COMMON
- GSML_Template
- GSML_Button
- GSML_XXX

[SyRS_xxx][ReqFunctional]
GSML_COMMON shall define and implement common features below.
- Enum type of state functions, i.e., entry, do, exit.
- Debug feature to evaluate GSML through serial communication, etc.

[SyRS_xxx][ReqFunctional]
GSML_Template shall provide template code to use GSML.

[SyRS_xxx][ReqInformation]
Code generation for GSML shall be defined as a futher feature.

[SyRS_xxx][ReqFunctional]
GSML is composed of GSML_xxx, e.g, GSML_Button, GSML_Led.



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



