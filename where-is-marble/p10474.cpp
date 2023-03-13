#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q, marble, marble_no;
    int CASE = 1;
    while (std::cin >> N >> Q, N && Q) {
        
        std::vector<int> marbles;
        for (int i = 0; i < N; ++i) {
            std::cin >> marble;
            marbles.push_back(marble);
        }
        std::sort(marbles.begin(), marbles.end());

        std::cout << "CASE# " << CASE++ << ':' << std::endl;

        for (int i = 0; i < Q; ++i) {
            std::cin >> marble_no;

            // find the first index where element is found.
            std::vector<int>::iterator position = std::lower_bound(marbles.begin(), marbles.end(), marble_no);
            // print correct answer.
            if (position == marbles.begin() + N || *position != marble_no) {
                std::cout << marble_no << " not found" << std::endl;
            } else {
                std::cout << marble_no << " found at " << (position - marbles.begin()) + 1 << std::endl;
            }
        }
    }
    return 0;
}
