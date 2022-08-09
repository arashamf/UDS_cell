extern unsigned int state_sensor_1;
extern unsigned int state_sensor_2;
extern unsigned int state_sensor_3;
extern unsigned int state_sensor_4;
extern unsigned int state_solenoid;
extern unsigned int pre_state_sensor_1;
extern unsigned int pre_state_sensor_2;
extern unsigned int pre_state_sensor_3;
extern unsigned int pre_state_sensor_4;
extern unsigned int pre_state_solenoid;
extern unsigned int state_cell;
extern unsigned int adress_cell;
extern unsigned char buf_rec[4];
extern unsigned int counter_buf;
extern unsigned int counter_solenoid;
extern unsigned char buf[20];
extern unsigned int error;
extern unsigned int counter_error;


//med 1569
#define S1_0_S2_0_low 1413
#define S1_0_S2_0_high 1725
// med 1950
#define S1_1_S2_0_low 1755
#define S1_1_S2_0_high 2145
//med 2543
#define S1_0_S2_1_low 2289
#define S1_0_S2_1_high 2797
//med 3723
#define S1_1_S2_1_low 3473
#define S1_1_S2_1_high 3973

#define Solenoid_max_load_full 2000 //порог 1050мј
//#define Solenoid_min_load_full 150  //250
#define Solenoid_max_load_part 500 
#define Solenoid_min_load_part 50  //порог - 160мј 
