#include <iostream>

int main(int argc, char *argv[]) {
    
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    } else {
        for(int i = 1; i < argc; i++) {
            std::string str(argv[i]);
            for(long unsigned int j = 0; j < str.length(); j++) {
                str[j] = std::toupper(str[j]);
            }
            std::cout << str;
        }
        std::cout << std::endl;
    }
    

}