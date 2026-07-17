#include "timer.h"

void Timer_start(Timer_t *timer, uint32_t period)
{
	timer->start_timer = HAL_GetTick();
	timer->period = period;

}


bool Timer_expired(Timer_t *timer)
{
	uint32_t current_time;
	current_time = HAL_GetTick();
	
  if( (current_time - timer->start_timer) >= timer->period )
	{
		timer->start_timer = current_time;
		return true;
	}
	return false;
}

