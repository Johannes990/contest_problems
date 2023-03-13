#include <iostream>

int bin_search_up(int array[], int arr_length, int element) {
    int low_idx = 0;
    int high_idx = arr_length - 1;

    // array is sorted beforehand
    // element is larger than anything in array, no element greater or equal.
    if (element > array[high_idx])
        return -1;
    // element is smaller than first element in array, return first element
    if (element <= array[low_idx])
        return low_idx;

    while (low_idx <= high_idx) {   
        // get middle_index from low to high
        int middle_idx = low_idx + ((high_idx - low_idx) * 0.5);

        // if element at middle index is GE than element and the element before it is less,
        // return middle index as the searched position
        if (array[middle_idx] >= element && array[middle_idx - 1] < element)
            return middle_idx;
        
        // previsous condition failed. If we get here, then array has element array[middle_idx - 1]
        // that is at least as large as element. set high_idx as the previous element of array.
        if (array[middle_idx] >= element) { high_idx = middle_idx - 1; }

        // element is no in the lower half of the array, adjust low idx.
        else if (array[middle_idx] < element) { low_idx = middle_idx + 1; }
    }
    // while loop didn't come up with anything, return -1 for not found.
    return -1;
}
//
int main() {
    int rows;
    int columns;
    int array[505][505];

    // fill array with numbers
    while (std::cin >> rows >> columns && (rows || columns)) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cin >> array[i][j];
            }
        }

        int query;
        std::cin >> query;

        while (query--) {
            int low_limit;
            int high_limit;
            std::cin >> low_limit >> high_limit;

            // square is the largest plot of land we find, the solution
            int max_square = 0;
            for (int row = 0; row < rows; ++row) {
                // search for the start position on row to begin search
                // if none found, move to next row
                int start_column = bin_search_up(array[row], columns, low_limit);
                if (start_column == -1)
                    continue;
                
                // loop to find larger squares that meet criteria
                for (int current_square = max_square; current_square < rows; ++current_square) {
                    
                    int edge_row = row + current_square;  // bottom of current square
                    int edge_col = start_column + current_square;  // left side of current suqare

                    // square bottom beyond map limits
                    if (edge_row >= rows)
                        break;

                    // square side beyond map limits
                    if (edge_col >= columns)
                        break;
                    
                    // square position greater than high_limit -> false plot
                    if (array[edge_row][edge_col] > high_limit)
                        break;
                    
                    if (current_square + 1 > max_square)
                        max_square = current_square + 1;
                }
            }
            std::cout << max_square << '\n';
        }
        std::cout << "-\n";
    }
    return 0;
}
