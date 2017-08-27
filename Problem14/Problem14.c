//
// Created by georg on 17.04.17.
//

#include <stdio.h>
#include <time.h>
#include <malloc.h>

typedef int bool;
enum { false, true };

int compute_next_collatz_element(int n){
    if (n % 2 == 0){
        return n/2;
    }
    return 3*n+1;

}

int compute_collatz_seq_length(int startval){
    int counter = 0;
    int collatz_val = startval;
    while(collatz_val != 1){
        counter += 1;
        collatz_val = compute_next_collatz_element(collatz_val);
    }
    //printf("Length for %i: %i \n", startval, counter);
    return counter;
}

int compute_collatz_seq_length_with_memory(int startval, int* sequence_storage){
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

int find_largest_collatz_seq_in_range(int threshhold){
    int largest_seq_length = 1;
    int temp;
    int largest_input_val = 1;

    for (int i = 1; i <= threshhold; i++) {
        temp = compute_collatz_seq_length(i);
        if (temp > largest_seq_length) {
            largest_seq_length = temp;
            largest_input_val = i;
        }
    }

    return largest_input_val;
}

int find_largest_collatz_seq_in_range_wth_storage(int N) {
    int largest_seq_length = 1;
    int temp;
    int largest_input_val = 1;
    int* stored_collatzlengths = malloc(N*sizeof(int));
    //int stored_collatzlengths[N];

    // get rid later
    for(int i=0;i<N;i++){
        stored_collatzlengths[i] = -1;
        // printf("Array[%i]=%i \n", i, stored_collatzlengths[i]);
    }


    for (int i = 1; i <= N; i++) {
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


void main(){
    int N = 100000;
    int res;
    bool use_memory = false;
    clock_t begin = clock();
    if(use_memory==true) {
        res = find_largest_collatz_seq_in_range_wth_storage(N);
    }
    else{
        res = find_largest_collatz_seq_in_range(N);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Largest Collatz Sequence under %i: %i \n", N, res);
    printf("Wall Time: %f \n", time_spent);
}
