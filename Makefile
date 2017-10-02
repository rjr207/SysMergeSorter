all:sorter

sorter: sorter.c
	gcc -Wall -Werror -fsanitize=address sorter.c -o sorter -g

clean:
	rm -rf sorter 
