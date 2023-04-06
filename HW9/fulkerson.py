def find_path(graph, s, t):
    visited = set()
    queue = [s]
    prev = {}
    while len(queue) > 0:
        curr = queue.pop(0)
        visited.add(curr)
        
        if curr == t:
            path = [(prev[t], t, graph[prev[t]][t])]
            while path[0][0] != s:
                path.insert(0, (prev[path[0][0]], path[0][0], graph[prev[path[0][0]]][path[0][0]]))

            return path

        for e, v in enumerate(graph[curr]):
            if v != 0 and e not in visited:
                prev[e] = curr
                queue.append(e)

    return []

t = int(input())
for _ in range(t):
    n_node, n_edge = [int(num) for num in input().split(" ")]

    graph = [[0] * n_node for _ in range(n_node)]
    flow = [[0] * n_node for _ in range(n_node)]
    for i in range(n_edge):
        e = [int(num) for num in input().split(" ")]

        graph[e[0]-1][e[1]-1] += e[2]
    
    path = find_path(graph, 0, n_node-1)

    while len(path) > 0:
        bottle_neck = min([abs(e[2]) for e in path])
        for (u, v, _) in path:
            flow[u][v] += bottle_neck
            graph[u][v] -= bottle_neck
            if graph[u][v] > -1:
                graph[v][u] -= bottle_neck
        
        path = find_path(graph, 0, n_node-1)

    max_flow = sum(flow[0])
    print(max_flow)