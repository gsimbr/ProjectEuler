

def is_pythagorean_triplet(a, b, c):
    assert a < b
    assert b < c
    return c**2-(a**2+b**2) == 0


def get_triplet_equaling_sum(my_sum):
    if sum < 5:
        raise ValueError

    triplets = []
    for a in range(1, my_sum):
        for b in range(a+1, my_sum-a):
            c = my_sum - a - b
            if c <= b:
                break
            triplets.append([a, b, c])
    return triplets


def get_pythgorean_triplets(triplets):
    for my_triplet in triplets:
        a = my_triplet[0]
        b = my_triplet[1]
        c = my_triplet[2]
        if is_pythagorean_triplet(a, b, c):
            print "Triplet found: a = %d, b = %d, c = %d" % (a, b, c)
            print "Product is: %d" % (a*b*c)


def main():
    my_sum = 1000
    triplets = get_triplet_equaling_sum(my_sum)
    get_pythgorean_triplets(triplets)

if __name__ == '__main__':
    main()
