#include <SPI.h>
#include <TFT_eSPI.h>
#include <string>
#include <vector>

#define TFT1_CS 22  // Chip Select for the first display
#define TFT2_CS 21  // Chip Select for the second display
#define TFT3_CS 14  // Chip Select for the third display

TFT_eSPI tft = TFT_eSPI();

int diceNum = 0;
std::vector<int> dice;
std::vector<int> rolledResults;
int sum = 0;
int diceType = 0;
int xOffset = 0, yOffset = 0;
int width = 0, height = 0, size = 0;

enum State {
  idle,
  initial,
  diceMove,
  diceDecision,
  roll,
  reset,
};
State state = initial;

// Button States
int diceChooseButtonState = HIGH, diceSelectButtonState = HIGH, resetButtonState = HIGH, rollButtonState = HIGH;
int diceChooseLastButtonState = HIGH, diceSelectLastButtonState = HIGH, resetLastButtonState = HIGH, rollLastButtonState = HIGH;

// Debounce Variables
const unsigned long debounceDelay = 50; // 50ms debounce time
unsigned long lastDiceChooseTime = 0, lastDiceSelectTime = 0, lastResetTime = 0, lastRollTime = 0;
int diceChooseLastState = HIGH, diceSelectLastState = HIGH, resetLastState = HIGH, rollLastState = HIGH;

int c = 0;

void setup(void) {
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  pinMode(TFT1_CS, OUTPUT);
  digitalWrite(TFT1_CS, HIGH);

  pinMode(TFT2_CS, OUTPUT);
  digitalWrite(TFT2_CS, LOW);

  pinMode(TFT3_CS, OUTPUT);
  digitalWrite(TFT3_CS, LOW);

  tft.init();
  SPI.begin();
  //Serial.begin(115200);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
}

void loop() {
  diceChooseButtonState = digitalRead(26);
  diceSelectButtonState = digitalRead(25);
  resetButtonState = digitalRead(27);
  rollButtonState = digitalRead(13);

  // Check if the button state has changed, reset the debounce timer
  if (diceChooseButtonState != diceChooseLastButtonState) {lastDiceChooseTime = millis();}
  if (diceSelectButtonState != diceSelectLastButtonState) {lastDiceSelectTime = millis();}
  if (resetButtonState != resetLastButtonState) {lastResetTime = millis();}
  if (rollButtonState != rollLastButtonState) {lastRollTime = millis();}

  if ((millis() - lastDiceChooseTime) > debounceDelay && diceChooseButtonState != diceChooseLastState) {
    // If the button state has been stable for longer than the debounce delay and the button state has changed
    diceChooseLastState = diceChooseButtonState;
    // Only toggle the state if the new button state is LOW (button pressed)
    if (diceChooseLastState == LOW) {state = diceMove;}
  }

  if ((millis() - lastDiceSelectTime) > debounceDelay && diceSelectButtonState != diceSelectLastState) { //repeat for other buttons
    diceSelectLastState = diceSelectButtonState;
    if (diceSelectLastState == LOW) {state = diceDecision;}
  }

  if ((millis() - lastResetTime) > debounceDelay && resetButtonState != resetLastState) {
    resetLastState = resetButtonState;
    if (resetLastState == LOW) {state = reset;}
  }

  if ((millis() - lastRollTime) > debounceDelay && rollButtonState != rollLastState) {
    rollLastState = rollButtonState;
    if (rollLastState == LOW) {state = roll;}
  }

  diceChooseLastButtonState = diceChooseButtonState;
  diceSelectLastButtonState = diceSelectButtonState;
  resetLastButtonState = resetButtonState;
  rollLastButtonState = rollButtonState;

  switch (state) {
    case idle: break;
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
      if (dice.size() < 5) {
        dice.push_back(diceNum);
        if (dice.size() == 1 || dice.size() == 2) {
          drawDiceAfterSelect(diceNum, 2);
        } else if (dice.size() == 3 || dice.size() == 4) {
          drawDiceAfterSelect(diceNum, 3);
        }
        screenClear(1);
        tft.drawCentreString("Total Dice: " + String(dice.size()), 120, 20, 2);
        state = initial;
      }
      break;
    case roll:
      //tft.drawNumber(diceNum, 120, 180);
      rolledResults.clear();
      for (int die : dice) {
        static const int ranges[] = {5, 7, 9, 10, 13, 21};
        rolledResults.push_back(random(1 - (die == 3), ranges[die]));  
        sum += rolledResults.back();
      }
      for (int i = 0; i < rolledResults.size(); i++) {
        String num = String(rolledResults[i]);
        diceType = dice[i];
        size = (diceType == 5) ? 2 : 4;
        width = 3*size;
        height = 6*size;
        xOffset = 4;
        yOffset = 2;
        if (diceType == 3) { //if a d10 is rolled
          xOffset = 0;
          width += 16;
        } else if (diceType == 4) { //if a d12 is rolled
          xOffset = 0;
          width += 13;
        } else if (diceType == 5) { //if a d20 is rolled
          yOffset = 5;
          width += 9;
        }
        selectTFT(1);
        tft.fillScreen(TFT_BLACK);
        switch(i) { // checks for # of cube, not type of cube
          case 0:
            selectTFT(2); 
            tft.fillRect(48+xOffset, 108+yOffset, width, height, TFT_BLACK);
            tft.drawCentreString(num, 60, (size == 2 || die >= 4) ? 112 : 108, size);
            break;
          case 1: 
            selectTFT(2); 
            tft.fillRect(168+xOffset, 108+yOffset, width, height, TFT_BLACK);
            tft.drawCentreString(num, 180, (size == 2 || die >= 4) ? 112 : 108, size);
            break;
          case 2: 
            selectTFT(3); 
            tft.fillRect(48+xOffset, 108+yOffset, width, height, TFT_BLACK);
            tft.drawCentreString(num, 60, (size == 2 || die >= 4) ? 112 : 108, size);
            break;
          case 3: 
            selectTFT(3); 
            tft.fillRect(168+xOffset, 108+yOffset, width, height, TFT_BLACK);
            tft.drawCentreString(num, 180, (size == 2 || die >= 4) ? 112 : 108, size);
            break;
          case 4: 
            break;
        }
      }
      state = initial;
      break;
    case reset:
      for (int i = 1; i <= 3; i++) {screenClear(i);}
      dice.clear();
      diceNum = 0;
      sum = 0;
      state = initial;
      break;
  }
}

