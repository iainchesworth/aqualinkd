#ifndef PUMP_H_
#define PUMP_H_

#include "aq_key.h"
#include "protocol_types.h"
#include "pump_types.h"

typedef struct pumpd
{
	int rpm;
	int gpm;
	int watts;
	unsigned char pumpID;
	int pumpIndex;
	pump_type pumpType;
	//int buttonID;
	protocolType prclType;
	aqkey* button;
	//bool updated;
} pump_detail;

#endif // PUMP_H_
