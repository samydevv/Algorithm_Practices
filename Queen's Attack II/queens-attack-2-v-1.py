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
    rowDown = rowUp = colLeft = colRight = top = down = counter = 0
    rowDown_obstacle = rowUp_obstacle = colLeft_obstacle = colRight_obstacle = topLeft_obstacle = topRight_obstacle = \
        downLeft_obstacle = downRight_obstacle = False

    while not rowDown_obstacle or not rowUp_obstacle or not colLeft_obstacle or not colRight_obstacle or not \
            topLeft_obstacle or not topRight_obstacle or not downLeft_obstacle or not downRight_obstacle:

        # fixed row, moving column
        colLeft += 1
        if (0 <= ((c_q - 1) - colLeft) <= n - 1 and list(
                [(r_q - 1), (c_q - 1) - colLeft]) not in obstacles and not colLeft_obstacle):
            counter += 1
        else:
            colLeft_obstacle = True

        colRight += 1
        if (0 <= ((c_q - 1) + colRight) <= n - 1 and list(
                [(r_q - 1), (c_q - 1) + colLeft]) not in obstacles and not colRight_obstacle):
            counter += 1
        else:
            colRight_obstacle = True

        # fixed column , moving row
        rowDown += 1
        if (0 <= ((r_q - 1) - rowDown) <= n - 1 and list(
                [(r_q - 1) - rowDown, c_q - 1]) not in obstacles and not rowDown_obstacle):
            counter += 1
        else:
            rowDown_obstacle = True

        rowUp += 1
        if (0 <= ((r_q - 1) + rowUp) <= n - 1 and list(
                [(r_q - 1) + rowUp, c_q - 1]) not in obstacles and not rowUp_obstacle):
            counter += 1
        else:
            rowUp_obstacle = True

        # moving diagonals up left and up right
        top += 1
        if (0 <= ((r_q - 1) + top) <= n - 1 and 0 <= ((c_q - 1) - colLeft) <= n - 1 and list(
                [(r_q - 1) + top, (c_q - 1) - colLeft]) not in obstacles and not topLeft_obstacle):
            counter += 1
        else:
            topLeft_obstacle = True

        if (0 <= ((r_q - 1) + top) <= n - 1 and 0 <= ((c_q - 1) + colLeft) <= n - 1 and list(
                [(r_q - 1) + top, (c_q - 1) + colLeft]) not in obstacles and not topRight_obstacle):
            counter += 1
        else:
            topRight_obstacle = True

        # moving diagonals down left and down right
        down += 1
        if (0 <= ((r_q - 1) - down) <= n - 1 and 0 <= ((c_q - 1) - colLeft) <= n - 1 and list(
                [(r_q - 1) - down, (c_q - 1) - colLeft]) not in obstacles and not downLeft_obstacle):
            counter += 1
        else:
            downLeft_obstacle = True

        if (0 <= ((r_q - 1) - down) <= n - 1 and 0 <= ((c_q - 1) + colLeft) <= n - 1 and list(
                [(r_q - 1) - down, (c_q - 1) + colLeft]) not in obstacles and not downRight_obstacle):
            counter += 1
        else:
            downRight_obstacle = True

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
        obstacles.append(list(x - 1 for x in map(int, input().rstrip().split())))
    result = queensAttack(n, r_q, c_q, obstacles)

    print(result)


if __name__ == '__main__':
    main()
