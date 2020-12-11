/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <drivers/sensor.h>

#include <device.h>
//#include <devicetree.h>
//#include <drivers/gpio.h>

/**
 * @file Sample app using the MAX44009 light sensor through ARC I2C.
 *
 * This app will read the sensor reading via I2C interface and show
 * the result every 4 seconds.
 */



/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

//#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0    DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN     DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS   DT_GPIO_FLAGS(LED0_NODE, gpios)
//#else
/* A build error here means your board isn't set up to blink an LED. */
/*#error "Unsupported board: led0 devicetree alias is not defined"
#define LED0    ""
#define PIN     0
#define FLAGS   0
#endif
*/





void main(void)
{
	const struct device *dev;
//        const struct device *devled;
        int ret;
	printk("MAX44009 light sensor application\n");

//      devled = device_get_binding("led0");
//      ret = gpio_pin_configure(devled, PIN, GPIO_OUTPUT_ACTIVE );
//      gpio_pin_set(devled, 26, 0);

//		printk("led on %d", PIN);
//		k_sleep(K_MSEC(4000));

	struct sensor_value val;
	uint32_t lum = 0U;
/*
	dev = device_get_binding("BME280");
	if (!dev) {
		printk("sensor: bosche testing not found.\n");
		return;
	}
*/
	dev = device_get_binding("MAX44009");
	if (!dev) {
		printk("sensor: device not found.\n");
		return;
	}
//else
//		printk("sensor: device max44 found.\n");

	while (1) {
		if (sensor_sample_fetch_chan(dev, SENSOR_CHAN_LIGHT) != 0) {
			printk("sensor: sample fetch fail.\n");
			return;
		}

		if (sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &val) != 0) {
			printk("sensor: channel get fail.\n");
			return;
		}

		lum = val.val1;
		printk("sensor: lum reading: %d\n", lum);

		k_sleep(K_MSEC(10));
	}
}
