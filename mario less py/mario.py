# this programm will print hash like a mario block
# including libraries
from cs50 import get_int

# using while loop
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break
for row in range(1, height + 1):
    # printing blocks
    print(' ' * (height - row) + '#' * row)

