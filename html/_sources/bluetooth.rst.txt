bluetooth (BLE) example 
=======================

The ds-d6 uses a Nordic nrf52832 chip, which has BLE functionality build into it.

To test, you can compile a standard application : Eddy Stone.

The watch will behave as a bluetooth beacon, and you should be able to detect it with your smartphone or with bluez under linux.



Using the created bluetooth sample:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


I use linux with a bluetoothadapter 4.0.
You will need to install bluez.

.. code-block:: console

    #bluetoothctl
    [bluetooth]#scan on

And your Eddy Stone should be visible.
     

If you have a smartphone, you can download the nrf utilities app from nordic.


Ble Peripheral
~~~~~~~~~~~~~~~

this example is a demo of the services under bluetooth

first build the image


.. code-block:: console


        $  west build -p -b ds_d6 samples/bluetooth/peripheral 



With linux you can have a look using bluetoothctl:



.. code-block:: console

    #bluetoothctl
    [bluetooth]#scan on


    [NEW] Device 60:7C:9E:92:50:C1 Zephyr Peripheral Sample Long
    once you see your device
    [blueooth]#connect 60:7C:9E:92:50:C1 (the device mac address as displayed)

    then you can already see the services


same thing with the app from nordic, you could try to connect and display value of e.g. heart rate


using Python to read out bluetoothservices
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In this repo you will find a python script : readbat.py
In order to use it you need bluez on linux and the python `bluepy` module.

It can be used in conjunction with the peripheral bluetooth demo.
It just reads out the battery level, and prints it.


::

     import binascii
     from bluepy.btle import UUID, Peripheral
      
     temp_uuid = UUID(0x2A19)
       
     p = Peripheral("60:7C:9E:92:50:C1", "random")
        
     try:
        ch = p.getCharacteristics(uuid=temp_uuid)[0]
        print binascii.b2a_hex(ch.read())
     finally:
         p.disconnect()
      
