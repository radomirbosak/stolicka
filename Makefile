all:
	gcc -Wall -o Stolicka stolicka.c -lm
	./Stolicka

clear:
	rm stolicka.o Stolicka
