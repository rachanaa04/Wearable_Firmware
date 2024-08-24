#ifndef PAGE2_H
#define PAGE2_H

#include "config.h"
#include "pages.h"
#include <Arduino.h> // Include necessary Arduino library

LV_IMG_DECLARE(logo);
LV_IMG_DECLARE(contactbodytemp);
LV_IMG_DECLARE(contactbodytemp_green);
LV_IMG_DECLARE(contactbodytemp_red);
LV_IMG_DECLARE(respiration_rate);
LV_IMG_DECLARE(respiration_rate_green);
LV_IMG_DECLARE(respiration_rate_red);
LV_IMG_DECLARE(ambient);
LV_IMG_DECLARE(trauma);
LV_IMG_DECLARE(health);
LV_IMG_DECLARE(arrow_up);
LV_IMG_DECLARE(arrowdown);
LV_IMG_DECLARE(profile);

LV_IMG_DECLARE(spO2);
LV_IMG_DECLARE(spO2_green);
LV_IMG_DECLARE(spO2_red);
LV_IMG_DECLARE(heartrateV);
LV_IMG_DECLARE(heartrateV_red);
LV_IMG_DECLARE(heartrateV_green);
LV_IMG_DECLARE(heartrate);
LV_IMG_DECLARE(heartrate_red);
LV_IMG_DECLARE(heartrate_green);

LV_IMG_DECLARE(inactive);
LV_IMG_DECLARE(highly_active);
LV_IMG_DECLARE(active);

LV_IMG_DECLARE(shockwave);
LV_IMG_DECLARE(falldamage);
LV_IMG_DECLARE(falldamage_red);
LV_IMG_DECLARE(falldamage_green);
LV_IMG_DECLARE(injury);
LV_IMG_DECLARE(injuryh);

LV_IMG_DECLARE(voc);
LV_IMG_DECLARE(voc_red);
LV_IMG_DECLARE(voc_green);
LV_IMG_DECLARE(alti);
LV_IMG_DECLARE(alti_red);
LV_IMG_DECLARE(alti_green);
LV_IMG_DECLARE(aqi);
LV_IMG_DECLARE(aqi_red);
LV_IMG_DECLARE(aqi_green);

// Image Declarations for Ambient Temp
LV_IMG_DECLARE(amb_pressure);
LV_IMG_DECLARE(amb_pressure_red);
LV_IMG_DECLARE(amb_pressure_green);
LV_IMG_DECLARE(amb_temp);
LV_IMG_DECLARE(amb_temp_red);
LV_IMG_DECLARE(amb_temp_green);
LV_IMG_DECLARE(humidity);
LV_IMG_DECLARE(humidity_red);
LV_IMG_DECLARE(humidity_green);
LV_IMG_DECLARE(CO_ic);
LV_IMG_DECLARE(H2S_ic);
LV_IMG_DECLARE(HCs_ic);
LV_IMG_DECLARE(IAQ_ic);
LV_IMG_DECLARE(ambient_noise);
LV_IMG_DECLARE(gaussian_mag);

LV_IMG_DECLARE(blade);
LV_IMG_DECLARE(chat);
LV_IMG_DECLARE(battery_empty);
LV_IMG_DECLARE(Settings);

LV_IMG_DECLARE(compass);

LV_IMG_DECLARE(help);
LV_IMG_DECLARE(help_green);
LV_IMG_DECLARE(yes);
LV_IMG_DECLARE(yes_green);
LV_IMG_DECLARE(no);
LV_IMG_DECLARE(no_green);

LV_IMG_DECLARE(pending);
LV_IMG_DECLARE(pending_green);
LV_IMG_DECLARE(resolved);
LV_IMG_DECLARE(resolved_green);
LV_IMG_DECLARE(emergency);
LV_IMG_DECLARE(emergency_green);

