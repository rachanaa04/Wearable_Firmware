#include "pages.h"
#include "config.h"

lv_obj_t *page_2 = nullptr;
// byte text_p2_val=1;
byte text_p2_contact_body_temp_value = 36, text_p2_respiration_rate_value = 14, text_p2_heartrate_value = 82, text_p2_spo2_value = 96, text_p2_heartrateV_value = 42;

//ambient btn screen 1 content
int text_aqi_value=130, text_alti_value=850;
float text_voc_value=2;
int step_count_value=0;
int tilt_value = 0;

//ambient btn screen 2 content
byte text_humidity_value=42, text_amb_temp_value=66, text_amb_pressure_value=1;

bool p2_holder_flag = false;
bool p_2_page_flag=false;

bool p2_health_btn_1_flag = false;
bool p2_health_btn_2_flag = false;
bool p2_health_btn_3_flag = false;

bool p2_truama_btn_1_flag = false;

bool p2_ambient_temp_btn_1_flag = false;
bool p2_ambient_temp_btn_2_flag = false;
bool p2_ambient_temp_btn_3_flag = false;
bool p2_ambient_temp_btn_4_flag = false;

bool p2_profile_btn = false;
bool p2_compass_btn_flag = false;
bool p2_page15_flag = false;
bool p2_page12_flag = false;
bool p2_page13_flag = false;

// static lv_obj_t  *gContainer_p2_holder,*gContainer_p2_health_btn,*gContainer_p2_ambient_temp_btn_p2,*gContainer_p2_profile_btn, *gContainer_p2_trauma_btn;

// Health: Screen 1 content
void dynamic_p2_health_btn_1()
{
    Serial.println("inside fn");
    lv_label_set_text(text_p2_contact_body_temp, stringToConstChar(String(text_p2_contact_body_temp_value) + " C"));
    lv_label_set_text(text_p2_respiration_rate, stringToConstChar(String(text_p2_respiration_rate_value) + " bpm"));
}

// Health: Screen 3 content
void dynamic_p2_health_btn_3()
{
    Serial.println("inside 3 fn");
    lv_label_set_text(text_p2_heartrate, stringToConstChar(String(text_p2_heartrate_value) + "bpm"));
    lv_label_set_text(text_p2_spo2, stringToConstChar(String(text_p2_spo2_value) + "%"));
    lv_label_set_text(text_p2_heartrateV, stringToConstChar(String(text_p2_heartrateV_value) + "ms"));
}

//ambient: screen 1 content
void dynamic_p2_ambient_temp_btn_1(){
    lv_label_set_text(text_alti, stringToConstChar(String(text_alti_value) + "ft"));
    lv_label_set_text(text_aqi, stringToConstChar(String(text_aqi_value) ));
    lv_label_set_text(text_voc, stringToConstChar(String(text_voc_value) + "mg"));

}

//ambient: screen 2 content
void dynamic_p2_ambient_temp_btn_2(){
    lv_label_set_text(text_humidity, stringToConstChar(String(text_humidity_value) + "%"));
    lv_label_set_text(text_amb_temp, stringToConstChar(String(text_amb_temp_value) +"C"));
    lv_label_set_text(text_amb_pressure, stringToConstChar(String(text_amb_pressure_value) + "atm"));
}

