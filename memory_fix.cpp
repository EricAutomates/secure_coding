#include <iostream>
#include <string>
#include <cstring>

int main() {
    char buffer[10];
    std::string input = "This string is way too long!";
    // Use strncpy to prevent overflow
    strncpy(buffer, input.c_str(), sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0'; // null terminate
    std::cout << "Buffer: " << buffer << std::endl;
    return 0;
}