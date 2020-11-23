/*
 * Copyright (c) 2018 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <display/cfb.h>
#include <stdio.h>
//#include <drivers/gpio.h>

#if defined(CONFIG_SSD16XX)
#define DISPLAY_DRIVER		"SSD16XX"
#endif

#if defined(CONFIG_SSD1306)
#define DISPLAY_DRIVER		"SSD1306"
#endif

#ifndef DISPLAY_DRIVER
#define DISPLAY_DRIVER		"DISPLAY"
#endif

/*

#define LED0_NODE DT_ALIAS(led0)

#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
#define LED0    DT_GPIO_LABEL(LED0_NODE, gpios)
#define PIN     DT_GPIO_PIN(LED0_NODE, gpios)
#define FLAGS   DT_GPIO_FLAGS(LED0_NODE, gpios)
#endif

*/



void main(void)
{       

/*       const struct device *devled;

		printf("begin testing!\n");


        int ret;

        devled = device_get_binding(LED0);
        if (devled == NULL) {
                return;
        }

        ret = gpio_pin_configure(devled, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
        if (ret < 0) {
                return;
        }
//        gpio_pin_set(devled, PIN, 1); //is done in ssd1306.c
*/
        uint16_t rows;
	uint8_t ppt;
	uint8_t font_width;
	uint8_t font_height;
	const struct device *dev;

	dev = device_get_binding(DISPLAY_DRIVER);

	if (dev == NULL) {
		printf("Device not found\n");
		return;
	}

	if (display_set_pixel_format(dev, PIXEL_FORMAT_MONO10) != 0) {
		printf("Failed to set required pixel format\n");
		return;
	}

	printf("initialized %s\n", DISPLAY_DRIVER);

	if (cfb_framebuffer_init(dev)) {
		printf("Framebuffer initialization failed!\n");
		return;
	}

	cfb_framebuffer_clear(dev, true);

	display_blanking_off(dev);

	rows = cfb_get_display_parameter(dev, CFB_DISPLAY_ROWS);
	ppt = cfb_get_display_parameter(dev, CFB_DISPLAY_PPT);
	printf("rows %d\n", rows);
	printf("ppt %d\n", ppt);

	for (int idx = 0; idx < 42; idx++) {
		if (cfb_get_font_size(dev, idx, &font_width, &font_height)) {
			break;
		}
		cfb_framebuffer_set_font(dev, idx);
		printf("font width %d, font height %d\n",
		       font_width, font_height);
	}

//test to see if it gets any pixel light
//cfb_framebuffer_invert(dev);
	printf("x_res %d, y_res %d, ppt %d, rows %d, cols %d\n",
	       cfb_get_display_parameter(dev, CFB_DISPLAY_WIDTH),
	       cfb_get_display_parameter(dev, CFB_DISPLAY_HEIGH),
	       ppt,
	       rows,
	       cfb_get_display_parameter(dev, CFB_DISPLAY_COLS));

	while (1) {
		for (int i = 0; i < rows; i++) {
			cfb_framebuffer_clear(dev, false);
			if (cfb_print(dev,
				      "DS-D6 ZEPHYR j!\"§$%&/()=",
				      0, i * ppt)) {
				printf("Failed to print a string\n");
				continue;
			}
//                        else
//				printf("print a string was a success\n");

			k_sleep(K_MSEC(1000));
//        gpio_pin_set(devled, PIN, 1); //is done in ssd1306.c
			cfb_framebuffer_finalize(dev);
//#if defined(CONFIG_ARCH_POSIX)
//#endif
		}
	}
}
