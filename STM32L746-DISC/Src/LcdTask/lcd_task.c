#include "stm32l476g_discovery_glass_lcd.h"

#define MAXSTRLENGTH	30
#define LCDLENGTH	6

char display_array[MAXSTRLENGTH*2] = "HELLO BIOINSPIRA HELLO BIOINSPIRA";
unsigned int str_length = 17;

static void show_lcd_str(char* head)
{
  int i;

  for(i=0; i< LCDLENGTH;i++)
    BSP_LCD_GLASS_DisplayChar((head+i), POINT_OFF, DOUBLEPOINT_OFF, i);
}

void StartLcdTask(void const * argument)
{

  /* USER CODE BEGIN StartLcdTask */

  char* current_char = display_array;

  /* Infinite loop */
  for(;;)
  {
    show_lcd_str (current_char++);

    if (current_char >= display_array + str_length)
      current_char = display_array;

    osDelay(500);
  }
  /* USER CODE END StartLcdTask */
}
