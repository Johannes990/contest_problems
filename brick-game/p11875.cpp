#include <iostream>
#include <vector>
#include <string>


int main() {
    int input_lines = 0;
    std::cin >> input_lines;

    for (int i = 0; i < input_lines; ++i)
    {
        int no_of_players = 0;
        int idx = 0;
        std::vector<int> ages;

        std::cin >> no_of_players;
        idx = no_of_players / 2;

        for (int i = 0; i < no_of_players; ++i)
        {
            int age = 0;
            std::cin >> age;
            ages.push_back(age);
            std::cin.clear();
        }
        std::cout << "Case " << i + 1 << ": " << ages[idx] << std::endl;
    }
    return 0;
}
