LIBa=libmyBank.a
LIBso=libmyBank.so
CC = gcc
FLAGS = -Wall -g
MAINOBJECTS=main.o
LIBOBJECTS=myBank.o myBank.h

all: myBankd myBanks mains maind 

mains: $(MAINOBJECTS) myBanks
	$(CC) $(flags) -o mains $(MAINOBJECTS) $(LIBa)
maind: $(MAINOBJECTS) myBankd
	$(CC) $(flags) -o maind $(MAINOBJECTS) ./$(LIBso)
myBankd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
myBanks: $(LIBOBJECTS)
	ar -rcs $(LIBa) $(LIBOBJECTS)
main.o:main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c
	$(CC) -fPIC $(FLAGS) -c myBank.c

.PHONY: clean all

clean:
	rm -f *.o mains maind $(LIBa) $(LIBso)