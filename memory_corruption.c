#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    // Writing more than 10 bytes corrupts memory
    strcpy(buffer, "This string is way too long!");
    printf("Buffer: %s\n", buffer);
    return 0;
}