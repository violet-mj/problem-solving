s = input()
UCPC = 'UCPC'
k = 0

    
for i in s:
  if i == UCPC[k]:
    k += 1
    if k == 4:
        break

if k >= 4:
  print("I love UCPC")
else:
  print("I hate UCPC")
