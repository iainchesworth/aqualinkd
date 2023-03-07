#ifndef CLIGHT_H_
#define CLIGHT_H_

#include "aq_key.h"
#include "clight_types.h"

typedef struct clightd
{
	clight_type lightType;
	aqkey* button;
} clight_detail;

#endif // CLIGHT_H_
