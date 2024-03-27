#include "supportLib.h"
#include <string.h>
unsigned char *DoubleArrayToByteArray(double *data, size_t length) {
    unsigned char *out;
    size_t i;

    out = (unsigned char *) malloc(sizeof(unsigned char) * length);

    for (i = 0; i < length; i++) {
        out[i] = data[i];
    }

    return out;
}

void WriteToFile(double *data, size_t dataLength, char *filename) {
    unsigned char *bytes;

    bytes = DoubleArrayToByteArray(data, dataLength);

    FILE *file;
    while ((file = fopen(filename, "wb")) == NULL) {
        // If the file path is not empty, remove the first character and try again
        if (strlen(filename) > 1) {
            memmove(filename, filename + 1, strlen(filename));
        } else {
            // If the file path is empty, return
            printf("Error opening file\n");

            free(bytes);
            return;
        }
    }
    fwrite(bytes, 1, dataLength, file);
    fclose(file);
    free(bytes);
}

double *ByteArrayToDoubleArray(unsigned char *data, size_t length) {
    double *out;
    size_t i;

    out = (double *) malloc(sizeof(double) * length);

    for (i = 0; i < length; i++) {
        out[i] = data[i];
    }

    return out;
}
