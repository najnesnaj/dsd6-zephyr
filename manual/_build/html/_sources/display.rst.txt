.. _display-sample:

display (ssd1306)
================

in order to get the ds d6 display working 
you will need to replace the standard display driver by the one provided in the directory drivers
(file ssd1306.c)



for the id107 hr plus you will need the ssd1306.c-id107hrplus.



Display    example
~~~~~~~~~~~~~~~~~~~

The display uses the character frame buffer (cfb).

There are two samples which should work out of the box.


check out the  cfb_shell - samples, which is really cool.
You will need a serial connection :eg. :  minicom -b 115200 -D /dev/ttyACM1.
(just type help to get an overview of commands)

.. code-block:: console

    $  cfb init
    $  cfb print 0 0 "hello world"
 


.. code-block:: console

    $  west build -p -b ds_d6 samples/display/cfb 
    or
    $  west build -p -b ds_d6 samples/display/cfb_shell 




Displaying special graphics (not just character) is  possible with the lvgl module.
