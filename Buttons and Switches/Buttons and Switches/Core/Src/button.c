#include "button.h"

#define NUMBER_OF_BUTTONS 3 // Or however many buttons you have

typedef struct {
  int KeyReg0;
  int KeyReg1;
  int KeyReg2;
  int KeyReg3;
  int TimeOutForKeyPress;
  int flag;
  uint16_t gpio_pin;
  GPIO_TypeDef* gpio_port;
} Button;

Button buttons[NUMBER_OF_BUTTONS] = {
  {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, BUTTON1_Pin, BUTTON1_GPIO_Port},
  {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, BUTTON2_Pin, BUTTON2_GPIO_Port},
  {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, 500, 0, BUTTON3_Pin, BUTTON3_GPIO_Port}
};

void subKeyProcess(int index) {
	HAL_GPIO_TogglePin ( TEST_GPIO_Port, TEST_Pin ) ;
	buttons[index].flag = 1;
}

int isButtonPressed(int index){
  if(buttons[index].flag == 1) {
    buttons[index].flag = 0;
    return 1;
  }
  return 0;
}

void getKeyInput() {
  int i;
  for(i = 0; i < NUMBER_OF_BUTTONS; i++) {
    Button *b = &buttons[i];
    b->KeyReg0 = b->KeyReg1;
    b->KeyReg1 = b->KeyReg2;
    b->KeyReg2 = HAL_GPIO_ReadPin(b->gpio_port, b->gpio_pin);

    if ((b->KeyReg1 == b->KeyReg0) && (b->KeyReg1 == b->KeyReg2)){
      if (b->KeyReg3 != b->KeyReg2){	// update state
        b->KeyReg3 = b->KeyReg2;
        if (b->KeyReg2 == PRESSED_STATE) {
          subKeyProcess(i);
        }
      } else {
        b->TimeOutForKeyPress--;
        if (b->TimeOutForKeyPress == 0){
          b->TimeOutForKeyPress = 200;
          if (b->KeyReg2 == PRESSED_STATE){	// handle long press
            subKeyProcess(i);
          }
        }
      }
    }
  }
}
