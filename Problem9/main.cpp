#include <iostream>
#include <assert.h>

using namespace std;

bool is_pythagorean_triplet(int a, int b, int c){
    assert(a < b);
    assert(b < c);
    return a*a+b*b-c*c == 0;
}

int get_pythagoran_triplet(int* my_list, int total_sum){
    int a, b, c;
    for (a = 0; a < total_sum; ++a) {
        for (b = a+1; b < total_sum-a; ++b) {
            c = total_sum-a-b;
            if(c <= b){
                break;
            }
            if(is_pythagorean_triplet(a, b, c)){
                cout << "a= " << a << ", b= " << b << ", c= " << c << endl;
                my_list[0] = a;
                my_list[1] = b;
                my_list[2] = c;
                return 0;
            }
        }
    }
    cout << "Could not find a pythagorean triplet satisfying the restraint a+b+c =" << total_sum << endl;
    return 1;
}

int main() {
    clock_t begin = clock();
    int mylist[3];
    int exit_code;
    exit_code = get_pythagoran_triplet(mylist, 10000);
    int a = mylist[0];
    int b = mylist[1];
    int c = mylist[2];
    int d = a*b*c;
    cout << "Result is " << d << endl;
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "time elapsed [s]= " << elapsed_secs << endl;
    return exit_code;
}