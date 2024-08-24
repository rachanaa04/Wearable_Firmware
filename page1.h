#ifndef PAGE1_H
#define PAGE1_H

#include "config.h"
#include "pages.h"
#include <Arduino.h>  // Include necessary Arduino library

// LV_FONT_DECLARE(lv_font_montserrat_28);
// LV_FONT_DECLARE(lv_font_montserrat_18);
LV_IMG_DECLARE(logo);
LV_IMG_DECLARE(ambient);
LV_IMG_DECLARE(ambient_red);
LV_IMG_DECLARE(ambient_green);
LV_IMG_DECLARE(healthring);
LV_IMG_DECLARE(healthring_red);
LV_IMG_DECLARE(injuryh);
LV_IMG_DECLARE(injuryh_red);
LV_IMG_DECLARE(injuryh_green);
LV_IMG_DECLARE(health);
LV_IMG_DECLARE(batterygfinal);

extern lv_obj_t *page_1;
static lv_obj_t *healthring_text,*injuryh_text,*ambient_temp_text;
static lv_obj_t *gContainer_p1,*time_text, *date_text, *day_text, *location_text,
                    *healthring_btn, *ambient_temp_btn_p1, *battery, *injuryh_btn;

extern byte health_val;
extern byte injuryh_val;
extern byte ambient_temp_val;
extern bool p1_main_flag;
extern int hour, minute, month, date, year, day;

void click_event_p1(lv_obj_t *obj, lv_event_t event);
const char *stringToConstChar(String str);
void page_1_init();
void dynamic_p1_main();
void day_label_text(int day);

#endif