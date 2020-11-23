.. _shell_bt_nus:

Bluetooth: NUS shell transport
##############################


for this, you will need the nordic branch of zephyr (https://github.com/nrfconnect/sdk-zephyr)

.. contents::
   :local:
   :depth: 2

The Nordic UART Service (NUS) shell transport sample demonstrates how to use the :ref:`shell_bt_nus_readme` to receive shell commands from a remote device.


TODO
####

You can use the shell to type messages on the OLED screen (cfb character frame buffer)
You can use bluetooth shell to type messages on OLED screen.

It would be really cool to use bt-shell to type message on uart (and the other way around)

I experimented with bt-shell and here you can use gatt to type characters on bluetooth.

Overview
********

When the connection is established, you can connect to the sample through the :ref:`nus_service_readme` by using a host application.
You can then send shell commands, that are executed on the device that runs the sample, and see the logs.
See :ref:`shell_bt_nus_host_tools` for more information about the host tools available, in |NCS|, for communicating with the sample.



Building and running
********************

.. |sample path| replace:: :file:`samples/bluetooth/shell_bt_nus`

.. include:: /includes/build_and_run.txt



Testing using the BLE Console
=============================

See :ref:`ble_console_readme` for more information on how to test the sample using the BLE Console.

Dependencies
************

This sample uses the following |NCS| libraries:

* :ref:`shell_bt_nus_readme`
* :ref:`nus_service_readme`

In addition, it uses the following Zephyr libraries:

* :ref:`zephyr:bluetooth_api`:

  * ``include/bluetooth/bluetooth.h``
  * ``include/bluetooth/hci.h``
  * ``include/bluetooth/uuid.h``
  * ``include/bluetooth/gatt.h``
  * ``samples/bluetooth/gatt/bas.h``
* :ref:`zephyr:logging_api`
