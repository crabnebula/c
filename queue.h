#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct queue_s *queue_t;

queue_t queue_new(void);
int queue_empty(queue_t queue);
void queue_in(queue_t queue, void *data);
void *queue_out(queue_t queue);
void queue_free(queue_t *queue);

#endif
