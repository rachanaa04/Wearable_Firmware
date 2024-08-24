#include "pages.h"
#include "config.h"

byte health_val = 50;
byte injuryh_val = 5;
byte ambient_temp_val = 30;
lv_obj_t *page_1=nullptr;
int hour = 5;
int minute = 35;
int month = 7;
int date = 25;
int year = 2024;
int day = 5;

bool p1_main_flag=false;

void click_event_p1(lv_obj_t *obj, lv_event_t event){
           
    if(obj==healthring_btn){
        Serial.println("healthring_btn");
        lv_label_set_text(healthring_text, stringToConstChar(String(health_val++)+ "%"));
    }
    
    else if(obj==injuryh_btn){
        Serial.println("injuryh_btn");
        lv_label_set_text(injuryh_text, stringToConstChar(String(injuryh_val++)+ "%"));
    }
    
    else if(obj==ambient_temp_btn_p1){
        Serial.println("ambient_temp_btn_p1");
        lv_label_set_text(ambient_temp_text, stringToConstChar(String(ambient_temp_val++)+ "C"));
    }
    else if(obj==battery && event==LV_EVENT_RELEASED){
        Serial.println("others");
        p1_main_flag=false;
        page_2_init();
        lv_scr_load(page_2);
        Serial.println("cleaned");
    }
    delay(25);
}


const char *stringToConstChar(String str) {
    // Allocate memory for the character array
    char *result = (char *)malloc(str.length() + 1);

    // Check if memory allocation succeeded
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    // Copy the contents of the String to the character array
    strcpy(result, str.c_str());

    // Return the constant character array
    return result;
}

void dynamic_p1_main(){

    lv_label_set_text(healthring_text, stringToConstChar(String(health_val)+ "%"));
    lv_label_set_text(injuryh_text, stringToConstChar(String(injuryh_val)+ "%"));
    lv_label_set_text(ambient_temp_text, stringToConstChar(String(ambient_temp_val)+ "C"));
    
}

