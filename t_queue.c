#include <stdio.h>
#include <stdlib.h>
#include <error.h>

#include "queue.h"

int main(void)
{
	int i, array[10];
	queue_t queue;

	queue = queue_new();
	if (queue == NULL)
		error(EXIT_FAILURE, 0, "create queue error");

	for (i = 0; i < 10; i++)
		array[i] = i + 1;

	for (i = 0; i < 10; i++)
		queue_in(queue, &array[i]);

	for (i = 0; i < 10; i++)
		printf("%d ", *(int *)queue_out(queue));
	printf("\n");

	queue_free(&queue);

	return 0;
}
