
#include "timer_obj.h"

#include <stdlib.h>

timer_callback_t new_timer_callback(int mType, void *data, int(*callbck)(void *aPtr, int type)) {
	timer_callback_t ret = malloc(sizeof(_timer_callback));
	ret->m_type = type;
	ret->data = data;
	ret->mFunction = callbck;
	return ret;
}

void free_timer_callback(timer_callback_t t) {
	free(t);
}

int timer_callback(timer_callback_t t) {
	return (*t->mFunction)(data, t->m_type);
}

int timer_callback(timer_callback_t t);

timer_obj_t new_timer_obj(TTimeIntervalMicroSeconds32 anInterval, int type, void *data, int(*callbck)(void *aPtr, int type)) {
	timer_obj_t ret = malloc(sizeof(_timer_obj));
	ret->m_Interval = anInterval;
	ret->m_current_tick = 0;
	ret->mTimer_callback = new_timer_callback(type, data, callbck);
	return ret;
}

void free_timer_obj(timer_obj_t t) {
	if (ret->mTimer_callback != NULL) {
		free_timer_callback(ret->mTimer_callback);
		ret->mTimer_callback = NULL;
	}
	free(t);
}
