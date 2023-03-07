#ifndef AQ_KEY_H_
#define AQ_KEY_H_

#include <stdint.h>

#include "aq_led.h"

typedef struct aqualinkkey
{
	//int number;
	//aqledstate *state;
	aqled* led;
	char* label;
	char* name;
	//#ifdef AQ_PDA
	//  char *pda_label;
	//#endif
	unsigned char code;
	int dz_idx;
	int hab_id;
	uint8_t special_mask;
} aqkey;

#endif // AQ_KEY_H_
