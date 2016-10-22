
def find_multiples(threshold, number):
    """

    :param int threshold: The number up to which all multiples of number
        should be returned
    :param int number: The number which multiples up to threshold should be
        returned
    :return: An array with all the multiples of number up to threshold
    """
    num = threshold // number
    if threshold % number == 0:
        num -= 1
    mult_array = [number*(i+1) for i in range(num)]

    return mult_array


def sum_multiples(threshold, numbers):
    """

    :param int threshold: The number up to which all multiples of number
        should be returned.
    :param [int] numbers: A list of integers whose sums of sums of all multiples
        up to threshold should be returned
    :return: The sum of sums of all multiples of elements in numbers up to
        threshold.
    """

    mult = set()

    for num in numbers:
        mult.update(find_multiples(threshold, num))

    my_sum = sum(mult)

    return my_sum

if __name__ == '__main__':
    numbers = [3, 5]
    threshold = 1000
    my_sum = sum_multiples(threshold, numbers)
    print my_sum
