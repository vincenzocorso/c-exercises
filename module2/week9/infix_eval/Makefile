CFLAGS		=	-Wall

OUT			=	infix_eval
LIB			=	libstack.a
INCS		=	$(wildcard *.h)

OBJS		=	stackitem.o

$(OUT):		$(OUT).c $(LIB) $(OBJS)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $@.c $(OBJS) -o $@ -L. -l:$(LIB)

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

.PHONY:	clean
clean:
			@echo "Cleaning..."
			rm -f *.o $(OUT)
