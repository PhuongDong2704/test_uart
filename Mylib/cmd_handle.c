#include "cmd_handle.h"
#include "led_handle.h" 
#include "string.h" 
void cmd_handle (char *buff_cmd, char *cmd, int on_off)
{
	char *pCmd = strstr (buff_cmd, cmd);
	 if (pCmd != NULL )
	 {
		 pCmd += strlen(cmd);
		 if (*pCmd == ':')
		 {
			 pCmd ++;
			 int number = 0;
			 while (1)
			 {
				 if (*pCmd >= '0' && *pCmd <= '9')
				 {
					 number *= 10;
					 number += (*pCmd - '0');
				 }
				 else if (*pCmd == ',')
				 {
					 led_handle(number, on_off);
					 number = 0;
				 }
				 else if (*pCmd == ';')
				 {
					 led_handle(number, on_off);
					 break;
				 }
				 pCmd ++;
			 }
		 }
	 }
}	
