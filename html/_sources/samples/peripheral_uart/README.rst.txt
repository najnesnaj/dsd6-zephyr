.. _peripheral_uart:

Bluetooth: Peripheral UART
##########################

for this you will need the nordic branch of zephyr : nrfconnect/sdk-zephyr 


TODO
########

this samples prints data on serial port on the bluetooth service (and the other way around)

it would be cool if you could use cfb (character frame buffer) as well. (send messages to screen)



 
.. contents::
   :local:
   :depth: 2

The Peripheral UART sample demonstrates how to use the :ref:`nus_service_readme`.
It uses the NUS service to send data back and forth between a UART connection and a Bluetooth LE connection, emulating a serial port over Bluetooth LE.


Overview
********

When connected, the sample forwards any data received on the RX pin of the UART 1 peripheral to the Bluetooth LE unit.
On Nordic Semiconductor's development kits, the UART 1 peripheral is typically gated through the SEGGER chip to a USB CDC virtual serial port.

Any data sent from the Bluetooth LE unit is sent out of the UART 1 peripheral's TX pin.


.. _peripheral_uart_debug:

Debugging
*********

In this sample, the UART console is used to send and read data over the NUS service.
Debug messages are not displayed in this UART console.
Instead, they are printed by the RTT logger.

If you want to view the debug messages, follow the procedure in :ref:`testing_rtt_connect`.



Building and running
********************

.. |sample path| replace:: :file:`samples/bluetooth/peripheral_uart`

.. include:: /includes/build_and_run.txt

.. _peripheral_uart_testing:

Testing
=======


Dependencies
************

This sample uses the following |NCS| libraries:

* :ref:`nus_service_readme`

In addition, it uses the following Zephyr libraries:

* ``include/zephyr/types.h``
* ``boards/arm/nrf*/board.h``
* :ref:`zephyr:kernel_api`:

  * ``include/kernel.h``

* :ref:`zephyr:api_peripherals`:

   * ``incude/gpio.h``
   * ``include/uart.h``

* :ref:`zephyr:bluetooth_api`:

  * ``include/bluetooth/bluetooth.h``
  * ``include/bluetooth/gatt.h``
  * ``include/bluetooth/hci.h``
  * ``include/bluetooth/uuid.h``
