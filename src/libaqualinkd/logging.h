#ifndef LOGGING_H_
#define LOGGING_H_

#include <syslog.h>

// Defined as int16_t so 16 bits to mask
#define AQUA_LOG (1 << 0) // Aqualink Generic / catchall
#define NET_LOG  (1 << 1) // Network
// Control protocols
#define AQRS_LOG (1 << 2) // Allbutton RS Keypad
#define ONET_LOG (1 << 3) // OneTouch
#define IAQT_LOG (1 << 4) // iAqualinkTouch
#define PDA_LOG  (1 << 5) // PDA
#define RSSA_LOG (1 << 6) // Serial Adapter
// Message PRotocols
#define DJAN_LOG (1 << 7) // Jange Device
#define DPEN_LOG (1 << 8) // Pentair Device
// misc
#define RSSD_LOG (1 << 9) // RS485 Connection /dev/ttyUSB?
#define PROG_LOG (1 << 10) // Programmer
#define DBGT_LOG (1 << 11) // Debug Timer

#define LOG_DEBUG_SERIAL 8

//void LOG(int from, int level, char *format, ...);
void LOG(int16_t from, int msg_level, const char* format, ...);

#endif // LOGGING_H_
