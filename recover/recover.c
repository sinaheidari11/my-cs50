//importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCKSIZE 512
//making error
int  inputError()
{
    printf("Usage: ./recover image\n");
    return 1;
}
//making error
int fileError(char filename[])
{
    printf("Unable to open file: %s\n", filename);
    return 1;
}
//definnig buffer
bool isJpegHeader(uint8_t buffer[])
{
    return buffer[0] == 0xff
           && buffer[1] == 0xd8
           && buffer[2] == 0xff
           && (buffer[3] & 0xf0) == 0xe0;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return inputError();
    }
    char *inputFile = argv[1];
    if (inputFile == NULL)
    {
        return inputError();
    }
    FILE *inputPtr = fopen(inputFile, "r");
    if (inputPtr == NULL)
    {
        return fileError(inputFile);
    }
// making variables
    char filename[8]; // xxx.jpg'\0'
    FILE *outputPtr = NULL;
    uint8_t buffer[BLOCKSIZE];
    int jpgCounter = 0;
//opennig files
    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, inputPtr) || feof(inputPtr) == 0)
    {
        if (isJpegHeader(buffer))
        {
            if (outputPtr != NULL)
            {
                fclose(outputPtr);
            }
            sprintf(filename, "%03i.jpg", jpgCounter);
            outputPtr = fopen(filename, "w");
            jpgCounter ++;
        }
        if (outputPtr != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }
    //closing opened files
    if (inputPtr == NULL)
    {
        fclose(inputPtr);
    }
    // closing opened files
    if (outputPtr == NULL)
    {
        fclose(outputPtr);
    }
    //returning 0 
    return 0;
}
