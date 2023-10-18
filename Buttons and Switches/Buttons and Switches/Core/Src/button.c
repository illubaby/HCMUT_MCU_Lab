#include "button.h"
#include "main.h"
#define NUMBER_OF_BUTTONS 3

int KeyReg0[NUMBER_OF_BUTTONS];
int KeyReg1[NUMBER_OF_BUTTONS];
int KeyReg2[NUMBER_OF_BUTTONS];
int KeyReg3[NUMBER_OF_BUTTONS];
int TimeOutForKeyPress[NUMBER_OF_BUTTONS];
int flag[NUMBER_OF_BUTTONS];
uint16_t gpio_pin[NUMBER_OF_BUTTONS] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};
GPIO_TypeDef* gpio_port[NUMBER_OF_BUTTONS] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};

void initializeArrays_for_Button() {
  for (int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
    KeyReg0[i] = NORMAL_STATE;
    KeyReg1[i] = NORMAL_STATE;
    KeyReg2[i] = NORMAL_STATE;
    KeyReg3[i] = NORMAL_STATE;
    TimeOutForKeyPress[i] = 500;
    flag[i] = 0;
  }
}
void subKeyProcess(int index) {
  HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
  flag[index] = 1;
}

int isButtonPressed(int index){
  if(flag[index] == 1) {
    flag[index] = 0;
    return 1;
  }
  return 0;
}

void getKeyInput() {
  for(int i = 0; i < NUMBER_OF_BUTTONS; i++) {
    KeyReg0[i] = KeyReg1[i];
    KeyReg1[i] = KeyReg2[i];
    KeyReg2[i] = HAL_GPIO_ReadPin(gpio_port[i], gpio_pin[i]);

    if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
      if (KeyReg3[i] != KeyReg2[i]){
        KeyReg3[i] = KeyReg2[i];
        if (KeyReg2[i] == PRESSED_STATE) {
          subKeyProcess(i);
        }
      } else {
        TimeOutForKeyPress[i]--;
        if (TimeOutForKeyPress[i] == 0){
          TimeOutForKeyPress[i] = 200;
          if (KeyReg2[i] == PRESSED_STATE){
            subKeyProcess(i);
          }
        }
      }
    }
  }
}
