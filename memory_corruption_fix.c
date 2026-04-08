#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    // Using strncpy to prevent buffer overflow
    strncpy(buffer, "This string is way too long!", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null termination
    printf("Buffer: %s\n", buffer);
    return 0;
}