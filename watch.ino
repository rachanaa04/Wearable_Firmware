#pragma mark 

#include "config.h"
#include "pages.h"

TTGOClass *ttgo;
TFT_eSPI *tft;
BMA *sensor;
unsigned long currentMillis ;
unsigned long lastExecutedMillis;
int irq = 0;

void setup(){

    p1_main_flag=false;
    Serial.begin(115200);
    Serial.println("setup started...");
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->lvgl_begin();

    //Receive objects for easy writing
    tft = ttgo->tft;
    sensor = ttgo->bma;
    ttgo->rtc->setDateTime(2024, 7, 25, 5, 21, 0);
    // ttgo->rtc->syncToSystem();
    ttgo->motor_begin();


    // Accel parameter structure
    Acfg cfg;
    /*!
        Output data rate in Hz, Optional parameters:
            - BMA4_OUTPUT_DATA_RATE_0_78HZ
            - BMA4_OUTPUT_DATA_RATE_1_56HZ
            - BMA4_OUTPUT_DATA_RATE_3_12HZ
            - BMA4_OUTPUT_DATA_RATE_6_25HZ
            - BMA4_OUTPUT_DATA_RATE_12_5HZ
            - BMA4_OUTPUT_DATA_RATE_25HZ
            - BMA4_OUTPUT_DATA_RATE_50HZ
            - BMA4_OUTPUT_DATA_RATE_100HZ
            - BMA4_OUTPUT_DATA_RATE_200HZ
            - BMA4_OUTPUT_DATA_RATE_400HZ
            - BMA4_OUTPUT_DATA_RATE_800HZ
            - BMA4_OUTPUT_DATA_RATE_1600HZ
    */
    cfg.odr = BMA4_OUTPUT_DATA_RATE_100HZ;
    /*!
        G-range, Optional parameters:
            - BMA4_ACCEL_RANGE_2G
            - BMA4_ACCEL_RANGE_4G
            - BMA4_ACCEL_RANGE_8G
            - BMA4_ACCEL_RANGE_16G
    */
    cfg.range = BMA4_ACCEL_RANGE_4G;
    /*!
        Bandwidth parameter, determines filter configuration, Optional parameters:
            - BMA4_ACCEL_OSR4_AVG1
            - BMA4_ACCEL_OSR2_AVG2
            - BMA4_ACCEL_NORMAL_AVG4
            - BMA4_ACCEL_CIC_AVG8
            - BMA4_ACCEL_RES_AVG16
            - BMA4_ACCEL_RES_AVG32
            - BMA4_ACCEL_RES_AVG64
            - BMA4_ACCEL_RES_AVG128
    */
    cfg.bandwidth = BMA4_ACCEL_NORMAL_AVG4;

    /*! Filter performance mode , Optional parameters:
        - BMA4_CIC_AVG_MODE
        - BMA4_CONTINUOUS_MODE
    */
    cfg.perf_mode = BMA4_CONTINUOUS_MODE;

    // Configure the BMA423 accelerometer
    sensor->accelConfig(cfg);

    // Enable BMA423 accelerometer
    // Warning : Need to use feature, you must first enable the accelerometer
    // Warning : Need to use feature, you must first enable the accelerometer
    // Warning : Need to use feature, you must first enable the accelerometer
    sensor->enableAccel();

    pinMode(BMA423_INT1, INPUT);
    attachInterrupt(BMA423_INT1, [] {
        // Set interrupt to set irq value to 1
        irq = 1;
    }, RISING); //It must be a rising edge

    // Enable BMA423 isStepCounter feature
    sensor->enableFeature(BMA423_STEP_CNTR, true);
    // Enable BMA423 isTilt feature
    sensor->enableFeature(BMA423_TILT, true);

    // Reset steps
    sensor->resetStepCounter();

    // Turn on feature interrupt
    sensor->enableStepCountInterrupt();
    sensor->enableTiltInterrupt();

    lastExecutedMillis = 0;
    currentMillis = millis();
    page_1_init();
    lv_scr_load(page_1);
}

void loop(){

    lv_task_handler();
    delay(5);

    currentMillis = millis();

    if (currentMillis - lastExecutedMillis >= 5000) {

        Serial.println(p2_health_btn_1_flag);
        // Save the last executed time
        lastExecutedMillis = currentMillis; 
        // Your code block to execute once every second
        if(p2_health_btn_1_flag){

            // Serial.println("inside active flag");
            text_p2_contact_body_temp_value=random(35,40);
            Serial.println(text_p2_contact_body_temp_value);
            
            text_p2_contact_body_temp_value=random(12,18);
            Serial.println(text_p2_respiration_rate_value);
            // dynamic_p2_health_btn_1();
            inflate_p2_health_btn_1();
        }

        else if(p2_health_btn_2_flag){

            step_count_value = sensor->getCounter();
            inflate_p2_health_btn_2();
        }

        else if(p2_health_btn_3_flag){
            //setiing random values for health btn 3
            text_p2_heartrate_value=random(76,94);
            text_p2_spo2_value=random(95,100);
            text_p2_heartrateV_value=random(40,56);
            // dynamic_p2_health_btn_3();
            inflate_p2_health_btn_3();
        }
        else if(p1_main_flag){
            //setting random values for page 1 main
            ambient_temp_val=random(25,40);
            injuryh_val=random(0,24);
            health_val=random(36,56);
            // dynamic_p1_main();
            RTC_Date t = ttgo->rtc->getDateTime();
            hour = int(t.hour);
            minute = t.minute;
            month = int(t.month);
            date = int(t.day);
            year = int(t.year);
            day = int(ttgo->rtc->getDayOfWeek(t.day, t.month, t.year));
            page_1_init();
        }

        else if(p2_ambient_temp_btn_1_flag){
            //setting randomvalues for ambient temp btn screen 1
            text_alti_value=random(900,1000);
            text_aqi_value=random(145,165);
            text_voc_value=random(0.2,3.0);
            // dynamic_p2_ambient_temp_btn_1();
            inflate_p2_ambient_temp_btn_1();
        }
        else if(p2_ambient_temp_btn_2_flag){
            //setting random data for amb temp screen 2
            text_amb_pressure_value=random(0.1,1.0);
            text_humidity_value=random(35,60);
            text_amb_temp_value=random(40,50);
            // dynamic_p2_ambient_temp_btn_2();
            inflate_p2_ambient_temp_btn_2();
        }
    }

    if(irq){

        irq = 0;
        bool rlst;
        do{
            rlst = sensor->readInterrupt();
        }while(!rlst);

        // Fall Detected
        if(sensor->isTilt()){

            tilt_value = 1;
            ttgo->motor->onec();
            delay(1000);
            inflate_p2_trauma_btn_1();
        }
    }
}



