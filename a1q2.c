#include <stdlib.h>
#include <stdio.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    long prev = ftell(file);

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    
    fseek(file,prev,SEEK_SET);

    fclose(file);

    printf("%ld\n", size);
}