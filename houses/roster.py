# includin libraries
import cs50
from sys import argv
# usin if statement
if len(argv) != 2:
    print('Usage: python roster.py [NAME OF THE HOUSE]')
    exit(1)

db = cs50.SQL("sqlite:///students.db")
rows = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', argv[-1])
# printing the result
for row in rows:
    print(row['first'] + ' ' + (row['middle'] + ' ' if row['middle'] else '') + row['last'] + ', born' + str(row['birth']))
