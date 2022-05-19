#include "stm32l1xx.h"                  // Device header
#include "gpio_config.h"

int main() {
	InitUserLED();
	
	OnUserLED();
}
