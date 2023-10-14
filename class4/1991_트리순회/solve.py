import sys

def Input_Data():
    readl = sys.stdin.readline
    N = int(readl())
    inp = [list(map(str, readl().split())) for _ in range(N)]
    tree = dict()
    for v, l, r in inp:
        tree[v] = (l, r)
    return N, tree

N, tree = Input_Data()

preorder = ""
inorder = ""
postorder = ""

def getOrder(node):
    global preorder, inorder, postorder
    preorder += node
    (l, r) = tree[node]
    if l != '.':
        getOrder(l)
    inorder += node
    if r != '.':
        getOrder(r)
    postorder += node

getOrder('A')
print(preorder)
print(inorder)
print(postorder)