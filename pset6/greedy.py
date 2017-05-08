"""
CS50

Problem set6

Mohammed Attya

"""

while True:
    change = input('hai! How much change is owed? ')
    try:
        change = float(change) * 100
    except Exception as e:
        print('Retry: ...')
    else:
        break

if change < 0:
    print('change must be > 0')
    exit(1)

counter = 0
while change > 0:
    if change >= 25:
        change -= 25
        counter += 1

    elif change >= 10:
        change -= 10
        counter += 1

    elif change >= 5:
        change -= 5
        counter += 1

    else:
        change -= 1
        counter += 1
print(counter)
