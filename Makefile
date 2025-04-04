CC = g++
CFLAGS = -Wall
EXEC_NAME = caca
INCLUDES =
LIBS = src/Passenger/menu.hpp
OBJ_FILES = fichier_1.o fichier_2.o
INSTALL_DIR = /usr/bin

all : $(EXEC_NAME)

clean :
  rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
  $(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
  $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
  $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
  gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
  cp $(EXEC_NAME) $(INSTALL_DIR)