#include <iostream>
#include <vector>

int main() {
    unsigned int n, m, x = 0;
    std::vector<int> size;

    std::cout << "\t\t STORAGE PLACEMENT STRATEGIES\n";
    std::cout << "Enter the number of holes: ";
    std::cin >> n;

    for (unsigned int i = 0; i < n; ++i) {
        std::cout << "Enter the Size Of Hole " << i + 1 << ": ";
        int holeSize;
        std::cin >> holeSize;
        size.push_back(holeSize);
    }

    int cho = 1;
    while (cho == 1) {
        std::cout << "\nEnter the size of the incoming program: ";
        std::cin >> m;

        std::cout << "\nMenu";
        std::cout << "\n1. First Fit Strategy \n2. Best Fit Strategy \n3. Quit";
        std::cout << "\nEnter your choice: ";
        int ch;
        std::cin >> ch;

        x = 0;
        switch (ch) {
            case 1:
                for (unsigned int i = 0; i < n; ++i) {
                    if (size[i] >= m) {
                        std::cout << "\nYour program is placed in hole " << i + 1;
                        size[i] -= m;
                        x = i + 1;
                        break;
                    }
                }
                if (x == 0)
                    std::cout << "There is no room for your program.";
                break;
            case 2: {
                int temp = 0, pos = 0, t1;
                if (m <= size[0]) {
                    temp = size[0] - m;
                    pos = 1;
                } else
                    temp = size[0];

                for (unsigned int i = 1; i < n; ++i) {
                    if (m <= size[i]) {
                        t1 = size[i] - m;
                        if (temp >= t1) {
                            temp = t1;
                            pos = i + 1;
                        }
                    } else
                        temp = size[i];
                }

                if (pos == 0)
                    std::cout << "There is no room for your program.";
                else {
                    size[pos - 1] -= m;
                    std::cout << "Your program is placed in hole " << pos;
                }
                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.";
        }

        std::cout << "\nFree Storage List";
        for (unsigned int i = 0; i < n; ++i)
            std::cout << "\nHole " << i + 1 << "\t\t" << size[i];

        std::cout << "\n\nPress 1 to continue: ";
        std::cin >> cho;
    }

    return 0;
}
