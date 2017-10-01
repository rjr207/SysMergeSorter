all:sorter

second: sorter.c
	gcc -Wall -Werror -fsanitize=address sorter.c -o sorter -g

clean:
	rm -rf sorter 
