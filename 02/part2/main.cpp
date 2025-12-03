#include <fstream>
#include <iostream>
#include <vector>

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> result;
    size_t start = 0;

    for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, start))
    {
        result.emplace_back(str.begin() + start, str.begin() + found);
        start = found + delim.size();
    }
    if (start != str.size())
        result.emplace_back(str.begin() + start, str.end());
    return result;      
}

int main(int argc, char* argv[]) {
    std::string filepath = argv[1];
    std::string line;
    std::fstream file(filepath);

    unsigned long answer = 0;

    while(getline(file, line)) {
        std::vector<std::string> ranges = split(line, ",");
        for (auto range : ranges) {
            std::vector<std::string> bounds = split(range, "-");
            unsigned long start = std::stoull(bounds[0]);
            unsigned long end = std::stoull(bounds[1]);

            for (unsigned long i = start; i <= end; i++) {
                std::string str = std::to_string(i);
                int length = str.length();
                std::vector<int> divisors;
                for (int j = 2; j < length; j++) {
                    if (length % j == 0) {
                        divisors.push_back(length / j);
                    }
                }

                divisors.push_back(1);

                bool isInvalid = false;
                for (const auto divisor: divisors) {
                    if (isInvalid) {
                        break;
                    }
                    std::vector<std::string> tokens;
                    size_t start = 0;
                    while(start != length) {
                        std::string token = str.substr(start, divisor);
                        tokens.push_back(token);
                        start += divisor;
                    }

                    std::string firstToken = tokens[0];
                    for (int k = 1; k < tokens.size(); k++) {
                        if (tokens[k] != firstToken) {
                            break;
                        }

                        if (k == tokens.size() - 1) {
                            answer += i;
                            isInvalid = true;
                        }
                    }
                }
            }
        }
    }

    std::cout << answer << std::endl;
    return 0;
}