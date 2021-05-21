# this programm will print (#) like a mario block
# definnig main function
def main():
    while True:
        # asking user for height
        height = int(input("Height: "))
        width = height
        if height >= 0 and height <= 8:
            break

    for i in range(1, height + 1):
        num_hashes = i
        num_spaces = width - num_hashes
# printinnig blocks
        print(" " * num_spaces, end="")
# printinnig blocks
        print("#" * num_hashes, end="")
# printinnig blocks
        print("  ", end="")
# printinnig blocks
        print("#" * num_hashes)


if __name__ == "__main__":
    main()
