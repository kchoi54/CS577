def fulkerson(graph, s, t):
    def dfs(graph, s, t, visited, flow):
        visited[s] = True
        if s == t:
            return flow
        for i in range(len(graph)):
            if not visited[i] and graph[s][i] > 0:
                new_flow = min(flow, graph[s][i])
                returned_flow = dfs(graph, i, t, visited, new_flow)
                if returned_flow > 0:
                    graph[s][i] -= returned_flow
                    graph[i][s] += returned_flow
                    return returned_flow
        return 0

    max_flow = 0
    while True:
        visited = [False] * len(graph)
        flow = dfs(graph, s, t, visited, float("inf"))
        if flow == 0:
            break
        max_flow += flow

    return max_flow

t = int(input())
for _ in range(t):
    m, n, edges = [int(num) for num in input().split(" ")]

    graph = [[0] * (m+n+2) for _ in range(m+n+2)]
    flow = [[0] * (m+n+2) for _ in range(m+n+2)]
    
    graph[0] = [0] + [1] * m + [0] * (n+1)
    for i in range(n):
        graph[m+1+i][-1] = 1
    
    for i in range(edges):
        e = [int(num) for num in input().split(" ")]

        graph[e[0]][e[1]+m] = 1

    max_flow = fulkerson(graph, 0, len(graph)-1)
    print(max_flow, "Y" if max_flow == n and max_flow == m else "N")