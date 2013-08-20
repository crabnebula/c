CFLAGS := -g -Wall -Werror

PROG := t_stack t_queue

all : $(PROG)

t_stack : t_stack.c stack.c stack.h
t_queue : t_queue.c queue.c stack.h

clean:
	@rm -v $(PROG)
