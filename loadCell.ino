void tareCells() {
  LoadCell_1.tareNoDelay();
  LoadCell_2.tareNoDelay();
  LoadCell_3.tareNoDelay();
  LoadCell_4.tareNoDelay();
}

void updateCells() {
  static boolean newDataReady = 0;
  if (LoadCell_1.update() and LoadCell_2.update() and LoadCell_3.update() and LoadCell_4.update())
  {
    newDataReady = true;
  }

  if ((newDataReady))
  {
    a = LoadCell_1.getData();
   b = LoadCell_2.getData();
    c = LoadCell_3.getData();
    d = LoadCell_4.getData();

    if (true) {
      //Serial.print(String(a) + ",");
      //Serial.print(String(b) + ",");
      //Serial.print(String(c) + ",");
      //Serial.print(String(d) + ",");
      Serial.print(String(a + b) + ",");
      Serial.print(String(c + d) + ",");
      Serial.println(String(pack) + "," + String(float(pack) * tol));
      if(bt_plot){
        ESP_BT.print(String(a+b) + "," + String(c+d) + "," + '\n');
      }
      tray1 = a + b; tray2 = c + d;
      
    }
    newDataReady = 0;
  }

  if (Serial.available() > 0)
  {
    char inByte = Serial.read();
    if (inByte == 't')
    {
      tareCells();
    }
  }

}
