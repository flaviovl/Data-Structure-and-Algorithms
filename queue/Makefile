CC=clang
#CC = gcc

CFLAGS=-Wall -g
# CFLAGS = -fPIC -Wall -Wextra -O2 -g

LDFLAGS = -shared
RM = rm -f
TARGET_LIB = libtarget.so

SRCS = queue_ll.c qll_test.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${OBJS} $(SRCS:.c=.d)


