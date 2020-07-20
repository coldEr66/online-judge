#!/usr/bin/python3.5
from random import randint


n = 20
print(n)
p = 5
print(p)
arr = []
s = ""
for i in range(0,n):
    s += chr(randint(0,9) + ord('0'))
print(s)
