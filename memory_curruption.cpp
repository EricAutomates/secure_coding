#include <iostream>
#include <string>
#include <cstring>  // Required for strcpy/strncpy

int main() {
    char buffer[10];
    std::string input = "This string is way too long!";

    // Safe version using strncpy
    strncpy(buffer, input.c_str(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null termination

    std::cout << "Buffer: " << buffer << std::endl;
    return 0;
}