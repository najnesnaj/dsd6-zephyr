===================================
debugging   the ds-d6 smartwatch
===================================
::

    The ds-D6 has a serial port. 


The blackmagicprobe can lauch a debugger : west debug --runnerblackmagicprobe.
The probe has a serial port /dev/ttyACM1 (linux : minicom -b 115200 -D /dev/ttyACM1) 


The Segger Jlink, which is kind of standard in zephyr can use the the swd-connector for debug messages as well.
    
.. note::


    The Segger JLink offers the JLinkRTTViewer.
    In order to use it, you can set this in ds_d6_defconfig (boardconfig)
    CONFIG_LOG=y
    CONFIG_USE_SEGGER_RTT=y
    CONFIG_SHELL=y
    CONFIG_SHELL_BACKEND_RTT=y
 



sniffing memory

.. code-block:: console

      The JLink probe allowed to check memory at 0x5000504 and 0x50000514.
      #mem32 0x5000504 0x1
      or write a value
      #w4 0x50000504 0x12345678
      This allowed me to check GPIO ports.











