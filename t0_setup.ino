void setup_package_inspection() {
  Serial.begin(115200);
  ESP_BT.begin("ESP32_BT");
  //----------------------------------BUTTONS

  //----------------------------------RELAYS

  //---------------------------------LOADCELL
  float calibrationValue_1 = -737.452 * 0.30;
  float calibrationValue_2 = 710.2 * 0.30;
  float calibrationValue_3 = 749.6 * 0.30;
  float calibrationValue_4 = -718.5 * 0.30;

  LoadCell_1.begin();
  LoadCell_2.begin();
  LoadCell_3.begin();
  LoadCell_4.begin();

  unsigned long stabilizingtime = 1000; boolean _tare = true;
  byte loadcell_1_rdy = 0;
  byte loadcell_2_rdy = 0;
  byte loadcell_3_rdy = 0;
  byte loadcell_4_rdy = 0;

  while ((loadcell_1_rdy + loadcell_2_rdy + loadcell_3_rdy + loadcell_4_rdy) < 4)
  { //run startup, stabilization and tare, both modules simultaniously
    if (!loadcell_1_rdy)
      loadcell_1_rdy = LoadCell_1.startMultiple(stabilizingtime, _tare);
    if (!loadcell_2_rdy)
      loadcell_2_rdy = LoadCell_2.startMultiple(stabilizingtime, _tare);
    if (!loadcell_3_rdy)
      loadcell_3_rdy = LoadCell_3.startMultiple(stabilizingtime, _tare);
    if (!loadcell_4_rdy)
      loadcell_4_rdy = LoadCell_4.startMultiple(stabilizingtime, _tare);
  }
  if (LoadCell_1.getTareTimeoutFlag())
  {
    Serial.println("Timeout, check MCU>HX711 no.1 wiring and pin designations");
  }
  if (LoadCell_2.getTareTimeoutFlag())
  {
    Serial.println("Timeout, check MCU>HX711 no.2 wiring and pin designations");
  }

  if (LoadCell_3.getTareTimeoutFlag())
  {
    Serial.println("Timeout, check MCU>HX711 no.3 wiring and pin designations");
  }
  if (LoadCell_4.getTareTimeoutFlag())
  {
    Serial.println("Timeout, check MCU>HX711 no.4 wiring and pin designations");
  }

  LoadCell_1.setCalFactor(calibrationValue_1); // user set calibration value (float)
  LoadCell_2.setCalFactor(calibrationValue_2); // user set calibration value (float)
  LoadCell_3.setCalFactor(calibrationValue_3); // user set calibration value (float)
  LoadCell_4.setCalFactor(calibrationValue_4); // user set calibration value (float)


  
}
