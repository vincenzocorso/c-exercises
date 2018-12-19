CC		=	gcc
C_FLAGS		=	-Wall
F_OBJECTS	=	main.o libsort.o
F_PATH		=	/home/mrcoder/Scrivania/GitHub/exercises_c/lez30
F_OUTPUT	=	$(F_PATH)/main

$(F_OUTPUT):		$(F_OBJECTS)
			@echo Linking...
			@$(CC) $(C_FLAGS) $(F_OBJECTS) -o $(F_OUTPUT)

$(F_OBJECTS):		libsort.h
			$(CC) $(C_FLAGS) -c $*.c
