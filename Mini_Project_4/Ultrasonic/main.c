#include "std_types.h"
#include "Ultrasonic.h"
#include "icu.h"
#include "lcd.h"
#include "avr/delay.h"


uint16 distance=0;

int main()
{
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance=    cm");

	while(1)
	{
		/* (-2) to minimize the error percentage
		 * as there is error varies from (+3) to (no error) as we increase ultrasonic distance */
		distance= Ultrasonic_readDistance()-2;
		LCD_moveCursor(0,10);

		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		_delay_ms(100);
	}

}
