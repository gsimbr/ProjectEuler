cimport numpy as np
import numpy as np


cdef unsigned int compute_next_collatz_element(unsigned int elem):
    if elem % 2 == 0:
        # use integer division
        return elem/2
    else:
        return 3*elem+1


cdef unsigned int compute_collatz_seq_length_with_memory(unsigned int startval, np.ndarray[np.int32_t, ndim=1] sequence_storage):
    """
    Computes the length of the collatz sequence by reading the length of the
    Collatz sequence by being able to read from memory if an already computed
    Collatz sequence length can be used.
    """
    cdef Py_ssize_t counter = 0
    cdef Py_ssize_t collatz_val = startval

    while collatz_val != 1:
        counter += 1
        collatz_val = compute_next_collatz_element(collatz_val)
        if collatz_val < startval:
            # as we compute the Collatz sequence length in increasing order,
            # we hit an already computed Collatz sequence length from the
            # previous value and add how many steps it took to get there
            result = counter + sequence_storage[collatz_val]
            sequence_storage[startval] = result
            return result

    return counter


cpdef unsigned int find_largest_collatz_seq_in_range_wth_storage(unsigned int n):
    """
    This finds the largest Collatz sequence length in the range from 1-N.
    """
    cdef int largest_seq_length = 1
    cdef int largest_input_val = 1
    cdef np.ndarray[np.int32_t, ndim=1] stored_collatzlengths = \
        np.zeros((n+1), dtype=np.int32, order="c")

    stored_collatzlengths[1] = 1

    cdef Py_ssize_t i

    for i in range(2, n):
        seq_length = compute_collatz_seq_length_with_memory(
            i, stored_collatzlengths)

        if seq_length > largest_seq_length:
            largest_seq_length = seq_length
            largest_input_val = i

    return largest_input_val

