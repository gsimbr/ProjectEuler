import primefac


def find_largest_prime_factor(number):
    """

    :param int number:
    :return:
    """

    factors = list(primefac.primefac(number))
    print factors
    return max(factors)

if __name__ == '__main__':
    num = 600851475143
    erg = find_largest_prime_factor(num)
    print erg