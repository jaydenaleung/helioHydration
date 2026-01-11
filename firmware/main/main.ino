// ELECTRONICS
#include "OneWire.h"
#include "DallasTemperature.h"

#define DQ_ONE_WIRE 4
#define UV_PIN A0;

OneWire oneWire(DQ_ONE_WIRE);
DallasTemperature sensors(&oneWire);

// CALCULATIONS
// See JOURNAL.md for the formula
bool active = true;

double L = 0.0;
double sum = 0.0;

double sigma = 0.03;
double C_PD = 1.0;
double coeff = sigma*C_PD/log(10); // log() is ln function

double delta_prev = 0.0;
double delta;
double delta_sec;

// Measurements
double V_PT; // photodiode voltage
double temp; // temperature measurement, celsius
double K_T; // temperature killing term

void initDelta() { // call initDelta() then updateDelta() in setup()
    delta = millis()-delta_prev;
    delta_sec = delta/1000.0;
}

void updateDelta() {
    delta_prev = delta;
    delta = millis()-delta_prev;
    delta_sec = delta/1000.0;
}

void updateVPT() {
    int uvLevel = analogRead(UV_PIN);
    V_PT = uvLevel * (5.0 / 1023.0);
}

void updateTemp() {
    sensors.requestTemperatures();
    temp = sensors.getTempCByIndex(0); // the index 0 refers to the first device
}

void updateTempTerm() {
    if (temp < 40) {
        K_T = 1.0;
    } else {
        K_T = pow(1.1036,temp-44.6958);
    }
}

// SETUP AND LOOP
void setup() {
    Serial.begin(9600);

    sensors.begin();
    delay(60*1000); // wait 1 min for sensors to init

    initDelta();
    updateDelta();
}

void loop() {
    if (active) {
        updateVPT();
        updateTemp();
        updateTempTerm();
        updateDelta();
        
        sum += V_PT*K_T*delta;
        L = coeff*sum;

        if (L >= 3.0) {
            active = false;
            Serial.println("Water successfully disinfected.");
        }
    }
 }