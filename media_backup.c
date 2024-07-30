#include <stdio.h>
#include <stdint.h>

// TODO: Expand program to allow the user to specify where the new file is stored.

// We create a type called BYTE for an unsigned 8-bit integer.
typedef uint8_t BYTE;

// In this program, we will be copying data from one file to another.
int main(int argc, char *argv[])
{
    // Instead of using "r" for read, we use "rb" for read binary. This is a pointer to our source file.
    // If we are dealing with binary data, like images, we must use this.
    FILE *src = fopen(argv[1], "rb");

    // We use "wb" for write binary. This is a pointer to our destination file.
    FILE *dst = fopen(argv[2], "wb");

    // We initialise an unsigned 8-bit int in memory, aka a byte.
    // This provides us 1 byte of space to use.
    BYTE b;

    // fread reads 1 or more bytes from a file.
    // First param: we pass in the address of b. This is telling our program where to store our byte on each iteration of the loop.
    // We can't just use b, we must use &b. If we used b, we would be passing the value into fread, not the address.
    // Second param: we provide the size of the data we want to read on each iteration of the loop.
    // Third param: we provide the quantity of data we want to read at one time. In this case, it's 1 byte.
    // Fourth param: we provide the file we want to read.
    // Finally, we determine the return value of fread. If it is 0, it means there are no more bytes to read.
    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        // The same explanation as above is applicable here. All params are the same.
        // The only difference is that we are writing to a file, not reading.
        fwrite(&b, sizeof(b), 1, dst);
    }

    // We use fclose to close our files, as they are no longer needed.
    fclose(dst);
    fclose(src);
}
