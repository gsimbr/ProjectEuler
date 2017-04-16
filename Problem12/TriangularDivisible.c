//
// Created by georg on 15.04.17.
//

#import <stdio.h>


int get_nth_triangle_number(int n){
    // gaussian summation
    return (n*(n+1))/2;
}

int get_num_divisors(int n){
    int counter = 0;
    for(int i=1; i<=n; ++i){
        if((n % i) == 0){
            counter += 1;
        }
    }
    return counter;
}


void main(){
    int n = 1;
    int triangle_no;
    int no_div = 1;
    int desired_divisors = 500;
    while(no_div < desired_divisors){
        n += 1;
        triangle_no = get_nth_triangle_number(n);
        no_div = get_num_divisors(triangle_no);
        printf("Triangle no= %i \n", triangle_no);
    }
    printf("n = %i \n", n);
    printf("no_div = %i \n", no_div);
}