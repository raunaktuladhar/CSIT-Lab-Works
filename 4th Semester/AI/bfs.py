import queue 
adj_list={
    "a":["b","c","d"],
    "b":["e","f"],
    "c":["g","h"],
    "d":["i"],
    "e":[],
    "f":[],
    "g":[],
    "h":[],
    "i":["j"],
    "j":[]

}

visited=[]
queue=[]
traversed_output=[]
def bfs(visited,graph,node):
    visited.append(node)
    queue.append(node)

    while queue:
        m=queue.pop(0)
        traversed_output.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)
    print("Traversed output =",traversed_output)
        
    

node=input("Enter the node from where you want to traverse = ")
bfs(visited,adj_list,node)
