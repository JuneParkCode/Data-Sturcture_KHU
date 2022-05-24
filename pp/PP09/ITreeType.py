
from lib2to3.pytree import Node


class NodeType:
    def __init__(self, data):
        self.info = data
        self.left = None
        self.right = None

class IterBST():
    def __init__(self):
        self.root = None
        self.order_list = []

    def insert(self, data):
        '''[10]'''
        node = self.root
        parent = self.root
        direction = -1
        while node is not None :
            if (node.info < data) :
                node = node.right
                parent = node
                direction = 1
            elif (node.info > data) :
                node = node.left
                parent = node
                direction = 0
        newNode = NodeType(data)
        if node is parent :
            self.root = newNode
        elif direction == 0 :
            parent.left = newNode
        else :
            parent.right = newNode

    def find(self, key):
        '''[11]'''
        self.find_node(self.root, key)

    def find_node(self, root, key):
        '''[12]'''
        node = root
        while node.info is not key:
            if node.info < key:
                node = node.right
            elif node.info > key:
                node = node.left
        return node
    
    ''' FAIL '''
    def delete(self, item):
        '''[13]'''
        self.delete_node(self.root, item)
    
    def delete_node(self, current, item):
        '''[14]'''
        ''' NOT WORKS'''
        if (item < current.info):
            self.delete_node(current.left, item)
        elif (item > current.info):
            self.delete_node(current.right, item)
        else :
            del current
    def inorder(self, node):
        '''[15]'''
        if (node is not None):
            self.inorder(node.left)
            self.order_list.append(node.info)
            self.inorder(node.right)
    
    def preorder(self, node):
        '''[16]'''
        if (node is not None):
            self.preorder(node.left)
            self.preorder(node.right)
            self.order_list.append(node.info)
    
    def postorder(self, node):
        '''[17]'''
        if (node is not None):
            self.preorder(node.right)
            self.preorder(node.left)
            self.order_list.append(node.info)

    def get_predecessor(tree, data):
        '''[18]'''
        while (tree.right != None):
            tree = tree.right
        data = tree.info
