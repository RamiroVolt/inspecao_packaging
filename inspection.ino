bool reject_f = 0;

void handle_transport() {
  static long t_time = 0;
  if (reject_f) {
    //ESP_BT.print("rejected");
    reject_f = 0;
    relay1.on();
    t_time = millis();
  }

  if (millis() > t_time + 200) {
    relay1.off();
  }
}

void inspect() {
  int t1_c = int(tray1); // current tray 1 value
  static int t1_max; // tray 1 max value

  int t2_c = int(tray2); // current tray 1 value
  static int t2_max; // tray 1 max value


  //----------------------------------------------measure  tray1
  if ( t1_c >= start_thresh  ) {
    if (t1_c > t1_max) t1_max = t1_c;
  }

  //----------------------------------------------inspect tray1
  if ( t1_c < start_thresh and t1_max != 0) {
    if (float(t1_max) < tol * float(pack)) {
      reject_f = 1;
      ESP_BT.print("rejected " + String(t2_max) + '\n');

    } else {
      ESP_BT.print("accepted  " + String(t1_max) + '\n');
    }
    t1_max = 0;
  }

  //----------------------------------------------measure  tray2
  if ( t2_c >= start_thresh  ) {
    if (t2_c > t2_max) t2_max = t2_c;
  }

  //----------------------------------------------inspect tray2
  if ( t2_c < start_thresh and t2_max != 0) {
    if (float(t2_max) < tol * float(pack)) {
      reject_f = 1;

      ESP_BT.print("rejected  " + String(t2_max) + '\n');
    } else {
      ESP_BT.print("accepted  " + String(t2_max) + '\n');
    }

    t2_max = 0;
  }


}
