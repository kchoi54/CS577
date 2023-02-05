t = int(input())
graphList = []
for i in range(t):
    graphList.append({})
    for n in range(int(input())):
        line = input().split(" ")
        graphList[i][line[0]] = line[1:]

for graph in graphList:
    visited = []
    stack = list(graph.keys())[::-1]
    while stack:
        curr = stack.pop()
        if curr in visited:
            continue
        visited.append(curr)
        stack.extend(graph[curr][::-1])

    output = ""
    for node in visited:
        output+= node+" "
    print(output[:-1])