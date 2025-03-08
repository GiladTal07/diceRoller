#include <SPI.h>
#include <TFT_eSPI.h>
#include <vector>

#define TFT1_CS 22  // Chip Select for the first display
#define TFT2_CS 21  // Chip Select for the second display

TFT_eSPI tft = TFT_eSPI();
int diceChooseButtonState = LOW;
int diceChooseLastButtonState = LOW;
int diceSelectButtonState = LOW;
int diceSelectLastButtonState = LOW;
int resetButtonState = LOW;
int resetLastButtonState = LOW;
int diceNum = 0;
std::vector<int> dice;  // Use a vector instead of an array

enum State {
  idle,
  initial,
  diceMove,
  diceDecision,
  reset,
};
State state = initial;

void setup(void) {
  pinMode(25, INPUT_PULLUP);  // Button for selecting the dice
  pinMode(26, INPUT_PULLUP);  // Button for cycling through dice options

  pinMode(TFT1_CS, OUTPUT); //initializes screen with CS 1
  digitalWrite(TFT1_CS, HIGH); //sets screen to 'deactivated'

  pinMode(TFT2_CS, OUTPUT); //initializes screen with CS 2
  digitalWrite(TFT2_CS, LOW); //sets screen to 'activated'

  tft.init();
  SPI.begin();
  tft.fillScreen(TFT_BLACK);
}

void loop() {

  diceSelectButtonState = digitalRead(25);
  diceChooseButtonState = digitalRead(26);
  resetButtonState = digitalRead(27);

  if (diceChooseButtonState == LOW && diceChooseLastButtonState == HIGH) {state = diceMove;} 
  else if (diceSelectButtonState == LOW && diceSelectLastButtonState == HIGH) {state = diceDecision;}
  else if (resetButtonState == LOW && resetLastButtonState == HIGH) {state = reset;}

  diceChooseLastButtonState = diceChooseButtonState;
  diceSelectLastButtonState = diceSelectButtonState;
  resetLastButtonState = resetButtonState;

  switch (state) {
    case idle: /*idle*/ break;
    case initial: 
      drawDiceSelectionScene(diceNum, 1); 
      state = idle; 
      break;
    case diceMove:
      diceNum = (diceNum + 1) % 6;
      drawDiceSelectionScene(diceNum, 1);
      state = idle;
      break;
    case diceDecision:
      if (dice.size() <= 5) {
        dice.push_back(diceNum);
        drawDiceAfterSelect(diceNum, 2);
        screenClear(1);
        state = idle;
      }
      break;
    case reset:
      for (int i=1; i<=3; i++) {
        screenClear(i);
      }
      dice.clear();
      diceNum = 0;
      state = idle;
  }
}

void drawDiceSelectionScene(int diceNum, int tftNum) {
  screenClear(tftNum);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  //tft.drawNumber(dice.size(), 200, 120);
  switch (diceNum) {
    case 0: drawd4(1.0, 0.0, 0.0);  tft.drawString("4", 108, 104, 4);  break;
    case 1: drawd6(1.0, 0.0, 0.0);  tft.drawString("6", 108, 104, 4);  break;
    case 2: drawd8(1.0, 0.0, 0.0);  tft.drawString("8", 108, 104, 4);  break;
    case 3: drawd10(1.0, 0.0, 0.0); tft.drawString("10", 104, 104, 4); break;
    case 4: drawd12(1.0, 0.0, 0.0); tft.drawString("12", 104, 112, 4); break;
    case 5: drawd20(1.0, 0.0, 0.0); tft.drawString("20", 104, 112, 4); break;
  }
}

void drawDiceAfterSelect(int diceNum, int tftNum) {
  screenClear(tftNum);
  tft.drawLine(120, 0, 120, 240, TFT_WHITE);
  if (dice.size() % 2 == 0) { //draw on the right side of screen
    switch (diceNum) {
      case 0: drawd4(0.75, 90.0, 30.0);  tft.drawString("4", 180, 120, 4);  break;
      case 1: drawd6(0.75, 90.0, 30.0);  tft.drawString("6", 180, 120, 4);  break;
      case 2: drawd8(0.75, 90.0, 30.0);  tft.drawString("8", 180, 120, 4);  break;
      case 3: drawd10(0.75, 90.0, 30.0); tft.drawString("10", 180, 120, 4); break;
      case 4: drawd12(0.75, 90.0, 30.0); tft.drawString("12", 180, 120, 4); break;
      case 5: drawd20(0.75, 90.0, 30.0); tft.drawString("20", 180, 120, 4); break;
    }
  } else if (dice.size() % 2 == 1) { //draw on the right side of screen
    switch (diceNum) {
      case 0: drawd4(0.75, -30.0, 30.0);  tft.drawString("4", 60, 120, 4);  break;
      case 1: drawd6(0.75, -30.0, 30.0);  tft.drawString("6", 60, 120, 4);  break;
      case 2: drawd8(0.75, -30.0, 30.0);  tft.drawString("8", 60, 120, 4);  break;
      case 3: drawd10(0.75, -30.0, 30.0); tft.drawString("10", 60, 120, 4); break;
      case 4: drawd12(0.75, -30.0, 30.0); tft.drawString("12", 60, 120, 4); break;
      case 5: drawd20(0.75, -30.0, 30.0); tft.drawString("20", 60, 120, 4); break;
    }
  }
}

void screenClear(int tftNum) {
  selectTFT(tftNum);
  tft.fillScreen(TFT_BLACK);
  //tft.drawNumber(dice.size(), 200, 120);
}

void selectTFT(int tftNum) {
  // Deactivate all displays
  digitalWrite(TFT1_CS, HIGH);
  digitalWrite(TFT2_CS, HIGH);
  //digitalWrite(TFT3_CS, HIGH);

  // Activate the selected one
  if (tftNum == 1) {
    digitalWrite(TFT1_CS, LOW);
  } else if (tftNum == 2) {
    digitalWrite(TFT2_CS, LOW);
  }
  // else if (tftNum == 3) {
  //   digitalWrite(TFT3_CS, LOW);
  // }
}
