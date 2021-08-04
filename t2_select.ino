Button bt1(5);
Button bt2(4);
Button bt3(16);
Button bt4(17);
Button bt0(15);

void led_clear() {
  //  for (int i = 0; i <= 3; i++) {
  //    digitalWrite(led[i], 1);
  //  }
  led1.off();
  led2.off();
  led3.off();
  led4.off();

}

void select(int pack_type) {
  switch (pack_type) {
    case 1: led_clear(); led1.on(); pack = pack1;
      preferences.begin("parameters", false);
      preferences.putInt("pack", 1);
      preferences.end(); tareCells();
      break;
    case 2: led_clear(); led2.on(); pack = pack2;
      preferences.begin("parameters", false);
      preferences.putInt("pack", 2);
      preferences.end(); tareCells();
      break;
    case 3: led_clear(); led3.on(); pack = pack3;
      preferences.begin("parameters", false);
      preferences.putInt("pack", 3);
      preferences.end();tareCells();
      break; 
    case 4: led_clear(); led4.on(); pack = pack4;
      preferences.begin("parameters", false);
      preferences.putInt("pack", 4);
      preferences.end();tareCells();
      break; 
    case 0: led_clear(); pack = 0;
      preferences.begin("parameters", false);
      preferences.putInt("pack", 0);
      preferences.end();
      break;
  }
}

void read_button() {

  static bool bt1_f, bt2_f, bt3_f, bt4_f, bt0_f;
  static long t0, t1, t2, t3, t4;

  if (bt1.isPressed()) bt1_f = true;
  if (bt2.isPressed()) bt2_f = true;
  if (bt3.isPressed()) bt3_f = true;
  if (bt4.isPressed()) bt4_f = true;
  if (bt0.isPressed()) bt0_f = true;


  // ---------------------------------- PACK1
  if (!bt1.isPressed()) {
    if (bt1_f and !led1.state) {
      select(1);
    } bt1_f = false;
  } else if (bt1_f and bt1.pulseTime > 1500 and led1.state) {
    bt1_f = false;
    Serial.println("learning");
    learning_f = true;
    learning_pack = 1; learned = false;
  }

  // ---------------------------------- PACK2
  if (!bt2.isPressed()) {
    if (bt2_f and !led2.state) {
      select(2);
    } bt2_f = false;
  } else if (bt2_f and bt2.pulseTime > 1500 and led2.state) {
    bt2_f = false;
    Serial.println("learning");
    learning_f = true;
    learning_pack = 2; false;
  }

  // ---------------------------------- PACK3
  if (!bt3.isPressed()) {
    if (bt3_f and !led3.state) {
      select(3);
    } bt3_f = false;
  } else if (bt3_f and bt3.pulseTime > 1500 and led3.state) {
    bt3_f = false;
    Serial.println("learning");
    learning_f = true;  learning_pack = 3; false;
  }

  // ---------------------------------- PACK4
  if (!bt4.isPressed()) {
    if (bt4_f and !led4.state) {
      select(4);
    } bt4_f = false;
  } else if (bt4_f and bt4.pulseTime > 1500 and led4.state) {
    bt4_f = false;
    Serial.println("learning");
    learning_f = true; learning_pack = 4; false;
  }

  // ---------------------------------- TURN OFF
  if (!bt0.isPressed()) {
    if (bt0_f) {
      select(0);
    } bt0_f = false;
  }


}


//void read_button() {
//
//  static bool bt1_f, bt2_f, bt3_f, bt4_f, bt0_f;
//  static unsigned long t1, t2, t3, t4, t0;
//
//  long t = millis();
//  bool bt1 = digitalRead(button1);
//  bool bt2 = digitalRead(button2);
//  bool bt3 = digitalRead(button3);
//  bool bt4 = digitalRead(button4);
//  bool bt0 = digitalRead(button0);
//
//  // ---------------------------------botao 1------------
//  if (!bt1 and !bt1_f) { //pressed
//    t1 = t;
//    bt1_f = true;
//  }
//
//  if (bt1 and bt1_f) { //released
//    bt1_f = false;
//    if (t > t1 + debounce_time) {
//      led_clear();
//      //digitalWrite(led[0], 0);
//      led1.on();
//      pack = pack1;
//    }
//  }
//
//  // ---------------------------------botao 2------------
//  if (!bt2 and !bt2_f) { //pressed
//    t2 = t;
//    bt2_f = true;
//  }
//
//  if (bt2 and bt2_f) { // released
//    bt2_f = false;
//    if (t > t2 + debounce_time) {
//      led_clear();    led2.on();//digitalWrite(led[1], 0);
//      pack = pack2;
//    }
//  }
//  // ---------------------------------botao 3------------
//  if (!bt3 and !bt3_f) { // pressed
//    t3 = t;
//    bt3_f = true;
//  }
//
//  if (bt3 and bt3_f) { // released
//    bt3_f = false;
//    if (t > t3 + debounce_time) {
//      led_clear();    led3.on();//digitalWrite(led[2], 0);
//      pack = pack3;
//    }
//  }
//  // ---------------------------------botao 4------------
//  if (!bt4 and !bt4_f) { //pressed
//    t4 = t;
//    bt4_f = true;
//  }
//
//  if (bt4 and bt4_f) { //released
//    bt4_f = false;
//    if (t > t4 + debounce_time) {
//      led_clear();    led4.on();//digitalWrite(led[3], 0);
//      pack = pack4;
//    }
//  }
//  //---------------------------------botao 0--------------
//  if (!bt0 and !bt0_f) { //pressed
//    t0 = t;
//    bt0_f = true;
//  }
//
//  if (bt0 and bt0_f) { //released
//    bt0_f = false;
//    if (t > t0 + debounce_time) {
//      led_clear(); pack = 0;
//    }
//  }
//}