void drawDiceSelectionScene(int diceNum, int tftNum) {
  screenClear(tftNum);
  tft.drawCentreString("Total Dice: " + String(dice.size()), 120, 20, 2);
  switch (diceNum) {
    case 0: drawd4(1.0, 0.0, 0.0);  tft.drawCentreString("4", 120, 108, 4);  break;
    case 1: drawd6(1.0, 0.0, 0.0);  tft.drawCentreString("6", 120, 108, 4);  break;
    case 2: drawd8(1.0, 0.0, 0.0);  tft.drawCentreString("8", 120, 108, 4);  break;
    case 3: drawd10(1.0, 0.0, 4.0); tft.drawCentreString("10", 120, 104, 4); break;
    case 4: drawd12(1.0, 0.0, 4.0); tft.drawCentreString("12", 120, 112, 4); break;
    case 5: drawd20(1.0, 0.0, 4.0); tft.drawCentreString("20", 120, 112, 4); break;
  }
}

void drawDiceAfterSelect(int diceNum, int tftNum) {
  selectTFT(tftNum);
  tft.drawLine(120, 0, 120, 240, TFT_WHITE);
  if (dice.size() % 2 == 0) {
    switch (diceNum) {
      case 0: drawd4(0.75, 90.0, 30.0);    tft.drawCentreString("4", 180, 108, 4);  break;
      case 1: drawd6(-1.05, 204.0, 144.0); tft.drawCentreString("6", 180, 108, 4);  break;
      case 2: drawd8(0.75, 90.0, 30.0);    tft.drawCentreString("8", 180, 108, 4);  break;
      case 3: drawd10(0.5, 120.0, 60.0);   tft.drawCentreString("10", 180, 108, 4); break;
      case 4: drawd12(0.5, 120.0, 60.0);   tft.drawCentreString("12", 180, 108, 4); break;
      case 5: drawd20(0.5, 120.0, 60.0);   tft.drawCentreString("20", 180, 112, 2); break;
    }
  } else {
    switch (diceNum) {
      case 0: drawd4(0.75, -30.0, 30.0); tft.drawCentreString("4", 60, 108, 4);  break;
      case 1: drawd6(0.95, -36.0, 24.0); tft.drawCentreString("6", 60, 108, 4);  break;
      case 2: drawd8(0.75, -30.0, 30.0); tft.drawCentreString("8", 60, 108, 4);  break;
      case 3: drawd10(0.5, 0.0, 60.0);   tft.drawCentreString("10", 60, 108, 4); break;
      case 4: drawd12(0.5, 0.0, 60.0);   tft.drawCentreString("12", 60, 108, 4); break;
      case 5: drawd20(0.5, 0.0, 60.0);   tft.drawCentreString("20", 60, 112, 2); break;
    }
  }
}

void screenClear(int tftNum) {
  selectTFT(tftNum);
  tft.fillScreen(TFT_BLACK);
}

void selectTFT(int tftNum) {
  // Deactivate all displays
  digitalWrite(TFT1_CS, HIGH);
  digitalWrite(TFT2_CS, HIGH);
  digitalWrite(TFT3_CS, HIGH);

  delayMicroseconds(5);
  // Activate the selected one
  if (tftNum == 1) {digitalWrite(TFT1_CS, LOW);} 
  else if (tftNum == 2) {digitalWrite(TFT2_CS, LOW);} 
  else if (tftNum == 3) {digitalWrite(TFT3_CS, LOW);}
}
