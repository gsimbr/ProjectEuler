#include <iostream>


bool evenly_divisible(int number, int threshhold) {
    for(int i=1; i <= threshhold; i++)
        if (number % i != 0)
        {
            return false;
        }
    return true;
}

int find_smallest_number_evenly_divisble_range(int threshold){
    int candidate = threshold;
    bool my_bool = false;
    while(not my_bool){
        my_bool = evenly_divisible(candidate, threshold);
        candidate += 1;
    }
    return candidate;
}


int main() {
    int cand = find_smallest_number_evenly_divisble_range(20);
    std::cout << cand << std::endl;
    return 0;
}