from cs50 import get_int
# Check if users input is greater than 0 and less than 8.
while True:
    height = get_int("Height: ")
    if height > 0 and height <= 8:
        break

# Set variables based on users input.
width = height - 1
block = 1

# Loop through the height while printing the spaces and blocks.
for _ in range(height):
    print(" " * width, end="")
    width -= 1
    print("#" * block, end="  ")
    print("#" * block)
    block += 1
