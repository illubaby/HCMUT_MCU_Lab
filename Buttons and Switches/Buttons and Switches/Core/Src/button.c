#include "button.h"

#define NUMBER_OF_BUTTONS 4  // Adjust this value according to your actual number of buttons
GPIO_TypeDef* BUTTON_GPIO_Port[] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t BUTTON_Pin[] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int KeyReg[NUMBER_OF_BUTTONS][4] = {0};  // [ButtonIndex][KeyReg0, KeyReg1, KeyReg2, KeyReg3]
int TimeOutForKeyPress[NUMBER_OF_BUTTONS] = {500};  // Initialize all to 500ms
int button_flags[NUMBER_OF_BUTTONS] = {0};  // Initialize all to 0

// Check if button is pressed
int isButtonPressed(int button_index){
	if(button_flags[button_index] == 1){
		button_flags[button_index] = 0;
		return 1;
	}
	return 0;
}

// Sample function for handling button press
void subKeyProcess(int button_index){
	// TODO: Add your code here
	HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
	button_flags[button_index] = 1;
}

// Debouncing function
void getKeyInput(){
	for(int i = 0; i < NUMBER_OF_BUTTONS; ++i) {
		KeyReg[i][0] = KeyReg[i][1];
		KeyReg[i][1] = KeyReg[i][2];
		// Replace with your actual GPIO Read function for each button
		KeyReg[i][2] = HAL_GPIO_ReadPin(BUTTON_GPIO_Port[i], BUTTON_Pin[i]);


		if ((KeyReg[i][1] == KeyReg[i][0]) && (KeyReg[i][1] == KeyReg[i][2])){
			if (KeyReg[i][3] != KeyReg[i][2]){
				KeyReg[i][3] = KeyReg[i][2];
				if (KeyReg[i][2] == PRESSED_STATE){
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					TimeOutForKeyPress[i] = 200;
					if (KeyReg[i][2] == PRESSED_STATE){
						subKeyProcess(i);
					}
				}
			}
		}
	}
}
