The 'Blinky' project is a simple demo program for
ST 'STM32L053R0' microcontroller using ST 'Nucleo-L053R8' Evaluation Board.
Compliant to Cortex Microcontroller Software Interface Standard (CMSIS).

Example functionality:
 - Clock Settings:
   - XTAL    = HSI     = 16.00 MHz
   - SYSCLK  =           32.00 MHz

 - one LED blinks
 - blinking is paused while holding down the USER button.


The Blinky program is available in different targets:
 - Debug:
   - Compiler optimization Level 1
   - Enabled Event Recorder
   - Keil RTX5 variant 'Source'
 - Release:
   - Compiler optimization Level 3
   - Keil RTX5 variant 'Library'

