#include <iostream>

int calc_sum_squares(int threshold){
    int erg = 0;
    for (int i = 1; i <= threshold; ++i) {
        erg += i*i;
    }
    return erg;
}

int calc_squared_sum(int threshold){
    int erg = 0;
    for (int i = 1; i <= threshold; ++i) {
        erg += i;
    }
    return erg*erg;
}

int compute_difference_squared_sums(int threshold){
    return calc_squared_sum(threshold) - calc_sum_squares(threshold);
}



int main() {
    int limit = 100;
    int my_erg = compute_difference_squared_sums(limit);
    std::cout << my_erg << std::endl;
    return 0;
}