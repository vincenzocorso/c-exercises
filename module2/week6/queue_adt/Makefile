CFLAGS		=	-Wall

OUT			=	main
LIB			=	libqueue.a

OBJS		=	queueitem.o

$(OUT):		$(LIB) $(OBJS)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $@.c $(OBJS) -o $@ -L. -l:$(LIB)

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

%.a:		%.o
			@echo "Compiling library..."
			ar rcs $@ $^

.PHONY:	clean
clean:
			@echo "Cleaning..."
			rm -f *.o *.a $(OUT)
