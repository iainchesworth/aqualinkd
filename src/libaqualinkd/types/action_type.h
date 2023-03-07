#ifndef ACTION_TYPE_H_
#define ACTION_TYPE_H_

typedef enum action_type {
	NO_ACTION = -1,
	POOL_HTR_SETOINT,
	SPA_HTR_SETOINT,
	FREEZE_SETPOINT,
	SWG_SETPOINT,
	SWG_BOOST,
	PUMP_RPM,
	PUMP_VSPROGRAM,
	POOL_HTR_INCREMENT,   // Setpoint add value (can be negative)
	SPA_HTR_INCREMENT    // Setpoint add value
} action_type;

#endif // ACTION_TYPE_H_
