This project show how to dynamically load SO file(same as Java dynamical load class file)

dlopen will load so file  see the load_so.c


dlsym will get function pointer for symbol based on the function name you already know it. see the load_so.c


when get function pointer we can invoke it immediately  like :   (*demo_function)(1);


Then close load so moduel.


We can use this way to update program without stop applicaiton. 
