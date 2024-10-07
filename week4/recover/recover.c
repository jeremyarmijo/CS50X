#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("The forensic image cannot be opened for reading\n");
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int count_image = 0;
    FILE *output = NULL;
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == BLOCK_SIZE) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (count_image == 0) {
                sprintf(filename, "%03i.jpg", count_image);
                output = fopen(filename, "w");
                if (output == NULL) {
                    printf("jpeg file cannot be opened\n");
                    return 2;
                }
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
                count_image++;
            } else if (count_image > 0) {
                fclose(output);
                sprintf(filename, "%03i.jpg", count_image);
                output = fopen(filename, "w");
                if (output == NULL) {
                    printf("jpeg file cannot be opened\n");
                    return 2;
                }
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
                count_image++;
            }
        } else if (count_image > 0)
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
    }
    fclose(output);
    fclose(input);
}
