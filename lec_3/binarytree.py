class Node:
    def __init__(self, num):
        self.n = num
        self.left = None
        self.right = None

    def setLeft(self, node):
        self.left = node

    def setRight(self, node):
        self.right = node
    
def left(i):
    return 2*i + 1;

def right(i):
    return 2*i + 2;

def create(ar, node, i):
    node.n = ar[i]

def createTree(ar, node, i, head):
    if i == 0:
        head = node
        head.left = Node(0)
        head.right = Node(0)
    
    if right(i) < len(ar) and i != 0:  
        create(ar, node, i)
        node.left = Node(0)
        node.right = Node(0)
    
    if right(i) >= len(ar):
        node.left = None
        node.right = None
        
    if node.left != None and node.right != None:
        createTree(ar, node.left, left(i), head)
        createTree(ar, node.right, right(i), head)

def main():
    head = Node(2)
    ar = [1,2,3,4,5,6,6,7]

    createTree(ar, head, 0, head)
    print(head.n)
    print(head.left.left.n)

if __name__ == "__main__":
    main()