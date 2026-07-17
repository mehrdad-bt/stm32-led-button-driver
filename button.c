#include "button.h"


Event_t Button_update(Button_t *button)
{
	
	GPIO_PinState pin;
	pin = HAL_GPIO_ReadPin(button->port, button->pin);
	uint32_t current_time;
	current_time = HAL_GetTick();
	
	if( current_time - button->last_press_time < 200)
	{	
			button->event = BUTTON_RELEASED;
			return button->event;
	}
		
	if ((pin == GPIO_PIN_RESET) && (button->last_state == true))
	{
      button->last_state = false;
      button->last_press_time = current_time;
			button->event = BUTTON_PRESSED;
      return button->event;
  }
	
	if (pin == GPIO_PIN_SET) 
	{
         button->last_state = true;
				 button->event = BUTTON_RELEASED;
		     return button->event;
  }
	
	return button->event;
}

