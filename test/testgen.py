#!/usr/bin/python3.5
from random import randint


n = 5
q = 1000
print(n)
print(q)
for i in range(0,n):
    print(randint(0,50),randint(0,50))

for i in range(0,q):
    print(randint(0,50),randint(0,50),randint(0,100))
