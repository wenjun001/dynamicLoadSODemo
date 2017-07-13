all:
	gcc $(CFLAGS) -c -fPIC     hello.c  -o  hello.o
	gcc  hello.o  -shared -o  hello.so
	gcc $(CFLAGS) -o load_so  load_so.c -ldl