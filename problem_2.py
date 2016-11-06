

def count_even_fibonacci(threshold):
    fib_1 = 0
    fib_2 = 1
    sum_even_fib = 0
    while True:
        fib_3 = fib_1 + fib_2
        if fib_3 > threshold:
            break
        fib_1 = fib_2
        fib_2 = fib_3
        if fib_3 % 2 == 0:
            sum_even_fib += fib_3
    return sum_even_fib


if __name__ == '__main__':
    c = count_even_fibonacci(4*1e6)
    print "c=%d" % c