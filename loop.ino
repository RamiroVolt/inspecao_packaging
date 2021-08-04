void loop() {
  updateCells();
  handle_serialBT();
  if (!learning_f) {
    read_button();
    inspect();
    handle_transport();
  } else {
    learn();
  }
}
