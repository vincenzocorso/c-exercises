CFLAGS		:=		-Wall

OBJS		:=		$(patsubst %.c, %.o, $(filter-out $(wildcard lib*.c), $(wildcard *.c)))
LIB			:=		libqueue.a
OUT			:=		main

$(OUT):		$(LIB) $(OBJS)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $(OBJS) -o $@ -L. -l:$(LIB)

%.a:		%.o
			@echo "Compiling library..."
			ar rcs $(LIB) $^

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

.PHONY:	clean
clean:
		@echo "Cleaning..."
		rm -f *.o *.a $(OUT)
		
test:
		@echo $(patsubst %.c, %.o, $(wildcard *.c))
		@echo $(wildcard lib*.c)
		@echo $(OBJS)
		
