"""
CS50

Problem set6

Mohammed Attya

"""

while True:
    n = input('Height: ')
    try:
        n = int(n, 10)
    except Exception as e:
        print('Retry: ...')
    else:
        break

if n > 13 or n < 1:
    print('Height must be a positive number and less than 13')
    exit(1)

for i in range(1, n+1):
    print(' ' * (n - i), end='')
    print('#' * (i + 1))
