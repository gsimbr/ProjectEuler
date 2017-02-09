import primefac
import time


def sum_primes(threshhold):
    counter = 0
    result = 0

    while counter < threshhold:
        counter += 1
        if primefac.isprime(counter):
            result += counter

    return result

if __name__ == '__main__':
    threshhold = 2*1e6
    start = time.time()
    res = sum_primes(threshhold)
    end = time.time()
    print "Sum of primes below %d: %d." % (threshhold, res)
    print "Walltime: %.2f" % (end-start)
