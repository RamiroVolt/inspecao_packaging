void learning_blink() {
  static long l = 0;
  static bool state = 0;
  if (millis() > l + 400) {
    l = millis();
    state = !state;
    if (state) {
      led1.on();
      led2.on();
      led3.on();
      led4.on();
    } else {
      led_clear();
      switch (learning_pack) {
        case 1: led1.on(); break;
        case 2: led2.on(); break;
        case 3: led3.on(); break;
        case 4: led4.on(); break;
      }
    }
  }
}

void save_learned() {

}

void learn() {

  while (true) {
    learning_blink();
    updateCells();
    read_button();
    static int t1_max, last_t1;
    static byte tray = 0;
    int t1_c = int(tray1); // current tray 1 value
    t1_max; // tray 1 max value

    //----------------------------------------------detect wich tray
    if ( t1_c >= start_thresh  and tray == 0 and last_t1 < start_thresh) {
      tray = 1;
    }
    //----------------------------------------------measure tray 1
    if (t1_c > t1_max and tray == 1) t1_max = t1_c;

    //----------------------------------------------learn tray1

    if ( t1_c < start_thresh and t1_max != 0 and tray == 1) {


      pack = t1_max;
      led_clear();



      t1_max = 0;
      tray = 0;
      learned = true;
      last_t1 = t1_c;
      read_button();

      learning_f = false;
      switch (learning_pack) {
        case 1: pack1 = pack; led1.on();
          preferences.begin("tray1", false);
          preferences.putInt("pack1", pack);
          preferences.end();
          break;
        case 2: pack2 = pack; led2.on();
          preferences.begin("tray1", false);
          preferences.putInt("pack2", pack);
          preferences.end();
          break;
        case 3: pack3 = pack; led3.on();
          preferences.begin("tray1", false);
          preferences.putInt("pack3", pack);
          preferences.end();
          break;
        case 4: pack4 = pack; led4.on();
          preferences.begin("tray1", false);
          preferences.putInt("pack4", pack);
          preferences.end();
          break;
      }
      break;
    }

  }
}
