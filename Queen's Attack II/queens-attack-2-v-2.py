import math
import os
import random
import re
import sys


#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER r_q
#  4. INTEGER c_q
#  5. 2D_INTEGER_ARRAY obstacles
#

def queensAttack(n, r_q, c_q, obstacles):
    counter = 0
    directions = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [1, -1], [-1, -1], [-1, 1]]
    if n == 0 or list([r_q,c_q]) in obstacles:
        return 0
    for row, col in directions:
        current_position = list([r_q + row, c_q + col])
        while 1 <= current_position[0] <= n and 1 <= current_position[1] <= n and current_position not in obstacles:
            current_position = list([current_position[0] + row, current_position[1] + col])
            counter += 1
    return counter


def main():
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))
    result = queensAttack(n, r_q, c_q, obstacles)

    print(result)


if __name__ == '__main__':
    main()
