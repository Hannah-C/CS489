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

    // open specified file
    FILE *file = fopen(argv[1], "rb");

    // if failure to open file return error
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return -1;
    }

    // moves to end of file
    fseek(file, 0, SEEK_END);
    // determines current position in bytes (now at end of file)
    long size = ftell(file);

    fclose(file);

    printf("%ld\n", size);
}