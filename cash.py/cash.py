# including library
from cs50 import get_float
# using while loop to start the program
while True:
    dollars = get_float("change owened:")
    if dollars >= 0:
        break
# definnig variables
cents = int((dollars * 100) + 0.5)
# definnig the total of coins
total = 0
for coins in [25, 10, 5, 1]:
    total += cents // coins
    cents %= coins
# printing the result
print(total)