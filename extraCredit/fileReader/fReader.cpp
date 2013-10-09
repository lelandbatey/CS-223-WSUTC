#include <stdio.h>
#include <time.h>

#define CHAR_NUM 1048576
#define READ_SIZE 1024

#ifndef DEBUG
#define DEBUG 0
#endif

#ifndef MANY_CHARS_FILE
#define MANY_CHARS_FILE "millionChars.txt"
#endif


FILE* buildFile() {
    FILE* writeFile;

    writeFile = fopen(MANY_CHARS_FILE,"w+");
    if (DEBUG) {
        printf("Writing to file.\n");
    }

    for (int i = 0; i < CHAR_NUM; ++i) {
        fputc('1',writeFile);
    }

    if (DEBUG) {
        printf("Finished writing to file.\n");
    }

    return writeFile;
}

int main(int argc, char const *argv[])
{
    FILE* readFile = buildFile();
    char buffer[READ_SIZE];
    char oneBuf[1];


    // Simple method of getting the time elapsed between two timestamps.
    // Taken from this StackOverflow:
    // http://stackoverflow.com/a/16276032
    struct timespec tstart={0,0}, tend={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);


    // Read from the file 1024 bytes at a time.
    if (DEBUG) {
        printf("Reading from file.\n");
    }
    
    for (int i = 0; i < int(CHAR_NUM/READ_SIZE); ++i) {
        fread(buffer, sizeof(buffer), 1, readFile);
    }
    
    if (DEBUG) {
        printf("Finished reading from file.\n");
    }

    fclose(readFile);
    clock_gettime(CLOCK_MONOTONIC, &tend);

    printf("Reading 1024 bytes at a time took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));





    readFile = buildFile();
    // Again with the simple timing method
    clock_gettime(CLOCK_MONOTONIC, &tstart);

    // read from the file one byte at a time
    if (DEBUG) {
        printf("Reading from file one at a time.\n");
    }

    for (int i = 0; i < CHAR_NUM; ++i) {
        // fgetc(readFile);
        fread(oneBuf, sizeof(oneBuf), 1, readFile);
    }

    clock_gettime(CLOCK_MONOTONIC, &tend);
    fclose(readFile);


    printf("Reading one byte at a time took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    remove(MANY_CHARS_FILE);

    return 0;
}