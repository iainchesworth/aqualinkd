
#ifndef AQ_PROGRAMMER_H_
#define AQ_PROGRAMMER_H_

#include <pthread.h>
//#include "aqualink.h"
#include "types/program_types.h"
#include "types/pump_types.h"

#define PROGRAMMING_POLL_DELAY_TIME 10
#define PROGRAMMING_POLL_COUNTER 200

// need to get the C values from aqualink manual and add those just incase
// someone has the controller set to C.
#define HEATER_MAX_F 104
#define HEATER_MIN_F 36
#define FREEZE_PT_MAX_F 42
#define FREEZE_PT_MIN_F 34

#define HEATER_MAX_C 40
#define HEATER_MIN_C 0
#define FREEZE_PT_MAX_C 5
#define FREEZE_PT_MIN_C 1

#define SWG_PERCENT_MAX 101
#define SWG_PERCENT_MIN 0

#define PTHREAD_ARG 25
#define LIGHT_MODE_BUFER PTHREAD_ARG

typedef enum emulation_type{
  ALLBUTTON,
  RSSADAPTER,
  ONETOUCH,
  IAQTOUCH,
  AQUAPDA,  // AQUAPALM and PDA are taken as specific type.
  JANDY_DEVICE // Very rarley used.
} emulation_type;




struct programmingThreadCtrl {
  pthread_t thread_id;
  //void *thread_args;
  char thread_args[PTHREAD_ARG];
  struct aqualinkdata *aq_data;
};


//void aq_programmer(program_type type, void *args, struct aqualinkdata *aq_data);
void aq_programmer(program_type type, char *args, struct aqualinkdata *aq_data);
//void kick_aq_program_thread(struct aqualinkdata *aq_data);
void kick_aq_program_thread(struct aqualinkdata *aq_data, emulation_type source_type);
bool in_programming_mode(struct aqualinkdata *aq_data);
bool in_ot_programming_mode(struct aqualinkdata *aq_data);
bool in_iaqt_programming_mode(struct aqualinkdata *aq_data);
bool in_swg_programming_mode(struct aqualinkdata *aq_data);
void aq_send_cmd(unsigned char cmd);
void queueGetProgramData(emulation_type source_type, struct aqualinkdata *aq_data);
//void queueGetExtendedProgramData(emulation_type source_type, struct aqualinkdata *aq_data, bool labels);
unsigned char pop_aq_cmd(struct aqualinkdata *aq_data);


//bool push_aq_cmd(unsigned char cmd);

//void send_cmd(unsigned char cmd, struct aqualinkdata *aq_data);
//void cancel_menu(struct aqualinkdata *aq_data);

//void *set_aqualink_time( void *ptr );
//void *get_aqualink_pool_spa_heater_temps( void *ptr );

int get_aq_cmd_length();
int setpoint_check(int type, int value, struct aqualinkdata *aqdata);
int RPM_check(pump_type type, int value, struct aqualinkdata *aqdata);
//int RPM_check(int type, int value, struct aqualinkdata *aqdata);
const char *ptypeName(program_type type);
const char *programtypeDisplayName(program_type type);

// These shouldn't be here, but just for the PDA AQ PROGRAMMER
bool send_cmd(unsigned char cmd);
bool push_aq_cmd(unsigned char cmd);
void waitForSingleThreadOrTerminate(struct programmingThreadCtrl *threadCtrl, program_type type);
void cleanAndTerminateThread(struct programmingThreadCtrl *threadCtrl);
bool waitForMessage(struct aqualinkdata *aq_data, char* message, int numMessageReceived);

#endif
