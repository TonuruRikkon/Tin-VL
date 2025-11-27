#include <iostream>

int main() {
    if (__cplusplus == 201103L) {
        std::cout << "C++11" << std::endl;
    } else if (__cplusplus == 201402L) {
        std::cout << "C++14" << std::endl;
    } else if (__cplusplus == 201703L) {
        std::cout << "C++17" << std::endl;
    } else if (__cplusplus == 202002L) {
        std::cout << "C++20" << std::endl;
    } else if (__cplusplus > 202002L) {
        std::cout << "C++23 or later" << std::endl;
    } else {
        std::cout << "Pre-C++11 or unknown standard" << std::endl;
    }
    return 0;
}