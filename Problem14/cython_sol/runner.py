import time

from libprob14.problem14 import find_largest_collatz_seq_in_range_wth_storage

if __name__ == '__main__':
    n = int(1000000)
    start = time.time()
    res = find_largest_collatz_seq_in_range_wth_storage(n)
    end = time.time()

    print "Result: {}, time elapsed: {}".format(res, end - start)
