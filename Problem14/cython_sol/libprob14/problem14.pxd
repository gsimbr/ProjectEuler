cimport numpy as np
import numpy as np


cdef unsigned int compute_next_collatz_element(unsigned int elem)

cdef unsigned int compute_collatz_seq_length_with_memory(
        unsigned int startval, np.ndarray[np.int32_t, ndim=1]  sequence_storage)
