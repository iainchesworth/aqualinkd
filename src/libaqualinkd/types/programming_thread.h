#ifndef PROGRAMMING_THREAD_H_
#define PROGRAMMING_THREAD_H_

#include <pthread.h>
#include "program_types.h"

struct programmingthread {
	pthread_t* thread_id;
	pthread_mutex_t thread_mutex;
	pthread_cond_t thread_cond;
	program_type ptype;
	//void *thread_args;
};

#endif // PROGRAMMING_THREAD_H_
