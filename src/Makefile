CC=g++
CFLAGS=-I. -g -Wall
DEPS = ascii.h bitmap.h file_io.h scene.h
TARGET = terminal_3d_viewer

all: $(TARGET)

$(TARGET): ascii.o bitmap.o file_io.o scene.o terminal_3d_viewer.o
	$(CC) $(CFLAGS) -o terminal_3d_viewer terminal_3d_viewer.o ascii.o bitmap.o file_io.o scene.o

ascii.o: ascii.cpp ascii.h
	$(CC) $(CFLAGS) -c ascii.cpp

bitmap.o: bitmap.cpp bitmap.h
	$(CC) $(CFLAGS) -c bitmap.cpp

file_io.o: file_io.cpp file_io.h
	$(CC) $(CFLAGS) -c file_io.cpp

scene.o: scene.cpp scene.h
	$(CC) $(CFLAGS) -c scene.cpp

terminal_3d_viewer.o: terminal_3d_viewer.cpp
	$(CC) $(CFLAGS) -c terminal_3d_viewer.cpp

clean:
	$(rm) terminal_3d_viewer *.o *~