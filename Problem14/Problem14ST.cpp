//
// Created by georg on 27.08.17.
//


#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>


int compute_next_collatz_element(int n){
    if (n % 2 == 0){
        return n/2;
    }
    return 3*n+1;

}

int compute_collatz_seq_length_with_memory(int startval, std::vector<int> sequence_storage){
    int counter = 0;
    int collatz_val = startval;

    while(collatz_val != 1){
        counter += 1;
        collatz_val = compute_next_collatz_element(collatz_val);
        if(collatz_val < startval){
            return sequence_storage[collatz_val]+counter;
        }
    }
    //printf("Length for %i: %i \n", startval, counter);
    return counter;
}


int find_largest_collatz_seq_in_range_wth_storage(unsigned int threshold, std::vector<int> stored_collatzlengths) {
    int largest_seq_length = 1;
    int temp;
    int largest_input_val = 1;
    //int stored_collatzlengths[N];

    // get rid later
    /*
    for(int i=0;i<threshold;i++){
        stored_collatzlengths[i] = -1;
        // printf("Array[%i]=%i \n", i, stored_collatzlengths[i]);
    }
     */


    for (int i = 1; i <= threshold; i++) {
        temp = compute_collatz_seq_length_with_memory(i, stored_collatzlengths);
        stored_collatzlengths[i] = temp;

        if (temp > largest_seq_length) {
            largest_seq_length = temp;
            largest_input_val = i;
        }
    }

    /*
    for (int i = 1; i <= threshhold; i++) {
        printf("Array[%i] = %i \n", i-1, stored_collatzlengths[i-1]);
    }
    */

    return largest_input_val;

}


int main(){
    int res;
    unsigned int threshold = 1000000;
    auto stored_collatzlengths = new std::vector<int>(threshold);
    clock_t begin = clock();

    res = find_largest_collatz_seq_in_range_wth_storage(threshold+1, *stored_collatzlengths);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    std::cout << "Largest Collatz Sequence under " <<  threshold << ": "  << res << std::endl;
    std::cout << "Wall Time:" << time_spent << std::endl;

    return 1;
}


