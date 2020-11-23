Starting with some basic applications
=====================================


The best way to get a feel of zephyr, is to start building sample applications.

The gpio ports, i2c communication, memory layout, stuff that is particular for the watch is defined in the board definition file.

The provided samples are standard zephyr application, with some minor modifications.




Blinky    example
~~~~~~~~~~~~~~~~~



::

    The watch does not contain a led as such, but it has a heart rate sensor. 
    
    Powering the heart rate sensor, lights up the green led.






have a look at the ds_d6.dts file, here you see the definition of the led.

.. code-block:: console
           $ vi  ~/zephyrproject/zephyr/boards/arm/ds_d6/ds_d6.dts

           gpios = <&gpio0 26 1>;




`building an image, which can be found under the build directory`

see : :ref:`blinky-sample` 

.. code-block:: console

    $ cd ~/zephyrproject/zephyr
    $ west build -p -b ds_d6 samples/basic/blinky

once the compilation is completed,  you can find the firmware under :
~/zephyrproject/zephyr/build/zephyr/zephyr.bin 


you can upload it with:

west flash 
or
west flash --runner blackmagicprobe (or jlink, or ....)

