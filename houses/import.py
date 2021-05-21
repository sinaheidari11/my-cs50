import cs50
import csv
from sys import argv

if len(argv) != 2:
    print('Usage: python import.py [NAME OF CSV FILE]')
    exit(1)

db = cs50.SQL("sqlite:///students.db")
with open(argv[-1], "r") as characters:

    # Create DictReader
    reader = csv.DictReader(characters)

    # Iterate over TSV file
    for row in reader:
        # Insert show
        curr_name = row['name'].split()
        first, middle, last = curr_name[0], curr_name[1] if len(curr_name) == 3 else None, curr_name[-1]
        house = row['house']
        birth = row['birth']
# inserting rows
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)


print('Done inserting rows.')
