.. _character_frame_buffer_sample:

Character frame buffer
######################

Overview
********

This sample displays character strings using the Character Frame Buffer
(CFB) subsystem framework.


Building and Running
********************

build the application: west build -p -b ds_d6 samples/display/cfb


on unix : #minicom -b 115200 -D /dev/ttyACM1 

you get a shell and you can type help


to display something on the screen : 
cfb init
cfb invert
cfp print 0 0 "hello world"