extern lv_obj_t *page_2;
static lv_obj_t *text_p2_contact_body_temp, *text_p2_respiration_rate, *text_step_count;
extern byte text_p2_contact_body_temp_value, text_p2_respiration_rate_value, text_p2_heartrate_value, text_p2_spo2_value, text_p2_heartrateV_value;
extern int step_count_value;
extern int tilt_value;

extern bool p2_holder_flag;

extern bool p2_health_btn_3_flag;
extern bool p2_health_btn_2_flag;
extern bool p2_health_btn_1_flag;

extern bool p2_truama_btn_1_flag;

extern bool p2_ambient_temp_btn_1_flag;
extern bool p2_ambient_temp_btn_2_flag;
extern bool p2_ambient_temp_btn_3_flag;
extern bool p2_ambient_temp_btn_4_flag;

static lv_obj_t *logo_img, *health_btn, *ambient_temp_btn_p2;
static lv_obj_t *gContainer_p2_main, *trauma_btn, *profile_btn, *arrow_down_btn, *arrow_up_button;
static lv_obj_t *gContainer_p2_holder, *gContainer_p2_health_btn, *gContainer_p2_trauma_btn_temp_btn_p2, *gContainer_p2_profile_btn;
static lv_obj_t *gContainer_p_2_holder, *gContainer_p11, *gContainer_p15, *gContainer_p12, *gContainer_p13;
static lv_obj_t *contact_body_temp_btn, *respiration_rate_btn;
static lv_obj_t *incative_btn, *active_btn, *highly_active_btn;
static lv_obj_t *heartrateV_ic, *spo2_ic, *heartrate_ic, *text_p2_heartrateV, *text_p2_spo2, *text_p2_heartrate;
static lv_obj_t *shockwave_btn, *falldamage_btn, *injury_btn, *gContainer_p2_trauma_btn;
static lv_obj_t *aqi_btn, *alti_btn, *voc_btn, *gContainer_p2_ambient_temp_btn, *text_aqi, *text_voc, *text_alti, *direction_txt;

extern int text_aqi_value, text_alti_value;
extern float text_voc_value;

static lv_obj_t *CO_ic_btn, *H2S_ic_btn, *HCs_ic_btn, *IAQ_ic_btn;
static lv_obj_t *amb_pressure_btn, *amb_temp_btn, *humidity_btn, *text_humidity, *text_amb_temp, *text_amb_pressure;
extern byte text_humidity_value, text_amb_temp_value, text_amb_pressure_value;

static lv_obj_t *amb_noise_btn, *gaussian_mag_btn;

static lv_obj_t  *name_text,*age_text,*gender_text, *blood_grp_text;
static lv_obj_t *blade_ic, *chat_ic, *battery_empty_ic, *settings_ic , *compass_ic;
static lv_obj_t  *battery_text,*percentage_text_1,*battery_health_text, *percentage_text_2, *time_charge_text, *time_discharge_text;
static lv_obj_t *help_btn, *yes_btn, *no_btn;
static lv_obj_t *pending_btn, *resolved_btn, *emergency_btn;

void inflate_p2_health_btn_3();
void click_event_p2(lv_obj_t *obj, lv_event_t event);
void page_2_init();

// Health Buttons
void inflate_p2_health_btn_1();
void inflate_p2_health_btn_2();

// Ambient Temp Buttons
void inflate_p2_ambient_temp_btn_1();
void dynamic_p2_ambient_temp_btn_1();

void inflate_p2_ambient_temp_btn_2();
void dynamic_p2_ambient_temp_btn_2();

void inflate_p2_ambient_temp_btn_3();
void inflate_p2_ambient_temp_btn_4();

// Profile
void inflate_p2_profile_btn();

// Trauma
void inflate_p2_trauma_btn_1();

void inflate_p2_holder();
void inflate_p_2_btn();

void inflate_p2_compass();
void inflate_p15_btn();
void inflate_p12_btn();
void inflate_p13_btn();

void dynamic_p2_health_btn_1();
void dynamic_p2_health_btn_3();

#endif
