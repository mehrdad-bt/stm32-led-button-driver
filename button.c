#include "button.h"


bool Button_update(Button_t *button)
{
	
	GPIO_PinState pin;
	pin = HAL_GPIO_ReadPin(button->port, button->pin);
	uint32_t current_time;
	current_time = HAL_GetTick();
	
	if( current_time - button->last_press_time < 200)
	{	
			return false;
	}
		
	if ((pin == GPIO_PIN_RESET) && (button->last_state == true))
	{
      button->last_state = false;
      button->last_press_time = current_time;
      return true;
  }
	
	if (pin == GPIO_PIN_SET) 
	{
         button->last_state = true;
		     return false;
  }
	
	
}

