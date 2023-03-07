
#ifndef AQUALINK_H_
#define AQUALINK_H_

#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include "aq_serial.h"
#include "types/action.h"
#include "types/aq_key.h"
#include "types/clight.h"
#include "types/panel_buttons.h"
#include "types/programming_thread.h"
#include "types/program_types.h"
#include "types/pump.h"
#include "types/temperature_types.h"

#define DEFAULT_POLL_SPEED -1
#define DEFAULT_POLL_SPEED_NON_THREADDED 2

#define TIME_CHECK_INTERVAL  3600
#define ACCEPTABLE_TIME_DIFF 120

// Use these settings to test time
//#define TIME_CHECK_INTERVAL  100
//#define ACCEPTABLE_TIME_DIFF 10

#define MAX_ZERO_READ_BEFORE_RECONNECT 10000 // 2k normally

void intHandler(int dummy);
void setUnits(const char *msg);

// There are cases where SWG will read 80% in allbutton and 0% in onetouch/aqualinktouch, this will compile that in or our
//#define READ_SWG_FROM_EXTENDED_ID

//#define TOTAL_BUTTONS     12
/*
#ifndef AQ_RS16
#define TOTAL_BUTTONS          12
#else
#define TOTAL_BUTTONS          20
#define RS16_VBUTTONS_START    13  // RS16 panel has 4 buttons with no LED's, so list them for manual matching to RS messages
#define RS16_VBUTTONS_END      16  // RS16 panel has 4 buttons with no LED's, so list them for manual matching to RS messages
#endif
*/
#define TEMP_UNKNOWN    -999
//#define UNKNOWN TEMP_UNKNOWN
#define DATE_STRING_LEN   30

#define MAX_PUMPS 4
#define MAX_LIGHTS 4

// special_mask
#define VS_PUMP        (1 << 0)
#define PROGRAM_LIGHT  (1 << 1)
#define TIMER_ACTIVE   (1 << 2) // Not used yet, but will need to timer

//typedef struct ProgramThread ProgramThread;  // Definition is later


// Moved to aq_programmer to stop circular dependancy
/*
typedef enum pump_type {
  PT_UNKNOWN = -1,
  EPUMP,
  VSPUMP,
  VFPUMP
} pump_type;
*/

#define PUMP_PRIMING -1
#define PUMP_OFFLINE -2
#define PUMP_ERROR   -3
#define PUMP_OFF_RPM 0
#define PUMP_OFF_GPM PUMP_OFF_RPM
#define PUMP_OFF_WAT PUMP_OFF_RPM

struct aqualinkdata
{
  char version[AQ_MSGLEN*2];
  char date[AQ_MSGLEN];
  char time[AQ_MSGLEN];
  char last_message[AQ_MSGLONGLEN+1]; // Last ascii message from panel - allbutton (or PDA) protocol
  char last_display_message[AQ_MSGLONGLEN+1]; // Last message to display in web UI
  aqled aqualinkleds[TOTAL_LEDS];
  aqkey aqbuttons[TOTAL_BUTTONS];
  unsigned short total_buttons;
  int air_temp;
  int pool_temp;
  int spa_temp;
  int temp_units;
  //bool single_device; // Pool or Spa only, not Pool & Spa (Thermostat setpoints are different)
  int battery;
  int frz_protect_set_point;
  int pool_htr_set_point;
  int spa_htr_set_point;
  int swg_percent;
  int swg_ppm;
  unsigned char ar_swg_device_status; // Actual state 
  aqledstate swg_led_state; // Display state for UI's
  aqledstate service_mode_state;
  aqledstate frz_protect_state;
  int num_pumps;
  pump_detail pumps[MAX_PUMPS];
  int num_lights;
  clight_detail lights[MAX_LIGHTS];
  bool boost;
  char boost_msg[10];
  float ph;
  int orp;

  // Below this line is not state related. (Future just do a mem compare for change)
  //aqkey *orderedbuttons[TOTAL_BUTTONS]; // Future to reduce RS4,6,8,12,16 & spa buttons
  //unsigned short total_ordered_buttons;
  unsigned char last_packet_type;
  int swg_delayed_percent;
  bool simulate_panel;
  int open_websockets;
  struct programmingthread active_thread;
  struct action unactioned;
  unsigned char raw_status[AQ_PSTLEN];
  // Multiple threads update this value.
  volatile bool updated;

  #ifdef AQ_RS16
  int rs16_vbutton_start;
  int rs16_vbutton_end;
  #endif
  #ifdef AQ_PDA
  int pool_heater_index;
  int spa_heater_index;
  int solar_heater_index;
  #endif
  // Timing for DEBUG
  struct timespec last_active_time;
  struct timespec start_active_time;
  pthread_mutex_t mutex;
  pthread_cond_t thread_finished_cond;
  struct tm tm;
};


#endif 
