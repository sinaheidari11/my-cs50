# including library
from cs50 import get_string
# making input
text = get_string("Text: ")
# creating variables
letters = words = sentences = 0
# starting to count letters,words and sentences
for char in text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ['?', '.', '!']:
        sentences += 1

words += 1
# using this formula to grade texts
L = (letters * 100.0) / words
S = (sentences * 100.0) / words
result = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)
if result < 1:
    print("Before Grade 1")
elif result >= 16:
    print("Grade 16+")
else:
    print(f"Grade {result}")