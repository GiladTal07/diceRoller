#include <SPI.h>
#include <TFT_eSPI.h>

#define TFT1_CS 21  // Chip Select for the first display
#define TFT2_CS 22  // Chip Select for the second display

TFT_eSPI tft = TFT_eSPI();
int diceChooseButtonState = 0;
int diceChooseLastButtonState = 0;
int diceSelectButtonState = 0;
int diceSelectLastButtonState = 0;
int diceNum = 0;
int diceDecided = 0;
int temp = 1;

void setup(void) {
  pinMode(25, INPUT_PULLUP);  // Button for selecting the dice
  pinMode(26, INPUT_PULLUP);  // Button for cycling through dice options

  pinMode(TFT1_CS, OUTPUT); //initializes screen with CS 1
  digitalWrite(TFT1_CS, HIGH); //sets screen to 'deactivated'

  pinMode(TFT2_CS, OUTPUT); //initializes screen with CS 2
  digitalWrite(TFT2_CS, HIGH); //sets screen to 'deactivated'

  tft.init();
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  while (diceDecided == 0) {
    digitalWrite(TFT1_CS, LOW);
    diceSelectButtonState = digitalRead(25);
    diceChooseButtonState = digitalRead(26);

    // Check for dice selection button (pin 26)
    if (diceChooseButtonState == LOW && diceChooseLastButtonState == HIGH) {
      diceNum = (diceNum + 1) % 6;
      tft.fillScreen(TFT_BLACK);
      delay(50);
    }
    diceChooseLastButtonState = diceChooseButtonState;

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    // Draw dice based on current selection
    switch (diceNum) {
      case 0:
        drawd4();
        tft.drawString("4", 108, 104, 4);
        break;
      case 1:
        drawd6();
        tft.drawString("6", 108, 104, 4);
        break;
      case 2:
        drawd8();
        tft.drawString("8", 108, 104, 4);
        break;
      case 3:
        drawd10();
        tft.drawString("10", 104, 104, 4);
        break;
      case 4:
        drawd12();
        tft.drawString("12", 104, 112, 4);
        break;
      case 5:
        drawd20();
        tft.drawString("20", 104, 112, 4);
        break;
    }

    // If the button on pin 25 is pressed (with debounce)
    if (diceSelectButtonState == LOW && diceSelectLastButtonState == HIGH) {
      diceDecided = diceNum+1;
      delay(50);  // Simple debounce
    }
    diceSelectLastButtonState = diceSelectButtonState;
  }

  // Display the selected dice number once
  if (temp) {
    digitalWrite(TFT1_CS, HIGH);  // Deactivate first screen
    digitalWrite(TFT2_CS, LOW);   // Activate second screen
    tft.fillScreen(TFT_BLACK);
    tft.drawNumber(diceDecided, 120, 120, 4);
    digitalWrite(TFT2_CS, HIGH);  // Deactivate second screen
    temp = 0;
  }
}


