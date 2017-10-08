function compute_next_collatz_element(elem::Int64)
  if (elem % 2 == 0)
    # use Integer division
    return div(elem, 2)
  else
    return 3*elem+1
  end
end

function compute_collatz_seq_length_with_memory(startval::Int64, sequence_storage::Array{Int64, 1})
    """
    Computes the length of the collatz sequence by reading the length of the
    Collatz sequence by being able to read from memory if an already computed
    Collatz sequence length can be used.
    """
    counter = 0
    collatz_val = startval

    while collatz_val != 1
        counter += 1
        collatz_val = compute_next_collatz_element(collatz_val)
        if collatz_val < startval
            # as we compute the Collatz sequence length in increasing order,
            # we hit an already computed Collatz sequence length from the
            # previous value and add how many steps it took to get there
            result = counter + sequence_storage[collatz_val]
            sequence_storage[startval] = result
            return result
        end
    end
    return counter
end


function find_largest_collatz_seq_in_range_wth_storage(N::Int64)
    """
    This finds the largest Collatz sequence length in the range from 1-N.
    """
    largest_seq_length = 1
    largest_input_val = 1
    stored_collatzlengths = Array{Int64}(N+1)
    stored_collatzlengths[1] = 1

    for i in 2:N
        seq_length = compute_collatz_seq_length_with_memory(i, stored_collatzlengths)

        if seq_length > largest_seq_length
            largest_seq_length = seq_length
            largest_input_val = i
        end
    end

    return largest_input_val

end

N=1000000
println("N = ", N)
@time res = find_largest_collatz_seq_in_range_wth_storage(N)
println("Result = ", res)
