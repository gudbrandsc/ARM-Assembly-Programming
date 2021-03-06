PROGS = driver

OBJS = sum_array_c.o sum_array_s.o find_max_c.o find_max_s.o fib_iter_c.o fib_iter_s.o fib_rec_c.o fib_rec_s.o find_str_c.o find_str_s.o
CFLAGS = -g

%.o : %.s
	as -o $@ $<

%.o : %.c
	gcc -c ${CFLAGS} -o $@ $<

all : ${PROGS}

driver : driver.c ${OBJS}
	gcc -o driver driver.c ${OBJS}

clean :
