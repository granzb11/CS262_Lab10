all:
	gcc -o ascii_to_binary ascii_to_binary.c
	gcc -o binary_to_ascii binary_to_ascii.c

clean:
	rm -f ascii_to_binary brinary_to_ascii
