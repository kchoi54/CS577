import random

num_x = int(input())
num_c = int(input())

clause = []
for _ in range(num_c):
    c = [int(num) for num in input().split(" ")]
    c = list(map(lambda x: (x>>int(1e64), abs(x)-1), c))
    f = lambda c, x :  bool(c[0][0]+x[c[0][1]]) and bool(c[1][0]+x[c[1][1]]) and bool(c[2][0]+x[c[2][1]])
    
    clause.append((c, f))

satisfied = 0
while satisfied < 2:
    X = random.choices([True, False], k=num_x)
    satisfied = sum(map(lambda cf: cf[1](cf[0], X), clause))

output = ""
for x in X:
    output += "1 " if x else "-1 "
print(output[:-1])