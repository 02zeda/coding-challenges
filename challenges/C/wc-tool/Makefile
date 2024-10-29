CFLAGS = -Wall -g
wc_challenge: wc_challenge.o
	gcc ${CFLAGS} -o wc_challenge wc_challenge.o

wc_challenge.o: src/wc_challenge.c
	gcc ${CFLAGS} -c src/wc_challenge.c
all:
	make wc_challenge
clean:
	echo "Removing object files and executable..."
	rm wc_challenge.o wc_challenge
install:
	cp  wc_challenge /usr/bin
uninstall:
	rm /usr/bin/wc_challenge
