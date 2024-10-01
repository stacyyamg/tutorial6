#include <iostream>
#include <string>
//
int computeChecksum(const std::string& charSequence) {
    int sumResult = 0;
    for (char c : charSequence) {
        sumResult += c;
    }
    return sumResult;
}

int generateKey(const std::string& firstArgument, int programNameSize) {
    int sumResult = computeChecksum(firstArgument);
    int generatedKey = (sumResult ^ firstArgument[0] * 3) << (programNameSize & 0x1f);
    return generatedKey;
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        std::cout << "Invalid input! Please run the program like this:" << std::endl;
        std::cout << "./main <firstArgument> <secondArgument>" << std::endl;
        return 1; 
    }

    std::string programName(argv[0]);  
    auto firstArgument(argv[1]);  
    auto programNameSize = programName.size();  
    auto secondArgument = std::atoi(argv[2]);  
    int sumResult = computeChecksum(firstArgument);

    std::cout << "Calculated checksum: " << sumResult << std::endl;
    std::cout << "Expected key: " << secondArgument << std::endl;


    if ((sumResult ^ firstArgument[0] * 3) << (programNameSize & 0x1f) == secondArgument) {
        std::cout << "Correct!" << std::endl;
    } else {
        std::cout << "Wrong!" << std::endl;
    }

    return 0;
}