void page_1_init() {
  
    // lv_obj_set_event_cb(page_1, swipe_event_cb_p1);
  
    p1_main_flag=true;

    static lv_style_t big_text_style;
        lv_style_init(&big_text_style);
        lv_style_set_text_color(&big_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        lv_style_set_bg_color(&big_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
        lv_style_set_text_font(&big_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_28);

    static lv_style_t small_text_style;
        lv_style_init(&small_text_style);
        lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
        // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
        lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    static lv_style_t cont_style;
        lv_style_init(&cont_style); 
        lv_style_set_border_width(&cont_style, LV_OBJ_PART_MAIN, 0);
        lv_style_set_bg_color(&cont_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
        lv_style_set_radius(&cont_style, LV_STATE_DEFAULT, 0);

    page_1 = lv_obj_create(NULL, NULL);
    
    gContainer_p1 = lv_cont_create(page_1, NULL);
        lv_obj_set_size(gContainer_p1,  LV_HOR_RES, LV_VER_RES);
        lv_obj_add_style(gContainer_p1, LV_OBJ_PART_MAIN, &cont_style);
        
    logo_img = lv_img_create(gContainer_p1,NULL);
        lv_img_set_src(logo_img, &logo);
        lv_obj_align(logo_img, page_1, LV_ALIGN_IN_TOP_RIGHT, -25, 25);
  
    time_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(time_text, stringToConstChar(String(hour) + ":" + String(minute) + "AM"));
        lv_obj_add_style(time_text, LV_OBJ_PART_MAIN, &big_text_style);
        lv_obj_align(time_text, gContainer_p1, LV_ALIGN_IN_TOP_LEFT, 15, 15);

    date_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(date_text, stringToConstChar(String(date) + "/" + String(month) + "/" + String(year)));
        lv_obj_add_style(date_text, LV_OBJ_PART_MAIN, &big_text_style);
        lv_obj_align(date_text, time_text, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    day_text = lv_label_create(gContainer_p1, NULL);
        day_label_text(day);
        // lv_label_set_text(day_text, "DAY");
        lv_obj_add_style(day_text, LV_OBJ_PART_MAIN, &big_text_style);
        lv_obj_align(day_text, date_text, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);

    location_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(location_text, "PUNE");
        lv_obj_add_style(location_text, LV_OBJ_PART_MAIN, &big_text_style);
        lv_obj_align(location_text, day_text, LV_ALIGN_OUT_RIGHT_MID, 50, 0);

    // healthring_btn = lv_imgbtn_create(gContainer_p1, NULL);
    //     lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_RELEASED, &healthring);
    //     lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_PRESSED, &healthring);
    //     lv_obj_align(healthring_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_LEFT, 20, -55);
    //     lv_obj_set_event_cb(healthring_btn, click_event_p1);

    if(health_val <= 40){

        healthring_btn = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_RELEASED, &healthring_red);
            lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_PRESSED, &healthring_red);
            lv_obj_align(healthring_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_LEFT, 20, -55);
            lv_obj_set_event_cb(healthring_btn, click_event_p1);
    }

    if(health_val > 40){

        healthring_btn = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_RELEASED, &healthring);
            lv_imgbtn_set_src(healthring_btn, LV_BTN_STATE_PRESSED, &healthring);
            lv_obj_align(healthring_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_LEFT, 20, -55);
            lv_obj_set_event_cb(healthring_btn, click_event_p1);
    }

    // injuryh_btn = lv_imgbtn_create(gContainer_p1, NULL);
    //     lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_RELEASED, &injuryh);
    //     lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_PRESSED, &injuryh);
    //     lv_obj_align(injuryh_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_MID, 0, -55);
    //     lv_obj_set_event_cb(injuryh_btn, click_event_p1);

    if(injuryh_val <= 25){

        injuryh_btn = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_RELEASED, &injuryh_green);
            lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_PRESSED, &injuryh_green);
            lv_obj_align(injuryh_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_MID, 0, -55);
            lv_obj_set_event_cb(injuryh_btn, click_event_p1);
    }

    if(injuryh_val > 25){

        injuryh_btn = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_RELEASED, &injuryh_red);
            lv_imgbtn_set_src(injuryh_btn, LV_BTN_STATE_PRESSED, &injuryh_red);
            lv_obj_align(injuryh_btn, gContainer_p1, LV_ALIGN_IN_BOTTOM_MID, 0, -55);
            lv_obj_set_event_cb(injuryh_btn, click_event_p1);
    }

    // ambient_temp_btn_p1 = lv_imgbtn_create(gContainer_p1, NULL);
    //     lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_RELEASED, &ambient);
    //     lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_PRESSED, &ambient);
    //     lv_obj_align(ambient_temp_btn_p1, gContainer_p1, LV_ALIGN_IN_BOTTOM_RIGHT, -20, -55);
    //     lv_obj_set_event_cb(ambient_temp_btn_p1, click_event_p1);

    if(ambient_temp_val <= 40){

        ambient_temp_btn_p1 = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_RELEASED, &ambient_green);
            lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_PRESSED, &ambient_green);
            lv_obj_align(ambient_temp_btn_p1, gContainer_p1, LV_ALIGN_IN_BOTTOM_RIGHT, -20, -55);
            lv_obj_set_event_cb(ambient_temp_btn_p1, click_event_p1);   
    }

    if(ambient_temp_val > 40){

        ambient_temp_btn_p1 = lv_imgbtn_create(gContainer_p1, NULL);
            lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_RELEASED, &ambient_red);
            lv_imgbtn_set_src(ambient_temp_btn_p1, LV_BTN_STATE_PRESSED, &ambient_red);
            lv_obj_align(ambient_temp_btn_p1, gContainer_p1, LV_ALIGN_IN_BOTTOM_RIGHT, -20, -55);
            lv_obj_set_event_cb(ambient_temp_btn_p1, click_event_p1);   
    }
    
    battery = lv_imgbtn_create(gContainer_p1, NULL);
        lv_imgbtn_set_src(battery, LV_BTN_STATE_RELEASED, &batterygfinal);
        lv_imgbtn_set_src(battery, LV_BTN_STATE_PRESSED, &batterygfinal);
        lv_obj_align(battery, gContainer_p1, LV_ALIGN_IN_BOTTOM_MID, 0, 5);
        lv_obj_set_event_cb(battery, click_event_p1);

    healthring_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(healthring_text,stringToConstChar(String(health_val)+"%" ));
        lv_obj_add_style(healthring_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(healthring_text, healthring_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    injuryh_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(injuryh_text, stringToConstChar(String(injuryh_val)+"%"));
        lv_obj_add_style(injuryh_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(injuryh_text, injuryh_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    ambient_temp_text = lv_label_create(gContainer_p1, NULL);
        lv_label_set_text(ambient_temp_text, stringToConstChar(String(ambient_temp_val)+ "C"));
        lv_obj_add_style(ambient_temp_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(ambient_temp_text, ambient_temp_btn_p1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

void day_label_text(int day){

    if(day == 0){
        lv_label_set_text(day_text, "SUN");
    }

    else if(day == 1){
        lv_label_set_text(day_text, "MON");
    }

    else if(day == 2){
        lv_label_set_text(day_text, "TUE");
    }

    else if(day == 3){
        lv_label_set_text(day_text, "WED");
    }

    else if(day == 4){
        lv_label_set_text(day_text, "THRS");
    }

    else if(day == 5){
        lv_label_set_text(day_text, "FRI");
    }

    else if(day == 6){
        lv_label_set_text(day_text, "SAT");
    }
}