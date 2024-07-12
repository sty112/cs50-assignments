from cs50 import get_int

size = get_int("Height: ")
while(True):
    if(size > 0 and size < 9):
        break
    else:
        size = get_int("Height: ")

for i in range(size):
    print(" "*(size-i-1), end="")
    print("#"*(i+1), end="")
    print("  ", end = "")
    print("#"*(i+1), end="")
    print()
