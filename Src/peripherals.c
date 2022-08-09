#include "peripherals.h"
#include "pins.h"
#include "global.h"
#include "adc.h"
#include "tim.h"
#include "show_errors.h"

unsigned int counter_1=0;
unsigned int counter_2=0;
unsigned int counter_3=0;
unsigned int counter_4=0;
unsigned int avg_solenoid_current=0;
unsigned int avg_adc_1=0;
unsigned int avg_adc_2=0;

void ReadButtons (void)
{
		unsigned int  tmp=0;
	
		//Reading ADC
		avg_adc_1=(avg_adc_1*9+ADC_GetValue(1))/10;
		tmp=avg_adc_1;
	
		if(tmp<S1_0_S2_0_low){pre_state_sensor_1=2;pre_state_sensor_2=2;}
		else if((tmp<=S1_0_S2_0_high)&&(tmp>=S1_0_S2_0_low)){pre_state_sensor_1=0;pre_state_sensor_2=0;}
		else if((tmp<=S1_1_S2_0_high)&&(tmp>=S1_1_S2_0_low)){pre_state_sensor_1=1;pre_state_sensor_2=0;}
		else if((tmp<=S1_0_S2_1_high)&&(tmp>=S1_0_S2_1_low)){pre_state_sensor_1=0;pre_state_sensor_2=1;}
		else if((tmp<=S1_1_S2_1_high)&&(tmp>=S1_1_S2_1_low)){pre_state_sensor_1=1;pre_state_sensor_2=1;}
		else if(tmp>S1_1_S2_1_high){pre_state_sensor_1=3;pre_state_sensor_2=3;}
		else {pre_state_sensor_1=2;pre_state_sensor_2=2;}
				
		
		/*avg_adc_2=(avg_adc_2*9+ADC_GetValue(2))/10;
		tmp=avg_adc_2;
		
		if(tmp<S1_0_S2_0_low){pre_state_sensor_3=2;pre_state_sensor_4=2;}
		else if((tmp<=S1_0_S2_0_high)&&(tmp>=S1_0_S2_0_low)){pre_state_sensor_3=0;pre_state_sensor_4=0;}
		else if((tmp<=S1_1_S2_0_high)&&(tmp>=S1_1_S2_0_low)){pre_state_sensor_3=1;pre_state_sensor_4=0;}
		else if((tmp<=S1_0_S2_1_high)&&(tmp>=S1_0_S2_1_low)){pre_state_sensor_3=0;pre_state_sensor_4=1;}
		else if((tmp<=S1_1_S2_1_high)&&(tmp>=S1_1_S2_1_low)){pre_state_sensor_3=1;pre_state_sensor_4=1;}
		else if(tmp>S1_1_S2_1_high){pre_state_sensor_3=3;pre_state_sensor_4=3;}
		else {pre_state_sensor_3=2;pre_state_sensor_3=2;}*/

		//Check debounce
		if(pre_state_sensor_1!=state_sensor_1){counter_1++;}
		else{counter_1=0;}
		if(counter_1==50){counter_1=0;state_sensor_1=pre_state_sensor_1;}
		
		if(pre_state_sensor_2!=state_sensor_2){counter_2++;}
		else{counter_2=0;}
		if(counter_2==50){counter_2=0;state_sensor_2=pre_state_sensor_2;}
		
	/*	if(pre_state_sensor_3!=state_sensor_3){counter_3++;}
		else{counter_3=0;}
		if(counter_3==50){counter_3=0;state_sensor_3=pre_state_sensor_3;}
		
		if(pre_state_sensor_4!=state_sensor_4){counter_4++;}
		else{counter_4=0;}
		if(counter_4==50){counter_4=0;state_sensor_4=pre_state_sensor_4;}*/
}


void SetSolenoid (void)
{
	unsigned int  tmp=0;
	
	avg_solenoid_current=(avg_solenoid_current*9 + ADC_GetValue(0))/10;
	tmp=ADCtoCurrent(avg_solenoid_current);	
	
	//Solenoid current checking
	if(counter_solenoid>0){
		
		counter_solenoid++;

				
		if(counter_solenoid<350)
		{
			if(tmp>Solenoid_max_load_full)
			{
				counter_solenoid=0;
				SolenoidOff();
				state_solenoid=3;
				pre_state_solenoid=3;
			}
		}
				
		if(counter_solenoid==300)
		{
			SolenoidOnPart();
		}
		
		if(counter_solenoid>350)
		{
			counter_solenoid=350;
			if(tmp>Solenoid_max_load_part)
			{
				counter_solenoid=0;
				SolenoidOff();
				state_solenoid=3;
				pre_state_solenoid=3;
			}	
			if(tmp<Solenoid_min_load_part)
			{
				counter_solenoid=0;
				SolenoidOff();
				state_solenoid=2;
				pre_state_solenoid=2;
			}
		}		
	}		
}



