#include "handle_cmd.h"
#include "string.h"
#include "driver_led.h"

void handle_cmd(char *buff_cmd, char *cmd, int on_off){
	char *pCmd = strstr(buff_cmd, cmd);
	if(pCmd != NULL){
		pCmd += strlen(cmd);
		if(*pCmd == ':'){
			pCmd++;
			int number = 0;
			while(1){
				if(*pCmd >='0' && *pCmd <= '9'){
					number *= 10;
					number += (*pCmd-'0');
				}
				else if(*pCmd == ','){
					control_led(number, on_off);
					number = 0;
				}
				else if(*pCmd == ';'){
					control_led(number, on_off);
					break;
				}
				++pCmd;
			}
		}
	}
}

