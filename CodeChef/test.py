#!/usr/bin/python3
import os


os.system("./res")
n = 150000
c = 150
res = 123456
print(str(n) + " " + str(c))
while True:
    line = input()
    items = line.split(" ")
    if (2 == int(items[0])):
        continue
    elif (1 == int(items[0])):
        num = int(items[1])
        if (num < res):
            print(0)
        else:
            print(1)
    elif (3 == int(items[0])):
        num = int(items[1])
        if(res == num):
            print("right")
        else:
            print("wrong")
        break
