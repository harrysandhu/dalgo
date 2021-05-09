#!/usr/bin/env python3


s = "aamakhdsjaksjdhxfdfdc"
i = 0
j = 0

largest = j-i+1
left = len(s) - j
res = {}
x = []
while largest < left:
    if s[j] not in res:
        res[s[j]] = j
        if j - i+1 >= largest:
            x = []
            largest = j - i+1
            x.append(i)
            x.append(j)
    else:
        i = res[s[j]] + 1
        j = i
        res = {}
        res[s[j]] = j
        left = len(s) - j      
    j += 1

print(largest, s[x[0]:x[1]+1])
