#include <stdio.h>
#include <stdlib.h>
#include <tomcrypt.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

/**
    To compile to web assembly
    emcc sample.c -o sample.html -s WASM=1
*/

char* EMSCRIPTEN_KEEPALIVE ln_sha(char string[]);
char* EMSCRIPTEN_KEEPALIVE ln_md5(char string[]);

int main(int argc, char *argv[])
{
    printf("Welcome to lnpher, a wasm module based on tomcrypt \n");

    printf("The hash is: %s\n", ln_md5("helloworld"));

    return EXIT_SUCCESS;
}

char* EMSCRIPTEN_KEEPALIVE ln_sha(char string[]){
    hash_state md;
    unsigned char result[16];

    sha256_init(&md);
    sha256_process(&md, string, strlen(string));
    sha256_done(&md, result);

    return result;
}

char* EMSCRIPTEN_KEEPALIVE ln_md5(char string[]){
    hash_state md;
    unsigned char result[16];

    md5_init(&md);
    md5_process(&md, string, strlen(string));
    md5_done(&md, result);

    return result;
}
