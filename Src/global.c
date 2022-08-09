#include "global.h"
//states of sensors
//=0 not pressed
//=1 pressed
//=2 break
//=3 short circuit
unsigned int state_sensor_1=0;
unsigned int state_sensor_2=0;
unsigned int state_sensor_3=0;
unsigned int state_sensor_4=0;
unsigned int state_solenoid=0;
unsigned int pre_state_sensor_1=0;
unsigned int pre_state_sensor_2=0;
unsigned int pre_state_sensor_3=0;
unsigned int pre_state_sensor_4=0;
unsigned int pre_state_solenoid=0;
unsigned int counter_solenoid=0;
unsigned int error=0;
unsigned int counter_error=0;

//states of cell
//=0 no packet
//=1 packet coming
unsigned int state_cell=0;
unsigned int adress_cell=0;

unsigned char buf_rec[4];
unsigned int counter_buf=0;
unsigned char buf[20];
