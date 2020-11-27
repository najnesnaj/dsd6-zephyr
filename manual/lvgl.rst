.. _lvgl-sample:

LittlevGL Basic Sample
######################

Overview
********

This sample application displays "Hello World" in the center of the screen.

LittlevGL is a free and open-source graphics library providing everything you need to create embedded GUI with easy-to-use graphical elements, beautiful visual effects and low memory footprint. 




Settings
*********

    - the lvgl settings happen in the config file (or what it in prj.cfg)
    - the ssd1306 is a monochrome display

CONFIG_SPI=y
CONFIG_LVGL_DISPLAY_DEV_NAME="SSD1306"
CONFIG_LVGL_HOR_RES_MAX=128
CONFIG_LVGL_VER_RES_MAX=32
CONFIG_LVGL_VDB_SIZE=64
CONFIG_LVGL_BITS_PER_PIXEL=1
CONFIG_LVGL=y
CONFIG_LVGL_COLOR_DEPTH_1=y 
CONFIG_LVGL_COLOR_TRANSP_GREEN=y
CONFIG_LVGL_USE_API_EXTENSION_V6=y
CONFIG_LVGL_USE_API_EXTENSION_V7=y
CONFIG_LVGL_USE_THEME_MONO=y
CONFIG_LVGL_THEME_DEFAULT_COLOR_PRIMARY_WHITE=y
CONFIG_LVGL_THEME_DEFAULT_COLOR_SECONDARY_BLACK=y

CONFIG_LVGL_EXT_CLICK_AREA_OFF=y
CONFIG_LVGL_USE_LABEL=y

CONFIG_LVGL_LABEL_DEF_SCROLL_SPEED=25
CONFIG_LVGL_LABEL_WAIT_CHAR_COUNT=3
 CONFIG_LOG_PROCESS_TRIGGER_THRESHOLD=10
 CONFIG_LOG_PROCESS_THREAD=y
 CONFIG_LOG_PROCESS_THREAD_SLEEP_MS=1000
 CONFIG_LOG_PROCESS_THREAD_STACK_SIZE=768
 CONFIG_LOG_BUFFER_SIZE=1024
 CONFIG_LOG_DETECT_MISSED_STRDUP=y
 CONFIG_LOG_STRDUP_MAX_STRING=400
 CONFIG_LOG_STRDUP_BUF_COUNT=32

References
**********
https://docs.littlevgl.com/en/html/index.html

LittlevGL Web Page: https://littlevgl.com/
