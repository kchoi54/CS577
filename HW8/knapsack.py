t = int(input())
for _ in range(t):
    size, capacity = [int(num) for num in input().split(" ")]

    v = [[0]*(capacity+1)]
    for i in range(1, size+1):
        w_i, v_i =[int(num) for num in input().split(" ")]
        v.append([0])
        for w in range(1, capacity+1):
            x = 0 if w_i > w else 1
            v[i].append(max(v[i-1][w], x*(v[i-1][max(w-w_i, 0)]+v_i)))

    print(v[size][capacity])