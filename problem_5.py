

def find_smallest_number_evenly_divisble_range(threshold):
    candidate = threshold
    my_bool = False

    while not my_bool:
        candidate += 1
        my_bool = evenly_divisible(candidate, threshold)

    return candidate


def evenly_divisible(number, threshhold):
    for i in range(1, threshhold+1):
        if number % i != 0:
            return False
    return True


if __name__ == '__main__':
    cand = find_smallest_number_evenly_divisble_range(20)
    print cand
