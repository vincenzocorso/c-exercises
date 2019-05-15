CFLAGS		=	-Wall

OUT			=	main
LIB			=	libpolynomial.a

$(OUT):		$(LIB)
			@echo "Creating executable..."
			$(CC) $(CFLAGS) $@.c -o $@ -L. -l:$(LIB)

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
