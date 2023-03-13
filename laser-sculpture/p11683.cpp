#include <algorithm>
#include <cstdio>

int main() {
    int BLOCK_HEIGHT = 0;
    int BLOCK_LENGTH = 0;

    while (true) {
        // first read in the height of the block, then the length
        std::scanf("%d%d", &BLOCK_HEIGHT, &BLOCK_LENGTH);

        // if 0 entered, end program
        if (!BLOCK_HEIGHT || !BLOCK_LENGTH)
            break;

        int current_column = 0;
        int previous_column = 0;
        int total_laser_uses = 0;

        // every time current block is lower than previous, laser gets turned on
        for (int i = 0; i < BLOCK_LENGTH; ++i) {
            std::scanf("%d", &current_column);

            if (i == 0) {
                total_laser_uses = BLOCK_HEIGHT - current_column;
                previous_column = current_column;
            } else {
                total_laser_uses += std::max(0, previous_column - current_column);
                previous_column = current_column;
            }
        }
        std::printf("%d\n", total_laser_uses);
    }
    return 0;
}
