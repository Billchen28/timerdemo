#ifndef __TIMER_ENGINE__
#define __TIMER_ENGINE__

#ifndef __TIMER_DEBUG__
#define __TIMER_DEBUG__
#endif

#include "jqueue.h"

typedef struct timer_engine_st {
	jqueue_t mTimerTaskQueue;
	int m_timer_engine_stated;
	int m_id;
}_timer_engine, *timer_engine_t;

static int m_gobal_timer_started = 0;

#define KTimerIntervalUnit 500

timer_engine_t get_timer_engine();

void start_engine();

void stop_engine();

void release_timer_engine();

#endif

