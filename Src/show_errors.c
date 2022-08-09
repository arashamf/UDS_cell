#include "pins.h"
#include "timer.h"		  	
#include "show_errors.h"
#include "global.h"

#define START_DELAY 1000
#define INTERVAL_DELAY 300

void CheckErrors(void)
{
	adress_cell=ReadAdr();
	if((adress_cell==0)||(adress_cell>14)){error=WRONG_ADRESS;return;}
	
	if((state_sensor_1==2)&&(state_sensor_2==2)){error=BREAK_1_2_BUTTON;return;}
	if((state_sensor_1==3)&&(state_sensor_2==3)){error=SHORT_1_2_BUTTON;return;}
	if((state_sensor_3==2)&&(state_sensor_4==2)){error=BREAK_3_4_BUTTON;return;}
	if((state_sensor_3==3)&&(state_sensor_4==3)){error=SHORT_3_4_BUTTON;return;}
	if(state_solenoid==2){error=BREAK_SOLENOID;return;}
	if(state_solenoid==3){error=SHORT_SOLENOID;return;}
	
	error=0;
}


void ShowErrors(void)
{
	counter_error++;
	switch(error)
	{
		case BREAK_1_2_BUTTON:  //2 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			counter_error=0; 
			break;
		case SHORT_1_2_BUTTON:  //3 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*4) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*5) { LED_RED(1); return; } 
			counter_error=0; 
			break;
		case BREAK_3_4_BUTTON:  //4 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*4) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*5) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*6) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*7) { LED_RED(1); return; } 
			counter_error=0; 
			break;
		case SHORT_3_4_BUTTON:  //5 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*4) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*5) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*6) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*7) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*8) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*9) { LED_RED(1); return; } 
			counter_error=0; 
			break;
		case BREAK_SOLENOID:  //6 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*4) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*5) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*6) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*7) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*8) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*9) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*10) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*11) { LED_RED(1); return; } 
			counter_error=0;
			break;
		case SHORT_SOLENOID:  //7 blink
			if(counter_error<START_DELAY) { LED_RED(0); return; } 			
			if(counter_error<START_DELAY+INTERVAL_DELAY*1) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*2) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*3) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*4) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*5) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*6) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*7) { LED_RED(1); return; } 
			if(counter_error<START_DELAY+INTERVAL_DELAY*8) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*9) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*10) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*11) { LED_RED(1); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*12) { LED_RED(0); return; }  
			if(counter_error<START_DELAY+INTERVAL_DELAY*13) { LED_RED(1); return; } 
			counter_error=0;
			break;
		case WRONG_ADRESS:  
			LED_RED(1);
			counter_error=0;
			break;
		default:
			LED_RED(0);   
			break;
	}
}



