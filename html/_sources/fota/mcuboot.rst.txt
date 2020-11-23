.. _mcuboot:

Serial Device Firmware Upgrade
################################

My main aim is to get this working.
It has a small footprint, since no need for bluetooth.

I have not(!) been successfull.

west build -b ds_d6 samples/display/cfb -- -DOVERLAY_CONFIG='overlay-serial.conf;overlay-fs.conf'  -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"../bootloader/mcuboot/root-rsa-2048.pem\"



Wireless Device Firmware Upgrade
################################

Overview
********
In order to perform a FOTA (firmware over the air) update on zephyr you need 2 basic components:

        * MCUboot   (a bootloader)
        * SMP Server (a bluetooth service)






.. _mcuboot:



MCUboot with zephyr
###################






Building&flashing the bootloader itself
---------------------------------------


west build -b ds_d6 -s ../bootloader/mcuboot/boot/zephyr -d build-mcuboot
west flash -d build-mcuboot --runner blackmagicprobe

Building&flashing an application for use with bootloader 
--------------------------------------------------------


Some additional configuration is required to build applications for MCUboot.

This is handled internally by the Zephyr configuration system and is wrapped
in the `CONFIG_BOOTLOADER_MCUBOOT` Kconfig variable, which must be enabled in
the application's `prj.conf` file.





west build -b ds_d6 samples/subsys/console/echo -d build-hello-signed -DCONFIG_MCUBOOT_SIGNATURE_KEY_FILE=\"../bootloader/mcuboot/root-rsa-2048.pem\"
west flash -d build-hello-signed --runner blackmagicprobe


another example with overlays:
west build -b ds_d6 samples/subsys/mgmt/mcumgr/smp_svr -- -DOVERLAY_CONFIG='overlay-serial.conf;overlay-fs.conf'



debugging the bootloader 
-------------------------

mcumgr -ldebug -t 60 --conntype=serial --connstring='dev=/dev/ttyACM1,baud=115200' image list






Signing the application
-----------------------

In order to upgrade to an image (or even boot it, if
`MCUBOOT_VALIDATE_PRIMARY_SLOT` is enabled), the images must be signed.

To make development easier, MCUboot is distributed with some example
keys.  It is important to stress that these should never be used for
production, since the private key is publicly available in this
repository.  See below on how to make your own signatures.

Images can be signed with the `scripts/imgtool.py` script.  It is best
to look at `samples/zephyr/Makefile` for examples on how to use this.

Flashing the application
------------------------

west flash knows where to put the application (you do not have to specify the address of the slot)


