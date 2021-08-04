


void handle_serialBT() {
  static String message = "";
  while (ESP_BT.available()) {
    if (ESP_BT.available() > 0) //Check if we receive anything from Bluetooth
    {
      char incoming = ESP_BT.read(); //Read what we recevive
      message += incoming;
    }
  }

  if (message.length() >= 0) {
    //ESP_BT.print(message);
    if (message.indexOf("tol") != -1) {
      if ( message.toFloat() <= 0.99 and message.toFloat() > 0.5) {
        ESP_BT.print("Setting Tolerance to " + String(message.toFloat()));
        ESP_BT.print('\n');
        preferences.begin("tray1", 0);
        preferences.putFloat("tol", message.toFloat());
        tol = message.toFloat();
        preferences.end();
      }
    }

    if (message.indexOf("siu") != -1) {
      ESP_BT.print("Setting Samples in use to " + String(message.toFloat()));
      ESP_BT.print('\n');
      preferences.begin("tray1", 0);
      preferences.putInt("tol", message.toInt());
      samples_in_use = message.toInt();
      preferences.end();
      LoadCell_1.setSamplesInUse(message.toInt());
      LoadCell_2.setSamplesInUse(message.toInt());
      LoadCell_3.setSamplesInUse(message.toInt());
      LoadCell_4.setSamplesInUse(message.toInt());

    }

    if (message.indexOf("graph") != -1) {
      bt_plot = !bt_plot;
    }
    if (message.indexOf( "tare") != -1) {
      ESP_BT.print("starting tare"); ESP_BT.print('\n');
      tareCells();
    }
    if (message.indexOf("thresh") != -1) {
      ESP_BT.print("changing threshold value"); ESP_BT.print('\n');
      preferences.begin("tray1", 0);
      preferences.putFloat("threshold", message.toInt());
      start_thresh = message.toInt();
      preferences.end();
    }

    if (message.indexOf("getc") != -1) {
      ESP_BT.print("tol = " + String(tol) + '\n');
      ESP_BT.print("thresh = " + String(start_thresh) + '\n');
      ESP_BT.print("pack1 = " + String(pack1) + '\n');
      ESP_BT.print("pack2 = " + String(pack2) + '\n');
      ESP_BT.print("pack3 = " + String(pack3) + '\n');
      ESP_BT.print("pack4 = " + String(pack4) + '\n');
      ESP_BT.print("current pack = " + String(pack) + '\n');
      ESP_BT.print('\n');
    }

    if (message.indexOf("getv") != -1) {
      ESP_BT.print("A = " + String(a) + '\n');
      ESP_BT.print("B = " + String(b) + '\n');
      ESP_BT.print("C = " + String(c) + '\n');
      ESP_BT.print("D = " + String(d) + '\n');
    }

    message = "";
  }

}
