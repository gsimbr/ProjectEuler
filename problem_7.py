import primefac


def find_xth_prime(index):
    counter = 0
    current_candidate = 1

    while counter < index:
        my_bool = primefac.isprime(current_candidate)
        if my_bool:
            counter += 1

        if counter == index:
            return current_candidate
        else:
            current_candidate += 1


if __name__ == '__main__':
    erg = find_xth_prime(10001)
    print erg
