CFLAGS = -std=c11 -Wall -Wextra -g -pedantic -O2

all: primes primes-i steg-decode

run: primes primes-i
	./primes
	./primes-i

steg-decode: ppm.o steg-decode.o
	gcc $(CFLAGS) ppm.o steg-decode.o error.o eratosthenes.o -o steg-decode

primes: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes

primes-i: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -DUSE_INLINE -o primes-i

ppm: ppm.c ppm.h
	gcc $(CFLAGS) -c ppm.c

eratosthenes: eratosthenes.h bitset.h eratosthenes.c
	gcc $(CFLAGS) -c eratosthenes.c -lm

error: error.c error.h
	gcc $(CFLAGS) -c error.c

clean:
	rm -f *.o primes primes-i steg-decode

zip:
	zip xvinto00.zip *.c *.h makefile