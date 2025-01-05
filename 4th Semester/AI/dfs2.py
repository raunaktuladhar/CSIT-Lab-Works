adj_list = {
    "a" : ["b", "c", "d"],
    "b" : ["e", "f"],
    "c" : ["g", "h"],
    "d" : ["i"],
    "e" : [],
    "f" : [],
    "g" : [],
    "h" : [],
    "i" : ["j"],
    "j" : []
}

closed_list = {}
output = []

for node in adj_list.keys():
    closed_list[node] = "not visited"

def dfs(startnode):
    closed_list[startnode] = "visited"
    output.append(startnode)

    for v in adj_list[startnode]:
        if closed_list[v] != "visited":
            dfs(v)

startnode = input("Enter the node from where you can traverse: ")
dfs(startnode)
print("Traversed nodes are: ", output)
