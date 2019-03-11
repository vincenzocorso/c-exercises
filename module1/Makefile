# Macro
CC		=	gcc
CFLAGS		=	-Wall
F_PATH		=	/home/mrcoder/Scrivania/GitHub/exercises_c
F_OBJECTS	=	test.o vincenzo.o
F_OUTPUT	=	$(F_PATH)/test

# Linking
$(F_OUTPUT):	$(F_OBJECTS)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $(F_OUTPUT) $(F_OBJECTS)

$(F_OBJECTS):	vincenzo.h
	$(CC) -c $*.c
