from math import log10, ceil
 
a, b = map(int, input().split())
 
print(ceil(log10(a) * b))
