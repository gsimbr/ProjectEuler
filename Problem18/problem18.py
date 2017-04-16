import numpy as np
import argparse


def read_triangle_file_into_np_array(path):
    """
    This parses and converts an .out-file (whitespace separated values and
    newlines) containing numerical values to an numpy array.

    :param str path: The path where the outfile is located.
    :returns: A Numpy array, which converted all the values from the out file.
    :rtype: np.array
    """

    file_in = open(path, "r")
    contents_orig = file_in.readlines()
    file_in.close()

    my_list = []

    for i in range(len(contents_orig)):
        vals = contents_orig[i].split(" ")
        my_list.append([int(elem) for elem in vals])

    val_array = np.array(my_list)

    return val_array


def command_line_parse():
    pass


def maximal_path_sum(val_array):
    """
    This computes the maximal path sum by dynamic programming. Starting at the
    the before

    :param np.array val_array:
    :return:
    """
    print val_array
    dims = val_array.size
    for idx in range(dims-1, 1, -1):
        array_new = [val_array[idx-1][lv] +
                     np.max([val_array[idx][lv], val_array[idx][lv+1]])
                     for lv in range(idx)]
        val_array[idx] = 0
        val_array[idx-1][:] = array_new[:]

    return val_array[0][0]+np.max(val_array[1])

if __name__ == '__main__':
    path = "/home/georg/Documents/repos/ProjectEuler/Problem18/p067_triangle.txt"
    vals = read_triangle_file_into_np_array(path)
    ret_val = maximal_path_sum(vals)
    print ret_val
