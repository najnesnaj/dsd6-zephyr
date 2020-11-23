# desay D6  Zephyr

[desay D6](https://github.com/fanoush/ds-d6 for more info) firmware toolkit based on [Zephyr Project](https://www.zephyrproject.org/) RTOS.

A collection of drivers, libraries and samples to build your own Desay D6 smart watch firmware.



## This is work in progress 

The watch has a nordic nrf52832 microcontroller , a ssd1306 oled display and (!) a serial port (usb port).
The watch is very cheap. (I bought it for 5 euro) 

I think it should be possible to install zephyr on this watch without opening it.
Key will be to install a serial bootloader. 
I have been testing the mcuboot zephyr serial bootloader without succes ...

My effort has been focused on using the serial port feature, bluetooth connectivity and OLED screen.
This should allow to use the watch as a bluetooth interface.
The display works as a serial display.


## id107 HR plus
I have put some effort in this watch as well, but can not get display to work.
The reason I guess is the chip select pin. Seems like it is not listening to spi.


## A word on Zephyr

Zephyr is an open source RTOS for microcontrollers.
The cool thing is bluetooth support.



Nordic Semiconductor has it's own branch of the open source kit.
From what I understand : they plan on shipping this to customers.
They put a lot of effort into it, and you get super nice features (uart over bluetooth).
NCS is using BSD-5-Clause-Nordic license (https://github.com/NordicPlayground/fw-nrfconnect-nrf/blob/master/LICENSE)
I have adapted a few samples (which are tailored to the nordic dev boards) for the dsd6 watch. 



## Where To Start?
Read the tutorial! A helpful manual is included in the repository:
 - [pdf](oswatch.pdf)
 - [epub](opensourcewatch.epub)
 - [html](manual/_build/html/index.html)

## Installation Overview
1. Follow the Zephyr [Getting Started Guide](https://docs.zephyrproject.org/latest/getting_started/index.html) to install zephyr SDK and tools.
2. Install `west` meta tool (https://docs.zephyrproject.org/latest/guides/west/install.html).

For the Nordic specific samples you will need their kit :
https://github.com/nrfconnect/sdk-nrf


You will have to copy the board definition files to boards/arm 
In order to the the OLED working, you will need to replace drivers/display/ssd1306.c by the one in this repository.




Resources:
- West documentation: https://docs.zephyrproject.org/latest/guides/west
- nRF Connect SDK is using zephyr in similar way and its documentation can be helpful as well: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/gs_installing.html


## What Is Included?
In this repository you can find files that supplement a zephyr installation.

* **board definition** Contains the board definition for the dsd6 and the id107hr-plus.
* **drivers** Contains the modified display driver for the dsd6.
* **samples** Modified samples for blinky, button, cfb (character frame buffer)

## Project Roadmap
### DONE
- the display
- bluetooth BLE
- RTC
- CTS (setting time in bluetooth)
- DFU (wireless firmware update)

### TODO
- DFU (serial firmware update)
- accel sensor
- heart rate sensor
- graphics libraries
- - LittlevGL
- HR detection (algorithm)
- accel sensor (eg step counter)
- powermanagement
- watchdog

