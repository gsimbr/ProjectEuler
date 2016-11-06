import numpy as np


def find_largest_palindrome_product(no_digits):
    my_list = []
    for num_1 in range(10**no_digits-1, int(np.sqrt(10**no_digits)), -1):
        for num_2 in range(10**no_digits-1, 1, -1):
            my_prod = num_1 * num_2
            if str(my_prod) == str(my_prod)[::-1]:
                my_list.append([[my_prod], [num_1, num_2]])
    my_list = np.array(my_list)
    largest_prod = np.argmax(my_list[:, 0])
    return my_list[largest_prod, 1][0], my_list[largest_prod, 1][1]


if __name__ == '__main__':
    num1, num2 = find_largest_palindrome_product(3)
    print num1, num2
    print num1*num2
