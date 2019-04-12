CFLAGS	=	-Wall

OBJS	=	item.o
OUT		=	list
LIB		=	libqueue.a

$(OUT):		$(LIB) $(OBJS)
			@echo "Creating executable"
			$(CC) $(CFLAGS) $@.c $(OBJS) -o $@ -L. -l:$(LIB)
			@./$(OUT)

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
			@echo "Cleaning..."
			rm -f *.o $(OUT)
