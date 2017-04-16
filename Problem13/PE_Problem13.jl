function read_file_to_bigint(path)
f = open(path);
a = []
for ln in eachline(f)
  append!(a, parse(BigInt, ln))
end
close(f)
return a
end

function add_list(my_array)
  res = BigInt(0)
  for elem in my_array
    res += elem
  end
  return res
end


big_int_array = read_file_to_bigint("Problem13.txt")
res = add_list(big_int_array)

println(res)
