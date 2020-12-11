Sensors
#######

Overview
********

the dsd6 contains several sensors.

The heart rate sensor is the pah8001 from Pixart.

I used the Max44009 as a template to setup the pah8001 as a lightsensor. 






Settings
*********

the lightsensor is on the I2C bus, but it needs to be powered (pin 26), otherwise the I2C crashes. I modified the board definitionfile so as if it contains an external powerregulator which gets powered first.



References
**********

