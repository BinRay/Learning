# dijkstra算法从a到g的最短路径

# 1.图表示
graph = {
    'a': { 'b' : 2, 'e' : 6 },
    'b': { 'c' : 3 },
    'c': { 'd' : 2, 'e' : 1 },
    'd': { 'f' : 2, 'g' : 4 },
    'e': { 'f' : 7 },
    'f': { 'g' : 3 },
    'g': { }
}

# 2. 开销表
infinity = float('inf')
costs = {
    'b' : 2,
    'c' : infinity,
    'd' : infinity,
    'e' : 6,
    'f' : infinity,
    'g' : infinity
}

# 3. 已处理表
processed = []
parents = {
    'a' : None,
    'b' : 'a',
    'e' : 'a'
}

def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node

node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if new_cost < costs[n]:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)


def output_path(node):
    path = ['g']
    while node in parents and parents[node] is not None:
        path.append(parents[node])
        node = parents[node]
    path.reverse()
    print(path)

output_path('g')
print(costs['g'])
