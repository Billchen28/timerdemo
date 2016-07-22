#include <stdio.h>

#include "jqueue.h"

#include "timer_engine.h"

int main() {
	timer_engine_t te = get_timer_engine();
	te->m_id = 1;
	start_engine();
	start_engine();
	jqueue_t jq = jqueue_new();
	char test[16] = "test str 1.";
	jqueue_push(jq, (void *) test, 0);
	while(jqueue_size(jq) > 0) {
            printf("%s\n", (char*)jqueue_pull(jq));
	}
	printf("%d\n", jqueue_size(jq));
	jqueue_free(jq);

	timer_engine_t te2 = get_timer_engine();
        te2->m_id = 2;
        start_engine();
        start_engine();	

	char buffer[16];
	scanf("%s", buffer);
	release_timer_engine();
	release_timer_engine();
	return 0;
}

