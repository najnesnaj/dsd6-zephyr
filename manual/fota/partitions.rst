
.. _signing:

Partitions
##########


.. code-block:: console


      have a look at boards/ds_d6.dts


Defining partitions for MCUboot 
-------------------------------


The first step required for Zephyr is making sure your board has flash
partitions defined in its device tree. These partitions are:

- `boot_partition`: for MCUboot itself
- `image_0_primary_partition`: the primary slot of Image 0
- `image_0_secondary_partition`: the secondary slot of Image 0
- `scratch_partition`: the scratch slot



Remark
------
the ds_d6 has no nor flash. Having 2 slots limits the size of you program!
You can also use 1 slot. (is less secure of course)         
         
         
         
         
         
         
         
         
         
