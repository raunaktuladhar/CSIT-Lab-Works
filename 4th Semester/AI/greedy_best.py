graph = {
    "s" : {"a" : 3, "b" : 2},
    "a" : {"c" : 4, "d" : 1},
    "b" : {"e" : 3, "f" : 1},
    "c" : {},
    "d" : {},
    "e" : {"h" : 5},
    "f" : {"i" : 2, "g" : 3},
    "g" : {},
    "h" : {},
    "i" : {}

}

heuristic = {
    "s" : 13,
    "a" : 12,
    "b" : 4,
    "c" : 7,
    "d" : 3,
    "e" : 8,
    "f" : 2,
    "g" : 0,
    "h" : 4,
    "i" : 9

}

def gbfs(graph, heuristic, start, goal):
    visited = set()
    queue = [(heuristic[start], [start])]
    while queue:
        (h, path) = queue.pop(0)
        current_node = path[-1]
        if current_node == goal:
            return path
        visited.add(current_node)

        for neighbour, distance in graph[current_node].items():
            if neighbour not in visited:
                new_path = path + [neighbour]
                queue.append((heuristic[neighbour], new_path))
        queue.sort()
    return None

start = input("Enter the start node: ")
goal = input("Enter the goal node: ")
result = gbfs(graph, heuristic, start, goal)

if result: # True or False check garxw
    print("Traversed output: ", result)

else:
    print("Path Not Found")