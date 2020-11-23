Menuconfig 
==========


Zephyr is like linux
~~~~~~~~~~~~~~~~~~~~

Once you have build a sample, you can add extra stuff by using the configuration menu.
 


.. code-block:: console


    $ west build -t menuconfig 

::

        Modules  --->
        Board Selection (nRF52832-MDK)  --->
        Board Options  --->
        SoC/CPU/Configuration Selection (Nordic Semiconductor nRF52 series MCU)  --->
        Hardware Configuration  --->
        ARM Options  --->
        Architecture (ARM architecture)  --->
        General Architecture Options  --->
    [ ] Floating point  ----
        General Kernel Options  --->
        C Library  --->
        Additional libraries  --->
    [*] Bluetooth  --->
    [ ] C++ support for the application  ----
        System Monitoring Options  --->
        Debugging Options  --->
    [ ] Disk Interface  ----
        File Systems  --->
    -*- Logging  --->
        Management  --->
        Networking  --->

after saving :
--------------

you will need to rebuild the image to include changes in config

.. code-block:: console

    $ west build 
 
