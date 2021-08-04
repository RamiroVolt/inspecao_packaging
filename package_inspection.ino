#include <Arduino.h>
#include "Led.h"
#include "Button.h"
#include <HX711_ADC.h>
#define button1 5
#define button2 4
#define button3 16
#define button4 17
#define button0 15
#include <Preferences.h>
#include "BluetoothSerial.h"
Preferences preferences;

//Global Variables
const int output_pin = 23, pd_pin = 15;
bool learning_f;
byte learning_pack;
bool learned = false, bt_plot;
int start_thresh = 500;
int pack = 0,
    pack1 = 1000,
    pack2 = 1350,
    pack3 = 2000,
    pack4 = 2500,
    samples_in_use;
int tray1, tray2;
float tol = 0.92;
float a,b,c,d;

bool bt_print = false;
//const int learned_eepromAdress_1 = 0,
//          learned_eepromAdress_2 = 8,
//

//LEDS
Led led1(18);
Led led2(21);
Led led3(22);
Led led4(19);
Led relay1(23);

BluetoothSerial ESP_BT;

//CELLS
HX711_ADC LoadCell_1(35, 26); //HX711 1 //
HX711_ADC LoadCell_2(34, 25); //HX711 2 //
HX711_ADC LoadCell_3(39, 33); //HX711 3 //
HX711_ADC LoadCell_4(36, 32); //HX711 4 //

//-----------------Function prototypes
void led_clear();
void setup_package_inspection();
void read_button();
void select();
void tareCells();
void uptadeCells();
void learning_blink();
void learn();
void inspect();


void setup() {
  setup_package_inspection();
  preferences.begin("tray1", false);
  pack1 = preferences.getInt("pack1", 1000);
  pack2 = preferences.getInt("pack2", 1250);
  pack3 = preferences.getInt("pack3", 1500);
  pack4 = preferences.getInt("pack4", 1750);
  tol = preferences.getFloat("tol", 0.9);
  start_thresh = preferences.getInt("threshold", 500);
  samples_in_use = preferences.getInt("siu", 5);
  
  if (preferences.getInt("pack", 0) != 0) {
    select(preferences.getInt("pack", 0));
  }
  preferences.end();

  

}
