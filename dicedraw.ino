//To draw the dice

void drawd4() {
  tft.drawTriangle(120, 60, 172, 150, 68, 150, TFT_GREEN);
}

void drawd6() {
  tft.drawRect(60, 60, 120, 120, TFT_GREEN);
}

void drawd8() {
  tft.drawLine(120, 172, 165, 146, TFT_GREEN);
  tft.drawLine(165, 146, 165, 94, TFT_GREEN);
  tft.drawLine(165, 94, 120, 68, TFT_GREEN);
  tft.drawLine(120, 68, 75, 94, TFT_GREEN);
  tft.drawLine(75, 94, 75, 146, TFT_GREEN);
  tft.drawLine(75, 146, 120, 172, TFT_GREEN);
  tft.drawTriangle(75, 146, 165, 146, 120, 68, TFT_GREEN);
}

void drawd10() {
  tft.drawLine(120, 203, 120, 158, TFT_GREEN);
  tft.drawLine(68, 134, 38, 138, TFT_GREEN);
  tft.drawLine(120, 158, 68, 134, TFT_GREEN);
  tft.drawLine(38, 138, 120, 203, TFT_GREEN);
  tft.drawLine(120, 203, 120, 158, TFT_GREEN);
  tft.drawLine(120, 158, 172, 134, TFT_GREEN);
  tft.drawLine(172, 134, 201, 138, TFT_GREEN);
  tft.drawLine(201, 138, 120, 203, TFT_GREEN);
  tft.drawLine(68, 134, 120, 158, TFT_GREEN);
  tft.drawLine(120, 158, 172, 134, TFT_GREEN);
  tft.drawLine(172, 134, 120, 36, TFT_GREEN);
  tft.drawLine(120, 36, 68, 134, TFT_GREEN);
  tft.drawLine(38, 138, 40, 104, TFT_GREEN);
  tft.drawLine(40, 104, 120, 36, TFT_GREEN);
  tft.drawLine(201, 138, 199, 104, TFT_GREEN);
  tft.drawLine(199, 104, 120, 36, TFT_GREEN);
}

void drawd12() {
  tft.drawLine(87, 168, 153, 168, TFT_GREEN);
  tft.drawLine(153, 168, 173, 106, TFT_GREEN);
  tft.drawLine(173, 106, 120, 68, TFT_GREEN);
  tft.drawLine(120, 68, 67, 106, TFT_GREEN);
  tft.drawLine(67, 106, 87, 168, TFT_GREEN);
  tft.drawLine(120, 34, 67, 52, TFT_GREEN);
  tft.drawLine(67, 52, 37, 95, TFT_GREEN);
  tft.drawLine(37, 95, 37, 147, TFT_GREEN);
  tft.drawLine(37, 147, 67, 192, TFT_GREEN);
  tft.drawLine(67, 192, 120, 207, TFT_GREEN);
  tft.drawLine(120, 207, 167, 192, TFT_GREEN);
  tft.drawLine(167, 192, 202, 147, TFT_GREEN);
  tft.drawLine(202, 147, 202, 95, TFT_GREEN);
  tft.drawLine(202, 95, 167, 52, TFT_GREEN);
  tft.drawLine(167, 52, 120, 34, TFT_GREEN);
  tft.drawLine(120, 68, 120, 34, TFT_GREEN);
  tft.drawLine(173, 106, 202, 95, TFT_GREEN);
  tft.drawLine(153, 168, 167, 192, TFT_GREEN);
  tft.drawLine(67, 192, 87, 168, TFT_GREEN);
  tft.drawLine(67, 106, 37, 95, TFT_GREEN);
}

void drawd20() {
  tft.drawTriangle(83, 98, 120, 164, 157, 98, TFT_GREEN);
  tft.drawTriangle(120, 206, 194, 164, 120, 167, TFT_GREEN);
  tft.drawTriangle(120, 206, 46, 164, 120, 167, TFT_GREEN);
  tft.drawTriangle(83, 98, 46, 76, 120, 34, TFT_GREEN);
  tft.drawTriangle(83, 98, 46, 76, 46, 164, TFT_GREEN);
  tft.drawTriangle(157, 98, 194, 76, 120, 34, TFT_GREEN);
  tft.drawTriangle(157, 98, 194, 76, 194, 164, TFT_GREEN);
}