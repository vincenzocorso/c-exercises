CFLAGS		=	-Wall

OUT			=	main
LIB			=	libcomplex.a

$(OUT):		$(LIB)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $@.c -o $@ -L. -l:$(LIB) -lm

%.o:		%.c
			@echo "Compiling "$^
			$(CC) $(CFLAGS) -c $^

%.a:		%.o
			@echo "Compiling library..."
			ar rcs $@ $^

.PHONY:	clean
clean:
			@echo "Cleaning..."
			rm -f *.o $(LIB) $(OUT)
