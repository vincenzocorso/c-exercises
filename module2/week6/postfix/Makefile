CFLAGS		=	-Wall

OUT			=	postfix
LIB			=	libstack.a

OBJS		=	stackitem.o

$(OUT):		$(LIB) $(OBJS)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $@.c $(OBJS) -o $@ -L. -l:$(LIB)

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

.PHONY:	clean
clean:
			@echo "Cleaning..."
			rm -f *.o $(OUT)
