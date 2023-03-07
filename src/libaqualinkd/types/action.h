#ifndef ACTION_H_
#define ACTION_H_

#include <time.h>

#include "action_type.h"

struct action {
	action_type type;
	time_t requested;
	int value;
	int id; // Only used for Pumps at the moment.
	//char value[10];
};

#endif // ACTION_H_
