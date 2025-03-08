//To draw the dice

void drawd4(float f, float x, float y) {
  tft.drawTriangle(120*f+x, 60*f+y, 172*f+x, 150*f+y, 68*f+x, 150*f+y, TFT_GREEN);
}

void drawd6(float f, float x, float y) {
  tft.drawRect(60*f+x, 60*f+y, 120*f+x, 120*f+x, TFT_GREEN);
}

void drawd8(float f, float x, float y) {
  tft.drawLine(120*f+x, 172*f+y, 165*f+x, 146*f+y, TFT_GREEN);
  tft.drawLine(165*f+x, 146*f+y, 165*f+x, 94*f+y, TFT_GREEN);
  tft.drawLine(165*f+x, 94*f+y, 120*f+x, 68*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 68*f+y, 75*f+x, 94*f+y, TFT_GREEN);
  tft.drawLine(75*f+x, 94*f+y, 75*f+x, 146*f+y, TFT_GREEN);
  tft.drawLine(75*f+x, 146*f+y, 120*f+x, 172*f+y, TFT_GREEN);
  tft.drawTriangle(75*f+x, 146*f+y, 165*f+x, 146*f+y, 120*f+x, 68*f+y, TFT_GREEN);
}

void drawd10(float f, float x, float y) {
  tft.drawLine(120*f+x, 203*f+y, 120*f+x, 158*f+y, TFT_GREEN);
  tft.drawLine(68*f+x, 134*f+y, 38*f+x, 138*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 158*f+y, 68*f+x, 134*f+y, TFT_GREEN);
  tft.drawLine(38*f+x, 138*f+y, 120*f+x, 203*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 203*f+y, 120*f+x, 158*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 158*f+y, 172*f+x, 134*f+y, TFT_GREEN);
  tft.drawLine(172*f+x, 134*f+y, 201*f+x, 138*f+y, TFT_GREEN);
  tft.drawLine(201*f+x, 138*f+y, 120*f+x, 203*f+y, TFT_GREEN);
  tft.drawLine(68*f+x, 134*f+y, 120*f+x, 158*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 158*f+y, 172*f+x, 134*f+y, TFT_GREEN);
  tft.drawLine(172*f+x, 134*f+y, 120*f+x, 36*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 36*f+y, 68*f+x, 134*f+y, TFT_GREEN);
  tft.drawLine(38*f+x, 138*f+y, 40*f+x, 104*f+y, TFT_GREEN);
  tft.drawLine(40*f+x, 104*f+y, 120*f+x, 36*f+y, TFT_GREEN);
  tft.drawLine(201*f+x, 138*f+y, 199*f+x, 104*f+y, TFT_GREEN);
  tft.drawLine(199*f+x, 104*f+y, 120*f+x, 36*f+y, TFT_GREEN);
}

void drawd12(float f, float x, float y) {
  tft.drawLine(87*f+x, 168*f+y, 153*f+x, 168*f+y, TFT_GREEN);
  tft.drawLine(153*f+x, 168*f+y, 173*f+x, 106*f+y, TFT_GREEN);
  tft.drawLine(173*f+x, 106*f+y, 120*f+x, 68*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 68*f+y, 67*f+x, 106*f+y, TFT_GREEN);
  tft.drawLine(67*f+x, 106*f+y, 87*f+x, 168*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 34*f+y, 67*f+x, 52*f+y, TFT_GREEN);
  tft.drawLine(67*f+x, 52*f+y, 37*f+x, 95*f+y, TFT_GREEN);
  tft.drawLine(37*f+x, 95*f+y, 37*f+x, 147*f+y, TFT_GREEN);
  tft.drawLine(37*f+x, 147*f+y, 67*f+x, 192*f+y, TFT_GREEN);
  tft.drawLine(67*f+x, 192*f+y, 120*f+x, 207*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 207*f+y, 167*f+x, 192*f+y, TFT_GREEN);
  tft.drawLine(167*f+x, 192*f+y, 202*f+x, 147*f+y, TFT_GREEN);
  tft.drawLine(202*f+x, 147*f+y, 202*f+x, 95*f+y, TFT_GREEN);
  tft.drawLine(202*f+x, 95*f+y, 167*f+x, 52*f+y, TFT_GREEN);
  tft.drawLine(167*f+x, 52*f+y, 120*f+x, 34*f+y, TFT_GREEN);
  tft.drawLine(120*f+x, 68*f+y, 120*f+x, 34*f+y, TFT_GREEN);
  tft.drawLine(173*f+x, 106*f+y, 202*f+x, 95*f+y, TFT_GREEN);
  tft.drawLine(153*f+x, 168*f+y, 167*f+x, 192*f+y, TFT_GREEN);
  tft.drawLine(67*f+x, 192*f+y, 87*f+x, 168*f+y, TFT_GREEN);
  tft.drawLine(67*f+x, 106*f+y, 37*f+x, 95*f+y, TFT_GREEN);
}

void drawd20(float f, float x, float y) {
  tft.drawTriangle(83*f+x, 98*f+y, 120*f+x, 164*f+y, 157*f+x, 98*f+y, TFT_GREEN);
  tft.drawTriangle(120*f+x, 206*f+y, 194*f+x, 164*f+y, 120*f+x, 167*f+y, TFT_GREEN);
  tft.drawTriangle(120*f+x, 206*f+y, 46*f+x, 164*f+y, 120*f+x, 167*f+y, TFT_GREEN);
  tft.drawTriangle(83*f+x, 98*f+y, 46*f+x, 76*f+y, 120*f+x, 34*f+y, TFT_GREEN);
  tft.drawTriangle(83*f+x, 98*f+y, 46*f+x, 76*f+y, 46*f+x, 164*f+y, TFT_GREEN);
  tft.drawTriangle(157*f+x, 98*f+y, 194*f+x, 76*f+y, 120*f+x, 34*f+y, TFT_GREEN);
  tft.drawTriangle(157*f+x, 98*f+y, 194*f+x, 76*f+y, 194*f+x, 164*f+y, TFT_GREEN);
}