void click_event_p2(lv_obj_t *obj, lv_event_t event)
{
    if (event != LV_BTN_STATE_RELEASED)  return;

    else if(obj == logo_img)
     {
            page_1_init();
            lv_scr_load(page_1); 
     }
    else if (obj == health_btn && p2_holder_flag){

        p2_holder_flag = false;
        inflate_p2_health_btn_1();
        lv_obj_clean(gContainer_p2_holder);
    }

    else if (obj == trauma_btn && p2_holder_flag){

        p2_holder_flag = false;
        inflate_p2_trauma_btn_1();
    }

    else if (obj == ambient_temp_btn_p2 && p2_holder_flag){

        p2_holder_flag = false;
        inflate_p2_ambient_temp_btn_1();
    }

    else if(obj == profile_btn && p2_holder_flag){

        p2_holder_flag = false;
        inflate_p2_profile_btn();
    }

    else if(obj == blade_ic && p_2_page_flag){

        p_2_page_flag = false;
        inflate_p2_compass();
    }

    else if(obj == battery_empty_ic && p_2_page_flag){

        p_2_page_flag = false;
        inflate_p15_btn();
    }

    else if(obj == chat_ic && p_2_page_flag){

        p_2_page_flag = false;
        inflate_p12_btn();
    }

    else if(obj == help_btn)
    {
        help_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_imgbtn_set_src(help_btn, LV_BTN_STATE_RELEASED, &help_green);
        lv_imgbtn_set_src(help_btn, LV_BTN_STATE_PRESSED, &help_green);
        lv_obj_set_event_cb(help_btn, click_event_p2);
        lv_obj_align(help_btn, gContainer_p12, LV_ALIGN_IN_TOP_MID, 0, 10);
    }

    else if(obj == yes_btn)
    {
        yes_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_obj_align(yes_btn, help_btn,LV_ALIGN_IN_TOP_LEFT, 0, 50);
        lv_obj_set_event_cb(yes_btn, click_event_p2);
        lv_imgbtn_set_src(yes_btn, LV_BTN_STATE_RELEASED, &yes_green);
        lv_imgbtn_set_src(yes_btn, LV_BTN_STATE_PRESSED, &yes_green);
    }
   else if(obj == no_btn)
   {
        no_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_imgbtn_set_src(no_btn, LV_BTN_STATE_RELEASED, &no_green);
        lv_imgbtn_set_src(no_btn, LV_BTN_STATE_PRESSED, &no_green);
        lv_obj_align(no_btn, help_btn,LV_ALIGN_IN_TOP_MID, 0, 100);
        lv_obj_set_event_cb(no_btn, click_event_p2);
   }
   else if(obj == pending_btn)
   {
        pending_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(pending_btn, LV_BTN_STATE_RELEASED, &pending_green);
        lv_imgbtn_set_src(pending_btn, LV_BTN_STATE_PRESSED, &pending_green);
        lv_obj_align(pending_btn, gContainer_p13, LV_ALIGN_IN_TOP_LEFT, 0, 9);
        lv_obj_set_event_cb(pending_btn, click_event_p2);
   }

   else if(obj == resolved_btn)
   {
        resolved_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(resolved_btn, LV_BTN_STATE_RELEASED, &resolved_green);
        lv_imgbtn_set_src(resolved_btn, LV_BTN_STATE_PRESSED, &resolved_green);
        lv_obj_align(resolved_btn, pending_btn,LV_ALIGN_IN_TOP_MID, 0, 49);
        lv_obj_set_event_cb(resolved_btn, click_event_p2);
   }

   else if(obj == emergency_btn)
{
     emergency_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(emergency_btn, LV_BTN_STATE_RELEASED, &emergency_green);
        lv_imgbtn_set_src(emergency_btn, LV_BTN_STATE_PRESSED, &emergency_green);
        lv_obj_align(emergency_btn, gContainer_p12, LV_ALIGN_IN_TOP_MID, 0, 109);   
        lv_obj_set_event_cb(emergency_btn, click_event_p2);
}
    else if (obj == arrow_up_button)
    {
        // check the flags
        if (p2_holder_flag)
        {
            p2_holder_flag = false;
            page_1_init();
            lv_scr_load(page_1);
        }
        else if (p2_health_btn_1_flag || p2_truama_btn_1_flag || p2_ambient_temp_btn_1_flag)
        {
            p2_health_btn_1_flag = false;
            p2_truama_btn_1_flag = false;
            p2_ambient_temp_btn_1_flag = false;

            inflate_p2_holder();
        }

        // Move from health screen 2 to screen 1
        else if (p2_health_btn_2_flag)
        {
            p2_health_btn_2_flag = false;

            inflate_p2_health_btn_1();
        }

        // Move from health screen 3 to screen 2
        else if (p2_health_btn_3_flag)
        {
            p2_health_btn_3_flag = false;

            inflate_p2_health_btn_2();
        }

        // Move from Ambient temp Screen 2 to Screen 1
        else if (p2_ambient_temp_btn_2_flag)
        {
            p2_ambient_temp_btn_2_flag = false;
            inflate_p2_ambient_temp_btn_1();
        }

        // Move from Ambient temp screen 3 to screen 2
        else if (p2_ambient_temp_btn_3_flag)
        {
            p2_ambient_temp_btn_3_flag = false;
            inflate_p2_ambient_temp_btn_2();
        }
        // Move from Ambient temp screen 4 to screen 3
        else if (p2_ambient_temp_btn_4_flag)
        {
            p2_ambient_temp_btn_4_flag = false;
            inflate_p2_ambient_temp_btn_3();
        }
        
        else if (p2_holder_flag)
        {
            p2_holder_flag = false;
            page_1_init();
            lv_scr_load(page_1);
        }

        // Move from health screen to Main holder
        else if (p2_health_btn_1_flag)
        {
            p2_health_btn_1_flag = false;
            gContainer_p2_health_btn = nullptr;
            inflate_p2_holder();
        }

        else if (p2_truama_btn_1_flag)
        {
            p2_truama_btn_1_flag = false;
            gContainer_p2_trauma_btn = nullptr;
            inflate_p2_holder();
        }

        // Move from Ambient temp Screen 1 to Main holder
        else if (p2_ambient_temp_btn_1_flag)
        {
            p2_ambient_temp_btn_1_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_holder();
        }

        // Move from health screen 2 to Main holder
        else if (p2_health_btn_2_flag)
        {
            p2_health_btn_2_flag = false;
            gContainer_p2_health_btn = nullptr;
            inflate_p2_holder();
        }
        else if (p2_health_btn_3_flag)
        {
            p2_health_btn_3_flag = false;
            gContainer_p2_health_btn = nullptr;
            inflate_p2_holder();
        }

        else if (p2_ambient_temp_btn_2_flag)
        {
            p2_ambient_temp_btn_2_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_holder();
        }

        else if (p2_ambient_temp_btn_3_flag)
        {
            p2_ambient_temp_btn_3_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_holder();
        }
        else if (p2_ambient_temp_btn_4_flag)
        {
            p2_ambient_temp_btn_4_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_holder();
        }

        else if(p2_profile_btn){

            p2_profile_btn = false;
            gContainer_p2_profile_btn = nullptr;
            inflate_p2_holder();
        }

        else if(p_2_page_flag){

            p_2_page_flag=false;
            gContainer_p_2_holder = nullptr;
            inflate_p2_holder();
        }


        else if(p2_compass_btn_flag){

            p2_compass_btn_flag = false;
            gContainer_p11 = nullptr;
            inflate_p_2_btn();
        }

        else if(p2_page15_flag){

            p2_page15_flag = false;
            gContainer_p15 = nullptr;
            inflate_p_2_btn();
        }

        else if(p2_page12_flag){

            p2_page12_flag = false;
            gContainer_p12 = nullptr;
            inflate_p_2_btn();
        }

        else if(p2_page13_flag){

            p2_page13_flag = false;
            gContainer_p13 = nullptr;
            inflate_p12_btn;
        }
    }

    else if (obj == arrow_down_btn)
    {
        // check the flags
        //  Move from health screen 1 to screen 2
        if (p2_health_btn_1_flag)
        {
            p2_health_btn_1_flag = false;
            inflate_p2_health_btn_2();
        }

        // Move from health screen 2 to screen 3
        else if (p2_health_btn_2_flag)
        {
            p2_health_btn_2_flag = false;
            gContainer_p2_health_btn = nullptr;
            inflate_p2_health_btn_3();
        }
        // Move from Ambient temp Screen 1 to Screen 2
        else if (p2_ambient_temp_btn_1_flag)
        {
            p2_ambient_temp_btn_1_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_ambient_temp_btn_2();
        }

        // Move from Ambient temp Screen 2 to Screen 3
        else if (p2_ambient_temp_btn_2_flag)
        {
            p2_ambient_temp_btn_2_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_ambient_temp_btn_3();
        }

        // Move from Ambient temp Screen 3 to Screen 4
        else if (p2_ambient_temp_btn_3_flag)
        {
            p2_ambient_temp_btn_3_flag = false;
            gContainer_p2_ambient_temp_btn = nullptr;
            inflate_p2_ambient_temp_btn_4();
        }

        else if(p2_holder_flag){

            p2_holder_flag = false;
            gContainer_p_2_holder = nullptr;
            inflate_p_2_btn();
        }

        else if(p2_page12_flag){

            p2_page12_flag = false;
            gContainer_p12 = nullptr;
            inflate_p13_btn();
        }
    }
}


