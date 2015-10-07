#include <glib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int i;
	GQueue* queue = g_queue_new();

	for(i = 0; i < argc; i++){
		g_queue_push_head(queue, argv[i]);
	}
	
	while(!g_queue_is_empty(queue)){
		printf("%s\n", (char*) g_queue_pop_head(queue));
	}
	return 0;
}

