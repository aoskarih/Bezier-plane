
#OBJS specifies which files to compile as part of the project
OBJS = main.cpp misc.cpp mandelbrot.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++11

#LINKER_FLAGS specifies the libraries we're linking against
# -lSDL2_image -lSDL2_mixer  -lSDL2_ttf -lSDL2main -lSDL2_gfx
LINKER_FLAGS = -lSDL2 -I/usr/local/include/  -I.

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = brot

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
