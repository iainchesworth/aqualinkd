#ifndef CLIGHT_TYPES_H_
#define CLIGHT_TYPES_H_

// color light modes (Aqualink program, Jandy, Jandy LED, SAm/SAL, Color Logic, Intellibrite)
typedef enum clight_type {
	LC_PROGRAMABLE = 0,
	LC_JANDY,
	LC_JANDYLED,
	LC_SAL,
	LC_CLOGIG,
	LC_INTELLIB
} clight_type;

#endif // CLIGHT_TYPES_H_
