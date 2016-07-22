
#ifndef __TIMER_OBJ__
#define __TIMER_OBJ__

#include <sys/time.h>

typedef struct timer_callback_st {
	int mType;
	void *data;
	int(*mFunction)(void *aPtr, int type);
}_timer_callback, *timer_callback_t;

timer_callback_t new_timer_callback();

void free_timer_callback(timer_callback_t t);

int timer_callback(timer_callback_t t);

typedef struct timer_obj_st {
	TTimeIntervalMicroSeconds32 m_Interval;
	unsigned int m_cycl_tick;
	unsigned int m_current_tick;
	timer_callback_t mTimer_callback;
} _timerobj, *timer_obj_t;

timer_obj_t new_timer_obj();

void free_timer_obj(timer_obj_t t);

#endif
