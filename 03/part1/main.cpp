
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    std::string filepath = argv[1];
    std::string line;
    std::fstream file(filepath);

    int answer = 0;

    while(getline(file, line)) {
        char max = line[0];
        char max2 = line[1];
        char last = line[line.length() - 1];
        int index = 0;

        for (int i = 1; i < line.length() - 1; i++) {
            if (line[i] > max) {
                max = line[i];
                max2 = line[i+1];
                index = i;
            }
        }

        char max2ndDigit = std::max(max2, last);
        std::cout << max << " " << max2ndDigit << std::endl;
        std::string joltage = "" + max + max2ndDigit;
        std::cout << joltage << std::endl;
        answer += stoi(joltage);

    }

    std::cout << answer << std::endl;
    return 0;
}