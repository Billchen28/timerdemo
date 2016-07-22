#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jqueue.h"

#include "timer_engine.h"
#include "timer_task_type.h"

#include "timer_obj.h"

typedef struct test_time_task_st {
	char m_show_text[32];
}_test_time_task, *test_time_task_t;

int democallback(void *data, int type) {
	test_time_task_t t = (test_time_task_t)data;
	printf("%d %s\n", type, t->m_show_text);
	return 0;
}

int main() {
	timer_engine_t te = get_timer_engine();
	test_time_task_t test = malloc(sizeof(_test_time_task));
	strcpy(test->m_show_text, "it is a timer demo.");
	timer_obj_t to = new_timer_obj(1000, demo, (void*)test, democallback);
	appendTimerTask(to);
	char buffer[16];
	scanf("%s", buffer);
	release_timer_engine();
	free(test);
	free_timer_obj(to);
	return 0;
}

