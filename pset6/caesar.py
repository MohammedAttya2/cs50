"""
CS50

Problem set6

Mohammed Attya

"""

import sys

if len(sys.argv) != 2:
    print('Usage: python caesar.py k')
    exit(1)

# check if the user inter a valid key
try:
    key = int(sys.argv[1])
except Exception as e:
    print('Usage: python caesar.py k')
    exit(1)

message = input('plaintext: ')

encrypted = ''

# iterate over the message
for c in message:
    # convert character to associative integer
    i = ord(c)

    if i >= 65 and i <= 65 + 26:
        i = (i + key - 65) % 26 + 65;
    elif i >= 97 and i <= 97 + 26:
        i = (i + key - 97) % 26 + 97;

    # convert the int to character and add it to the encrypted message
    encrypted += chr(i)

print('ciphertext: {}'.format(encrypted))
