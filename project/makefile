CC=g++
CFLAGS=-c -Wall

all: editor

editor: ECTextViewImp.o ECEditorTest.o
	$(CC) ECTextViewImp.o ECEditorTest.o -o editor

clean:
	rm -f *.o editor