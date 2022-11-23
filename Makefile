c=gcc
op=-Wall -Wextra

all : testfig.c my_sig.h
	$(c) $(op) testfig.c -o exe
