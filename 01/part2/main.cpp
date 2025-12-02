#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::string filepath = argv[1];
    std::string line;
    std::fstream file(filepath);
    int cursor = 50;

    int answer = 0;


    while(getline(file, line)) {
        std::cout << "CURSOR: " << cursor << "| MOVE: " << line;
        char direction = line[0];
        int value = stoi(line.substr(1));

        if (direction == 'R') {
            while (value > 100) {
                value -= 100;
                answer++;
            }

            cursor+= value;
            if (cursor > 99) {
                cursor -= 100;
                answer++;
            }
        } else {
            while (value > 100) {
                value -= 100;
                answer++;
            }

            int nextCursor = cursor - value;
            if (nextCursor <= 0) {
                if (cursor != 0) {
                    answer++;
                }
                if (nextCursor < 0) {
                    cursor = 100 + nextCursor;
                } else {
                    cursor = nextCursor;
                } 
            } else {
                cursor = nextCursor;
            }

        }

        std::cout << "| ZEROS: " << answer << std::endl;

    }

    std::cout << answer << std::endl;
    return 0;
}