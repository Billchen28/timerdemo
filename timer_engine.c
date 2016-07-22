#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#include "timer_engine.h"

static timer_engine_t g_timer_engine = NULL;

void do_tick(timer_engine_t t_e) {
	printf("do_tick, id:%d\n", t_e->m_id);
}

void tick(int arg) {
	if (g_timer_engine != NULL) {
		do_tick(g_timer_engine);
	}
}

timer_engine_t get_timer_engine() {
	if (g_timer_engine == NULL) {
		timer_engine_t ret = malloc(sizeof(_timer_engine));
		ret->m_timer_engine_stated = 0;
		ret->mTimerTaskQueue = NULL;
		g_timer_engine = ret;
	}
	return g_timer_engine;
}

void release_timer_engine(timer_engine_t t_e) {
	if (g_timer_engine == NULL) {
		return;
	}
	stop_engine();
	free(g_timer_engine);
	g_timer_engine = NULL;
}

void start_engine() {
	if (g_timer_engine == NULL || g_timer_engine->m_timer_engine_stated) {
		return;
	}
	signal(SIGALRM, tick);
        struct itimerval timeInterval;

        unsigned int secondUnit = 0;
        unsigned int msUnit = 0;
        if (KTimerIntervalUnit > 1000)
        {
                secondUnit = KTimerIntervalUnit / 1000;
                msUnit = KTimerIntervalUnit % 1000;
        } else {
                msUnit = KTimerIntervalUnit;
        }
        timeInterval.it_value.tv_sec = secondUnit;
        timeInterval.it_value.tv_usec = msUnit * 1000;
        timeInterval.it_interval.tv_sec  = secondUnit;
        timeInterval.it_interval.tv_usec = msUnit * 1000;
        int ret = 0;
        ret = setitimer(ITIMER_REAL , &timeInterval, NULL);
        if ( ret != 0)
        {
		g_timer_engine->m_timer_engine_stated = 0;
#ifdef __TIMER_DEBUG__
                printf("start gobal timer fail\n");
#endif
        }
        else
        {
		g_timer_engine->m_timer_engine_stated = 1;
#ifdef __TIMER_DEBUG__
                printf("start gobal timer ok\n");
#endif
        }
}

void stop_engine() {
	if (g_timer_engine == NULL || !g_timer_engine->m_timer_engine_stated) {
		return;
	}
	signal(SIGALRM, tick);
	struct itimerval timeInterval;
	timeInterval.it_value.tv_sec = 0;
	timeInterval.it_value.tv_usec = 0;
	timeInterval.it_interval.tv_sec  = 0;
	timeInterval.it_interval.tv_usec = 0;
	int ret = 0;
	ret = setitimer(ITIMER_REAL , &timeInterval, NULL);
	if ( ret != 0)
	{
#ifdef __TIMER_DEBUG__
		printf("stop gobal timer fail\n");
#endif
	}
	else
	{
		g_timer_engine->m_timer_engine_stated = 0;
#ifdef __TIMER_DEBUG__
		printf("stop gobal timer ok\n");
#endif
	}
}