// Health: Screen 1 : Body temperatory and respiration rate
void inflate_p2_health_btn_1()
{
    p2_health_btn_1_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_14);

    gContainer_p2_health_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_health_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_health_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_health_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    // contact_body_temp_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    // lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_RELEASED, &contactbodytemp);
    // lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_PRESSED, &contactbodytemp);
    // lv_obj_align(contact_body_temp_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_MID, 0, 5);
    // lv_obj_set_event_cb(contact_body_temp_btn, click_event_p2);

    if(text_p2_contact_body_temp_value <= 40){

        contact_body_temp_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
            lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_RELEASED, &contactbodytemp_green);
            lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_PRESSED, &contactbodytemp_green);
            lv_obj_align(contact_body_temp_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_MID, 0, 2);
            lv_obj_set_event_cb(contact_body_temp_btn, click_event_p2);
    }

    if(text_p2_contact_body_temp_value > 40){

        contact_body_temp_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
            lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_RELEASED, &contactbodytemp_red);
            lv_imgbtn_set_src(contact_body_temp_btn, LV_BTN_STATE_PRESSED, &contactbodytemp_red);
            lv_obj_align(contact_body_temp_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_MID, 0, 2);
            lv_obj_set_event_cb(contact_body_temp_btn, click_event_p2);
    }

    if(text_p2_contact_body_temp_value <= 18 || text_p2_contact_body_temp_value >=12){

        respiration_rate_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_RELEASED, &respiration_rate_green);
        lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_PRESSED, &respiration_rate_green);
        lv_obj_align(respiration_rate_btn, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
        lv_obj_set_event_cb(respiration_rate_btn, click_event_p2);
    }

    if(text_p2_contact_body_temp_value > 18 || text_p2_contact_body_temp_value < 12){

        respiration_rate_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_RELEASED, &respiration_rate_red);
        lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_PRESSED, &respiration_rate_red);
        lv_obj_align(respiration_rate_btn, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
        lv_obj_set_event_cb(respiration_rate_btn, click_event_p2);
    }

    // respiration_rate_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    // lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_RELEASED, &respiration_rate);
    // lv_imgbtn_set_src(respiration_rate_btn, LV_BTN_STATE_PRESSED, &respiration_rate);
    // lv_obj_align(respiration_rate_btn, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -23);
    // lv_obj_set_event_cb(respiration_rate_btn, click_event_p2);

    text_p2_contact_body_temp = lv_label_create(gContainer_p2_health_btn, NULL);
    //lv_label_set_text(text_p2_contact_body_temp, "36C");
    lv_label_set_text(text_p2_contact_body_temp, stringToConstChar(String(text_p2_contact_body_temp_value) + " C"));
    lv_obj_add_style(text_p2_contact_body_temp, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_p2_contact_body_temp, contact_body_temp_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    text_p2_respiration_rate = lv_label_create(gContainer_p2_health_btn, NULL);
    //lv_label_set_text(text_p2_respiration_rate, "12bpm");
    lv_label_set_text(text_p2_respiration_rate, stringToConstChar(String(text_p2_respiration_rate_value) + " bpm"));
    lv_obj_add_style(text_p2_respiration_rate, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_p2_respiration_rate, respiration_rate_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

// Health: Screen 2 : inactive, active, and highly active
void inflate_p2_health_btn_2()
{
    p2_health_btn_2_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_14);

    gContainer_p2_health_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_health_btn, 160, 160);
    lv_obj_add_style(gContainer_p2_health_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_health_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    incative_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    lv_imgbtn_set_src(incative_btn, LV_BTN_STATE_RELEASED, &inactive);
    lv_imgbtn_set_src(incative_btn, LV_BTN_STATE_PRESSED, &inactive);
    lv_obj_align(incative_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    lv_obj_set_event_cb(incative_btn, click_event_p2);

    active_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    lv_imgbtn_set_src(active_btn, LV_BTN_STATE_RELEASED, &active);
    lv_imgbtn_set_src(active_btn, LV_BTN_STATE_PRESSED, &active);
    lv_obj_align(active_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_RIGHT, 9, -9);
    lv_obj_set_event_cb(active_btn, click_event_p2);

    text_step_count = lv_label_create(gContainer_p2_health_btn, NULL);
    lv_label_set_text(text_step_count, stringToConstChar(String(step_count_value)));
    lv_obj_add_style(text_step_count, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_step_count, active_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

    highly_active_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    lv_imgbtn_set_src(highly_active_btn, LV_BTN_STATE_RELEASED, &highly_active);
    lv_imgbtn_set_src(highly_active_btn, LV_BTN_STATE_PRESSED, &highly_active);
    lv_obj_align(highly_active_btn, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -5);
    lv_obj_set_event_cb(highly_active_btn, click_event_p2);
}

// Health: Screen 3 : Heartrate, SpO2, and Heartrate Variability
void inflate_p2_health_btn_3()
{
    p2_health_btn_3_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p2_health_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_health_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_health_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_health_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_14);

    // heartrate_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    // lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_RELEASED, &heartrate);
    // lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_PRESSED, &heartrate);
    // lv_obj_align(heartrate_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_LEFT, 0, 0);

    if(text_p2_heartrate_value >= 70 || text_p2_heartrate_value <= 120){

        heartrate_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_RELEASED, &heartrate_green);
        lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_PRESSED, &heartrate_green);
        lv_obj_align(heartrate_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    }

    if(text_p2_heartrate_value < 70 || text_p2_heartrate_value > 120){

        heartrate_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_RELEASED, &heartrate_red);
        lv_imgbtn_set_src(heartrate_ic, LV_BTN_STATE_PRESSED, &heartrate_red);
        lv_obj_align(heartrate_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_LEFT, 0, 0);
    }

    text_p2_heartrate = lv_label_create(gContainer_p2_health_btn, NULL);
    // lv_label_set_text(text_p2_heartrate, "50bpm");
    lv_label_set_text(text_p2_heartrate, stringToConstChar(String(text_p2_heartrate_value) + "bpm"));
    lv_obj_add_style(text_p2_heartrate, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_p2_heartrate, heartrate_ic, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

    // spo2_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    // lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_RELEASED, &spO2);
    // lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_PRESSED, &spO2);
    // lv_obj_align(spo2_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_RIGHT, 10, -10);

    if(text_p2_spo2_value <= 100){

        spo2_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_RELEASED, &spO2_green);
        lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_PRESSED, &spO2_green);
        lv_obj_align(spo2_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_RIGHT, 8, -8);
    }

    if(text_p2_spo2_value > 100){

        spo2_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_RELEASED, &spO2_red);
        lv_imgbtn_set_src(spo2_ic, LV_BTN_STATE_PRESSED, &spO2_red);
        lv_obj_align(spo2_ic, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_RIGHT, 8, -8);
    }

    text_p2_spo2 = lv_label_create(gContainer_p2_health_btn, NULL);
    // lv_label_set_text(text_p2_spo2, "96%");
    lv_label_set_text(text_p2_spo2, stringToConstChar(String(text_p2_spo2_value) + "%"));
    lv_obj_add_style(text_p2_spo2, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_p2_spo2, spo2_ic, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);

    // heartrateV_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    // lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_RELEASED, &heartrateV);
    // lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_PRESSED, &heartrateV);
    // lv_obj_align(heartrateV_ic, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

    if(text_p2_heartrateV_value <= 60){

        heartrateV_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_RELEASED, &heartrateV_green);
        lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_PRESSED, &heartrateV_green);
        lv_obj_align(heartrateV_ic, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -13);
    }

    if(text_p2_heartrateV_value > 60){

        heartrateV_ic = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
        lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_RELEASED, &heartrateV_red);
        lv_imgbtn_set_src(heartrateV_ic, LV_BTN_STATE_PRESSED, &heartrateV_red);
        lv_obj_align(heartrateV_ic, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -13);
    }

    text_p2_heartrateV = lv_label_create(gContainer_p2_health_btn, NULL);
    // lv_label_set_text(text_p2_heartrateV, "50bpm");
    lv_label_set_text(text_p2_heartrateV, stringToConstChar(String(text_p2_heartrateV_value) + "ms"));
    lv_obj_add_style(text_p2_heartrateV, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_p2_heartrateV, heartrateV_ic, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

// Ambient Temp: Screen 1 : AQI, Altitude, and VOC
void inflate_p2_ambient_temp_btn_1()
{
    p2_ambient_temp_btn_1_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_14);

    gContainer_p2_ambient_temp_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_ambient_temp_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_ambient_temp_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_ambient_temp_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    // aqi_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_RELEASED, &aqi);
    // lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_PRESSED, &aqi);
    // lv_obj_align(aqi_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -18);
    // lv_obj_set_event_cb(aqi_btn, click_event_p2);

    if(text_aqi_value <= 170){

        aqi_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_RELEASED, &aqi_green);
        lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_PRESSED, &aqi_green);
        lv_obj_align(aqi_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -15);
        lv_obj_set_event_cb(aqi_btn, click_event_p2);
    }

    if(text_aqi_value > 170){

        aqi_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_RELEASED, &aqi_red);
        lv_imgbtn_set_src(aqi_btn, LV_BTN_STATE_PRESSED, &aqi_red);
        lv_obj_align(aqi_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -15);
        lv_obj_set_event_cb(aqi_btn, click_event_p2);
    }

    text_aqi = lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_label_set_text(text_aqi, "58");
    lv_label_set_text(text_aqi, stringToConstChar(String(text_aqi_value) ));
    lv_obj_add_style(text_aqi, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_aqi, aqi_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    // alti_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_RELEASED, &alti);
    // lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_PRESSED, &alti);
    // lv_obj_align(alti_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 5, 5);
    // lv_obj_set_event_cb(alti_btn, click_event_p2);

    if(text_alti_value <= 1000){

        alti_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_RELEASED, &alti_green);
        lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_PRESSED, &alti_green);
        lv_obj_align(alti_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 5, 5);
        lv_obj_set_event_cb(alti_btn, click_event_p2);
    }

    if(text_alti_value > 1000){

        alti_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_RELEASED, &alti_red);
        lv_imgbtn_set_src(alti_btn, LV_BTN_STATE_PRESSED, &alti_red);
        lv_obj_align(alti_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 5, 5);
        lv_obj_set_event_cb(alti_btn, click_event_p2);
    }

    text_alti=lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_label_set_text(text_alti, "566 ft");
    lv_label_set_text(text_alti, stringToConstChar(String(text_alti_value) + "ft"));
    lv_obj_add_style(text_alti, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_alti, alti_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    // voc_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_RELEASED, &voc);
    // lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_PRESSED, &voc);
    // lv_obj_align(voc_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
    // lv_obj_set_event_cb(voc_btn, click_event_p2);

    if(text_voc_value <= 2.5){

        voc_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_RELEASED, &voc_green);
        lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_PRESSED, &voc_green);
        lv_obj_align(voc_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(voc_btn, click_event_p2);
    }

    if(text_voc_value > 2.5){

        voc_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_RELEASED, &voc_red);
        lv_imgbtn_set_src(voc_btn, LV_BTN_STATE_PRESSED, &voc_red);
        lv_obj_align(voc_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(voc_btn, click_event_p2);
    }

    text_voc=lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    //lv_label_set_text(text_voc, "2.5 mg");
    lv_label_set_text(text_voc, stringToConstChar(String(text_voc_value) + "mg"));
    lv_obj_add_style(text_voc, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_voc, voc_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

// Ambient Temp: Screen 2
void inflate_p2_ambient_temp_btn_2()
{
    p2_ambient_temp_btn_2_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    gContainer_p2_ambient_temp_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_ambient_temp_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_ambient_temp_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_ambient_temp_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    // amb_pressure_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_RELEASED, &amb_pressure);
    // lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_PRESSED, &amb_pressure);
    // lv_obj_align(amb_pressure_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
    // lv_obj_set_event_cb(amb_pressure_btn, click_event_p2);

    if(text_amb_pressure_value <= 1){

        amb_pressure_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_RELEASED, &amb_pressure_green);
        lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_PRESSED, &amb_pressure_green);
        lv_obj_align(amb_pressure_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
        lv_obj_set_event_cb(amb_pressure_btn, click_event_p2);
    }


    if(text_amb_pressure_value > 1){

        amb_pressure_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_RELEASED, &amb_pressure_red);
        lv_imgbtn_set_src(amb_pressure_btn, LV_BTN_STATE_PRESSED, &amb_pressure_red);
        lv_obj_align(amb_pressure_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
        lv_obj_set_event_cb(amb_pressure_btn, click_event_p2);
    }

    text_amb_pressure=lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_label_set_text(text_amb_pressure, "2.5 atm");
    lv_label_set_text(text_amb_pressure, stringToConstChar(String(text_amb_pressure_value) + "atm"));
    lv_obj_add_style(text_amb_pressure, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_amb_pressure, amb_pressure_btn, LV_ALIGN_OUT_BOTTOM_MID, 4, 0);

    // amb_temp_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_RELEASED, &amb_temp);
    // lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_PRESSED, &amb_temp);
    // lv_obj_align(amb_temp_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
    // lv_obj_set_event_cb(amb_temp_btn, click_event_p2);

    if(text_amb_temp_value <= 50){

        amb_temp_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_RELEASED, &amb_temp_green);
        lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_PRESSED, &amb_temp_green);
        lv_obj_align(amb_temp_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(amb_temp_btn, click_event_p2);
    }

    if(text_amb_temp_value > 50){

        amb_temp_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_RELEASED, &amb_temp_red);
        lv_imgbtn_set_src(amb_temp_btn, LV_BTN_STATE_PRESSED, &amb_temp_red);
        lv_obj_align(amb_temp_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(amb_temp_btn, click_event_p2);
    }

    text_amb_temp=lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_label_set_text(text_amb_temp, "25C");
    lv_label_set_text(text_amb_temp, stringToConstChar(String(text_amb_temp_value) +"C"));
    lv_obj_add_style(text_amb_temp, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_amb_temp, amb_temp_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    // humidity_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
    // lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_RELEASED, &humidity);
    // lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_PRESSED, &humidity);
    // lv_obj_align(humidity_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 10, 8);
    // lv_obj_set_event_cb(humidity_btn, click_event_p2);

    if(text_humidity_value <= 55){

        humidity_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_RELEASED, &humidity_green);
        lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_PRESSED, &humidity_green);
        lv_obj_align(humidity_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 10, 8);
        lv_obj_set_event_cb(humidity_btn, click_event_p2);
    }

    if(text_humidity_value > 55){

        humidity_btn = lv_imgbtn_create(gContainer_p2_ambient_temp_btn, NULL);
        lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_RELEASED, &humidity_red);
        lv_imgbtn_set_src(humidity_btn, LV_BTN_STATE_PRESSED, &humidity_red);
        lv_obj_align(humidity_btn, gContainer_p2_ambient_temp_btn, LV_ALIGN_IN_TOP_LEFT, 10, 8);
        lv_obj_set_event_cb(humidity_btn, click_event_p2);
    }

    text_humidity=lv_label_create(gContainer_p2_ambient_temp_btn, NULL);
    //lv_label_set_text(text_humidity, "20%");
    lv_label_set_text(text_humidity, stringToConstChar(String(text_humidity_value) + "%"));
    lv_obj_add_style(text_humidity, LV_OBJ_PART_MAIN, &small_text_style);
    lv_obj_align(text_humidity, humidity_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

// Ambient Screen 3:

void inflate_p2_ambient_temp_btn_3()
{
    p2_ambient_temp_btn_3_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p2_holder = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_holder, 165, 165);
    lv_obj_add_style(gContainer_p2_holder, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_holder, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    // HCs
    HCs_ic_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(HCs_ic_btn, LV_BTN_STATE_RELEASED, &HCs_ic);
    lv_imgbtn_set_src(HCs_ic_btn, LV_BTN_STATE_PRESSED, &HCs_ic);
    lv_obj_align(HCs_ic_btn, gContainer_p2_holder, LV_ALIGN_IN_TOP_LEFT, 10, 10);
    lv_obj_set_event_cb(HCs_ic_btn, click_event_p2);

    // Co Icon
    CO_ic_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(CO_ic_btn, LV_BTN_STATE_RELEASED, &CO_ic);
    lv_imgbtn_set_src(CO_ic_btn, LV_BTN_STATE_PRESSED, &CO_ic);
    lv_obj_align(CO_ic_btn, gContainer_p2_holder, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
    lv_obj_set_event_cb(CO_ic_btn, click_event_p2);

    // H2S Icon
    H2S_ic_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(H2S_ic_btn, LV_BTN_STATE_RELEASED, &H2S_ic);
    lv_imgbtn_set_src(H2S_ic_btn, LV_BTN_STATE_PRESSED, &H2S_ic);
    lv_obj_align(H2S_ic_btn, gContainer_p2_holder, LV_ALIGN_IN_BOTTOM_LEFT, 10, -10);
    lv_obj_set_event_cb(H2S_ic_btn, click_event_p2);

    // IAQ
    IAQ_ic_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(IAQ_ic_btn, LV_BTN_STATE_RELEASED, &IAQ_ic);
    lv_imgbtn_set_src(IAQ_ic_btn, LV_BTN_STATE_PRESSED, &IAQ_ic);
    lv_obj_align(IAQ_ic_btn, gContainer_p2_holder, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10);
    lv_obj_set_event_cb(IAQ_ic_btn, click_event_p2);
}

void inflate_p2_ambient_temp_btn_4()
{

    p2_ambient_temp_btn_4_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    gContainer_p2_health_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_health_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_health_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_health_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    amb_noise_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    lv_imgbtn_set_src(amb_noise_btn, LV_BTN_STATE_RELEASED, &ambient_noise);
    lv_imgbtn_set_src(amb_noise_btn, LV_BTN_STATE_PRESSED, &ambient_noise);
    lv_obj_align(amb_noise_btn, gContainer_p2_health_btn, LV_ALIGN_IN_TOP_MID, 0, 5);
    lv_obj_set_event_cb(amb_noise_btn, click_event_p2);

    gaussian_mag_btn = lv_imgbtn_create(gContainer_p2_health_btn, NULL);
    lv_imgbtn_set_src(gaussian_mag_btn, LV_BTN_STATE_RELEASED, &gaussian_mag);
    lv_imgbtn_set_src(gaussian_mag_btn, LV_BTN_STATE_PRESSED, &gaussian_mag);
    lv_obj_align(gaussian_mag_btn, gContainer_p2_health_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -23);
    lv_obj_set_event_cb(gaussian_mag_btn, click_event_p2);
}

// Profile: Screen 1 : Profile
void inflate_p2_profile_btn(){

    p2_profile_btn = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    gContainer_p2_profile_btn = lv_cont_create(gContainer_p2_main, NULL);
        lv_obj_set_size(gContainer_p2_profile_btn, 165, 165);
        lv_obj_add_style(gContainer_p2_profile_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
        lv_obj_align(gContainer_p2_profile_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    name_text = lv_label_create(gContainer_p2_profile_btn, NULL);
        lv_label_set_text(name_text, "Name:");
        lv_obj_add_style(name_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(name_text, gContainer_p2_profile_btn, LV_ALIGN_IN_TOP_LEFT, 10, 30);

    age_text = lv_label_create(gContainer_p2_profile_btn, NULL);
        lv_label_set_text(age_text, "Age:");
        lv_obj_add_style(age_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(age_text, name_text, LV_ALIGN_IN_TOP_LEFT, 0, 30);

    gender_text = lv_label_create(gContainer_p2_profile_btn, NULL);
        lv_label_set_text(gender_text, "Gender:");
        lv_obj_add_style(gender_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(gender_text, age_text, LV_ALIGN_IN_TOP_LEFT, 0, 30);

    blood_grp_text = lv_label_create(gContainer_p2_profile_btn, NULL);
        lv_label_set_text(blood_grp_text, "Blood group:");
        lv_obj_add_style(blood_grp_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(blood_grp_text, gender_text, LV_ALIGN_IN_TOP_LEFT, 0, 30);
}

void inflate_p2_trauma_btn_1()
{
    p2_truama_btn_1_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p2_trauma_btn = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_trauma_btn, 165, 165);
    lv_obj_add_style(gContainer_p2_trauma_btn, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_trauma_btn, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    shockwave_btn = lv_imgbtn_create(gContainer_p2_trauma_btn, NULL);
    lv_imgbtn_set_src(shockwave_btn, LV_BTN_STATE_RELEASED, &shockwave);
    lv_imgbtn_set_src(shockwave_btn, LV_BTN_STATE_PRESSED, &shockwave);
    lv_obj_align(shockwave_btn, gContainer_p2_trauma_btn, LV_ALIGN_IN_BOTTOM_MID, 0, -10);
    lv_obj_set_event_cb(shockwave_btn, click_event_p2);

    injury_btn = lv_imgbtn_create(gContainer_p2_trauma_btn, NULL);
    lv_imgbtn_set_src(injury_btn, LV_BTN_STATE_RELEASED, &injury);
    lv_imgbtn_set_src(injury_btn, LV_BTN_STATE_PRESSED, &injury);
    lv_obj_align(injury_btn, gContainer_p2_trauma_btn, LV_ALIGN_IN_TOP_LEFT, 10, 10);
    lv_obj_set_event_cb(injury_btn, click_event_p2);

    if(tilt_value){

        falldamage_btn = lv_imgbtn_create(gContainer_p2_trauma_btn, NULL);
        lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_RELEASED, &falldamage_red);
        lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_PRESSED, &falldamage_red);
        lv_obj_align(falldamage_btn, gContainer_p2_trauma_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(falldamage_btn, click_event_p2);
        tilt_value = 0;
    }
    else{

        falldamage_btn = lv_imgbtn_create(gContainer_p2_trauma_btn, NULL);
        lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_RELEASED, &falldamage_green);
        lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_PRESSED, &falldamage_green);
        lv_obj_align(falldamage_btn, gContainer_p2_trauma_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
        lv_obj_set_event_cb(falldamage_btn, click_event_p2);
    }

    // falldamage_btn = lv_imgbtn_create(gContainer_p2_trauma_btn, NULL);
    // lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_RELEASED, &falldamage);
    // lv_imgbtn_set_src(falldamage_btn, LV_BTN_STATE_PRESSED, &falldamage);
    // lv_obj_align(falldamage_btn, gContainer_p2_trauma_btn, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
    // lv_obj_set_event_cb(falldamage_btn, click_event_p2);
}

void inflate_p2_compass(){

    p2_compass_btn_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_14);

    gContainer_p11 = lv_cont_create(gContainer_p2_main, NULL);
        lv_obj_set_size(gContainer_p11,  165, 165);
        lv_obj_add_style(gContainer_p11, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
        lv_obj_align(gContainer_p11, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    // direction_txt = lv_label_create(gContainer_p11, NULL);
    //     lv_label_set_text(direction_txt, "1 N");
    //     lv_obj_add_style(direction_txt, LV_OBJ_PART_MAIN, &small_text_style);
    //     lv_obj_align(direction_txt, gContainer_p11, LV_ALIGN_IN_TOP_MID, 0, 0);

    compass_ic = lv_imgbtn_create(gContainer_p11, NULL);
        lv_imgbtn_set_src(compass_ic, LV_BTN_STATE_RELEASED, &compass);
        lv_imgbtn_set_src(compass_ic, LV_BTN_STATE_PRESSED, &compass);
        lv_obj_align(compass_ic, direction_txt,LV_ALIGN_IN_TOP_MID, 0, 5);
}

void inflate_p15_btn(){

    p2_page15_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    static lv_style_t small_text_style;
    lv_style_init(&small_text_style);
    lv_style_set_text_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_bg_color(&small_text_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    // lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_18);
    lv_style_set_text_font(&small_text_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);

    gContainer_p15 = lv_cont_create(gContainer_p2_main, NULL);
        lv_obj_set_size(gContainer_p15,  165, 165);
        lv_obj_add_style(gContainer_p15, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
        lv_obj_align(gContainer_p15, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    battery_text = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(battery_text, "Battery");
        lv_obj_add_style(battery_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(battery_text, gContainer_p15, LV_ALIGN_IN_TOP_LEFT, 10, 30);

    percentage_text_1 = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(percentage_text_1, "percentage:");
        lv_obj_add_style(percentage_text_1, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(percentage_text_1, battery_text, LV_ALIGN_IN_TOP_LEFT, 0, 15);

    battery_health_text = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(battery_health_text, "Battery health");
        lv_obj_add_style(battery_health_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(battery_health_text, percentage_text_1, LV_ALIGN_IN_TOP_LEFT, 0, 30);

    percentage_text_2 = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(percentage_text_2, "percentage:");
        lv_obj_add_style(percentage_text_2, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(percentage_text_2, battery_health_text, LV_ALIGN_IN_TOP_LEFT, 0, 15);

    time_charge_text = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(time_charge_text, "Time to charge:");
        lv_obj_add_style(time_charge_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(time_charge_text, percentage_text_2, LV_ALIGN_IN_TOP_LEFT, 0, 30);

    time_discharge_text = lv_label_create(gContainer_p15, NULL);
        lv_label_set_text(time_discharge_text, "Time to discharge:");
        lv_obj_add_style(time_discharge_text, LV_OBJ_PART_MAIN, &small_text_style);
        lv_obj_align(time_discharge_text, time_charge_text, LV_ALIGN_IN_TOP_LEFT, 0, 30);

}

void inflate_p12_btn(){

    p2_page12_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p12 = lv_cont_create(gContainer_p2_main, NULL);
        lv_obj_set_size(gContainer_p12, 165 ,165 );
        lv_obj_add_style(gContainer_p12, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
        lv_obj_align(gContainer_p12, gContainer_p2_main ,LV_ALIGN_CENTER, 0, 0);

    help_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_imgbtn_set_src(help_btn, LV_BTN_STATE_RELEASED, &help);
        lv_imgbtn_set_src(help_btn, LV_BTN_STATE_PRESSED, &help);
        lv_obj_set_event_cb(help_btn, click_event_p2);
        lv_obj_align(help_btn, gContainer_p12, LV_ALIGN_IN_TOP_MID, 0, 10);

    yes_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_obj_align(yes_btn, help_btn,LV_ALIGN_IN_TOP_LEFT, 0, 50);
        lv_obj_set_event_cb(yes_btn, click_event_p2);
        lv_imgbtn_set_src(yes_btn, LV_BTN_STATE_RELEASED, &yes);
        lv_imgbtn_set_src(yes_btn, LV_BTN_STATE_PRESSED, &yes);
        
        
    no_btn = lv_imgbtn_create(gContainer_p12, NULL);
        lv_imgbtn_set_src(no_btn, LV_BTN_STATE_RELEASED, &no);
        lv_imgbtn_set_src(no_btn, LV_BTN_STATE_PRESSED, &no);
        lv_obj_align(no_btn, help_btn,LV_ALIGN_IN_TOP_MID, 0, 100);
        lv_obj_set_event_cb(no_btn, click_event_p2);
}

void inflate_p13_btn(){

    p2_page13_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p13 = lv_cont_create(gContainer_p2_main, NULL);
        lv_obj_set_size(gContainer_p13, 165 ,165 );
        lv_obj_add_style(gContainer_p13, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
        lv_obj_align(gContainer_p13,gContainer_p2_main ,LV_ALIGN_CENTER, 0, 0);

    pending_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(pending_btn, LV_BTN_STATE_RELEASED, &pending);
        lv_imgbtn_set_src(pending_btn, LV_BTN_STATE_PRESSED, &pending);
        lv_obj_align(pending_btn, gContainer_p13, LV_ALIGN_IN_TOP_MID, 0, 10);
        lv_obj_set_event_cb(pending_btn, click_event_p2);

    resolved_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(resolved_btn, LV_BTN_STATE_RELEASED, &resolved);
        lv_imgbtn_set_src(resolved_btn, LV_BTN_STATE_PRESSED, &resolved);
        lv_obj_align(resolved_btn, pending_btn,LV_ALIGN_IN_TOP_MID, 0, 45);
        lv_obj_set_event_cb(resolved_btn, click_event_p2);

    emergency_btn = lv_imgbtn_create(gContainer_p13, NULL);
        lv_imgbtn_set_src(emergency_btn, LV_BTN_STATE_RELEASED, &emergency);
        lv_imgbtn_set_src(emergency_btn, LV_BTN_STATE_PRESSED, &emergency);
        lv_obj_align(emergency_btn, gContainer_p12, LV_ALIGN_IN_TOP_MID, 0, 110);
        lv_obj_set_event_cb(emergency_btn, click_event_p2);
}

void inflate_p_2_btn(){

    p_2_page_flag=true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p_2_holder = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p_2_holder, 165 ,165 );
    lv_obj_add_style(gContainer_p_2_holder, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p_2_holder, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    blade_ic = lv_imgbtn_create(gContainer_p_2_holder, NULL);
        lv_imgbtn_set_src(blade_ic, LV_BTN_STATE_RELEASED, &blade);
        lv_imgbtn_set_src(blade_ic, LV_BTN_STATE_PRESSED, &blade);
        lv_obj_align(blade_ic, gContainer_p_2_holder, LV_ALIGN_IN_TOP_LEFT, 2, 8);
        lv_obj_set_event_cb(blade_ic, click_event_p2);

    chat_ic = lv_imgbtn_create(gContainer_p_2_holder, NULL);
        lv_imgbtn_set_src(chat_ic, LV_BTN_STATE_RELEASED, &chat);
        lv_imgbtn_set_src(chat_ic, LV_BTN_STATE_PRESSED, &chat);
        lv_obj_align(chat_ic, gContainer_p_2_holder,LV_ALIGN_IN_TOP_RIGHT, -2, 8);
        lv_obj_set_event_cb(chat_ic, click_event_p2);

    battery_empty_ic = lv_imgbtn_create(gContainer_p_2_holder, NULL);
        lv_imgbtn_set_src(battery_empty_ic, LV_BTN_STATE_RELEASED, &battery_empty);
        lv_imgbtn_set_src(battery_empty_ic, LV_BTN_STATE_PRESSED, &battery_empty);
        lv_obj_align(battery_empty_ic, gContainer_p_2_holder, LV_ALIGN_IN_BOTTOM_LEFT, 2, -3);
        lv_obj_set_event_cb(battery_empty_ic, click_event_p2);

    settings_ic = lv_imgbtn_create(gContainer_p_2_holder, NULL);
        lv_imgbtn_set_src(settings_ic, LV_BTN_STATE_RELEASED, &Settings);
        lv_imgbtn_set_src(settings_ic, LV_BTN_STATE_PRESSED, &Settings);
        lv_obj_align(settings_ic, gContainer_p_2_holder,LV_ALIGN_IN_BOTTOM_RIGHT, -2, -3);
        lv_obj_set_event_cb(settings_ic, click_event_p2);
}

void inflate_p2_holder(){

    p2_holder_flag = true;

    static lv_style_t cont_style_p2_holder;
    lv_style_init(&cont_style_p2_holder);
    lv_style_set_border_width(&cont_style_p2_holder, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2_holder, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2_holder, LV_STATE_DEFAULT, 5);

    gContainer_p2_holder = lv_cont_create(gContainer_p2_main, NULL);
    lv_obj_set_size(gContainer_p2_holder, 165, 165);
    lv_obj_add_style(gContainer_p2_holder, LV_OBJ_PART_MAIN, &cont_style_p2_holder);
    lv_obj_align(gContainer_p2_holder, gContainer_p2_main, LV_ALIGN_CENTER, 0, 0);

    trauma_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(trauma_btn, LV_BTN_STATE_RELEASED, &trauma);
    lv_imgbtn_set_src(trauma_btn, LV_BTN_STATE_PRESSED, &trauma);
    lv_obj_align(trauma_btn, gContainer_p2_holder, LV_ALIGN_IN_BOTTOM_LEFT, 10, -10);
    lv_obj_set_event_cb(trauma_btn, click_event_p2);

    profile_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(profile_btn, LV_BTN_STATE_RELEASED, &profile);
    lv_imgbtn_set_src(profile_btn, LV_BTN_STATE_PRESSED, &profile);
    lv_obj_align(profile_btn, gContainer_p2_holder, LV_ALIGN_IN_TOP_LEFT, 10, 10);
    lv_obj_set_event_cb(profile_btn, click_event_p2);

    health_btn = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(health_btn, LV_BTN_STATE_RELEASED, &health);
    lv_imgbtn_set_src(health_btn, LV_BTN_STATE_PRESSED, &health);
    lv_obj_align(health_btn, gContainer_p2_holder, LV_ALIGN_IN_TOP_RIGHT, -10, 10);
    lv_obj_set_event_cb(health_btn, click_event_p2);

    ambient_temp_btn_p2 = lv_imgbtn_create(gContainer_p2_holder, NULL);
    lv_imgbtn_set_src(ambient_temp_btn_p2, LV_BTN_STATE_RELEASED, &ambient);
    lv_imgbtn_set_src(ambient_temp_btn_p2, LV_BTN_STATE_PRESSED, &ambient);
    lv_obj_align(ambient_temp_btn_p2, gContainer_p2_holder, LV_ALIGN_IN_BOTTOM_RIGHT, -10, -10);
    lv_obj_set_event_cb(ambient_temp_btn_p2, click_event_p2);
}

void page_2_init(){

    page_2 = lv_obj_create(NULL, NULL);
    
    static lv_style_t cont_style_p2;
    lv_style_init(&cont_style_p2);
    lv_style_set_border_width(&cont_style_p2, LV_OBJ_PART_MAIN, 0);
    lv_style_set_bg_color(&cont_style_p2, LV_STATE_DEFAULT, LV_COLOR_BLACK);
    lv_style_set_radius(&cont_style_p2, LV_STATE_DEFAULT, 0);

    gContainer_p2_main = lv_cont_create(page_2, NULL);
    lv_obj_set_size(gContainer_p2_main, LV_HOR_RES, LV_VER_RES);
    lv_obj_add_style(gContainer_p2_main, LV_OBJ_PART_MAIN, &cont_style_p2);
    lv_obj_align(gContainer_p2_main, page_2, LV_ALIGN_CENTER, 0, 0);

    arrow_down_btn = lv_imgbtn_create(gContainer_p2_main, NULL);
    lv_imgbtn_set_src(arrow_down_btn, LV_BTN_STATE_RELEASED, &arrowdown);
    lv_imgbtn_set_src(arrow_down_btn, LV_BTN_STATE_PRESSED, &arrowdown);
    lv_obj_align(arrow_down_btn, gContainer_p2_main, LV_ALIGN_IN_BOTTOM_MID, 0, -5);
    lv_obj_add_style(arrow_down_btn, LV_OBJ_PART_MAIN, &cont_style_p2);
    lv_obj_set_event_cb(arrow_down_btn, click_event_p2);

    arrow_up_button = lv_imgbtn_create(gContainer_p2_main, NULL);
    lv_imgbtn_set_src(arrow_up_button, LV_BTN_STATE_RELEASED, &arrow_up);
    lv_imgbtn_set_src(arrow_up_button, LV_BTN_STATE_PRESSED, &arrow_up);
    lv_obj_align(arrow_up_button, gContainer_p2_main, LV_ALIGN_IN_TOP_MID, 0, 5);
    lv_obj_add_style(arrow_up_button, LV_OBJ_PART_MAIN, &cont_style_p2);
    lv_obj_set_event_cb(arrow_up_button, click_event_p2);

    logo_img = lv_imgbtn_create(gContainer_p2_main, NULL);
    lv_imgbtn_set_src(logo_img, LV_BTN_STATE_RELEASED, &logo);
    lv_imgbtn_set_src(logo_img, LV_BTN_STATE_PRESSED, &logo);
    //lv_img_set_src(logo_img, &logo);
    lv_obj_align(logo_img, gContainer_p2_main, LV_ALIGN_IN_TOP_RIGHT, -3, 3);
    lv_obj_add_style(logo_img, LV_OBJ_PART_MAIN, &cont_style_p2);
    lv_obj_set_event_cb(logo_img, click_event_p2);

    inflate_p2_holder();
}
