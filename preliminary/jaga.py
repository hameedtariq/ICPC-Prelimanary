import heapq

def create_graph(points):
    graph = {}
    for point in points:
        node1, node2 = map(int, point.split())
        if node1 not in graph:
            graph[node1] = []
        graph[node1].append(node2)

        if node2 not in graph:
            graph[node2] = []
        graph[node2].append(node1)
    return graph

def shortest_distances(graph, source): 
    distances = {node: float('inf') for node in graph}
    distances[source] = 0
    priority_queue = [(0, source)]
    while priority_queue:
        dist, current_node = heapq.heappop(priority_queue)
        if dist > distances[current_node]:
            continue

        for neighbor in graph[current_node]:
            new_dist = distances[current_node] + 1
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                heapq.heappush(priority_queue, (new_dist, neighbor))

    return [distances[node] for node in sorted(distances)]

num = int(input())
final = []
for _ in range(num):
    road, crossing = map(int, input().split())
    distances = [0] * (road + 1)
    points = []
    for _ in range(crossing):
        points.append(input())
    graph = create_graph(points)
    for source_node in range(1, road + 1):
        shortest_distances_list = shortest_distances(graph, source_node)
        distances[source_node] = sum(shortest_distances_list)

    # Find the top 5 indexes with the maximum sum
    top_5_indexes = sorted(range(1, road + 1), key=lambda node: distances[node])[:5]
    final.append(top_5_indexes)

for distances in final:
    for x in distances:
        print(x)
