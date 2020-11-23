======================
On the subject of UART 
======================


As I am predisposed of finding out things the hard way, it took me a while to notice why the serial port was only partly functioning :

- I used a wrong pin on my dev-board (id107 HR watch) 
- I used a USB - el cheapo - serial port 

The nrf52 is an arm chip with TTL levels of 3.3V, so you need a plug that can handle this voltage instead of the usual 5V.


I did not want to spend money and wait for the postman.
I had an stm32f103c8 lying around. 

This could be converted in a blackmagicprobe, which has a debugprobe and(!) a serial port. The stm32 is 3.3V compatible. Problem solved, which is quite cool, since it uses up only one USB-port.  



read and learn  
--------------


::
 
	To compile a program with a non standard (=jlink) debugger:
	west flash --runner blackmagicprobe






