#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

struct queue_s {
	int count;
	struct elem {
		void *data;
		struct elem *link;
	} *head, *tail;
};

queue_t queue_new(void) {
	queue_t queue;

	queue = malloc(sizeof(*queue));
	if (queue == NULL)
		return NULL;
	queue->count = 0;
	queue->head = NULL;
	queue->tail = NULL;

	return queue;
}

void queue_in(queue_t queue, void *data) {
	assert(queue != NULL && data != NULL);

	struct elem *node;
	node = malloc(sizeof(struct elem));
	assert(node != NULL);
	if (node == NULL)
		return;
	node->data = data;
	node->link = NULL;
	if (queue->tail != NULL)
		queue->tail->link = node;
	queue->tail = node;
	if (queue->head == NULL)
		queue->head = node;
	queue->count++;
}

void *queue_out(queue_t queue) {
	assert(queue != NULL);
	assert(queue->count > 0);

	struct elem *head;
	void *ret;

	head = queue->head;
	queue->head = head->link;
	if (queue->head == NULL)
		queue->tail = NULL;
	queue->count--;

	ret = head->data;
	free(head);

	return ret;
}

void queue_free(queue_t *pqueue) {
	if (pqueue == NULL || *pqueue == NULL)
		return;

	struct elem *ptr, *next;

	for (ptr = (*pqueue)->head; ptr != NULL; ptr = next) {
		next = ptr->link;
		free(ptr);
	}
	free(*pqueue);
	*pqueue = NULL;
}
