
#include <dlfcn.h>

#include <stdlib.h>
#include <stdio.h>



/* The type "simple_demo_function" describes a function that
   takes no arguments, and returns no value: */

typedef void (*simple_demo_function)(int);


int main(void) {
    const char *error;
    void *module;
    simple_demo_function demo_function;

    /* Load dynamically loaded library */
    module = dlopen("../load_so/hello.so", RTLD_LAZY);
    if (!module) {
        fprintf(stderr, "Couldn't open mapping.so: %s\n",
                dlerror());
        exit(1);
    }

    /* Get symbol */
    dlerror();
    demo_function = dlsym(module, "first");
    if ((error = dlerror())) {
        fprintf(stderr, "Couldn't find callMe: %s\n", error);
        exit(1);
    }


    /* Now call the function in the DL library */
    (*demo_function)(1);

    demo_function = dlsym(module, "second");
    if ((error = dlerror())) {
        fprintf(stderr, "Couldn't find callMe: %s\n", error);
        exit(1);
    }



    /* Now call the function in the DL library */
    (*demo_function)(2);

    /* All done, close things cleanly */
    dlclose(module);
    return 0;
}