# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

for i in range(height):
    for j in range(height - i):
        print(" ")

        for k in range(i):
            print("#")