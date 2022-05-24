class TreeNode:

    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
    
class BST():

    def __init__(self):
        self.root = None
        self.order_list = []
    
    def is_empty(self):
        return (self.root == None)
    
    def count_nodes(self, tree):
        '''[1]'''
        if tree is None :
            return (0)
        else :
            return (1 + self.count_nodes(tree.left) + self.count_nodes(tree.right))

    def length_is(self):
        return self.count_nodes(self.root)

    def insert(self, item):
        '''[2]'''
        self.insert_item(self.root, item)
        
    def insert_item(self, node, item):
        '''[3]'''
        if (self.root is None) :
            newNode = TreeNode(item)
            self.root = newNode
        elif (node is None) :
            newNode = TreeNode(item)
            node = newNode
            return node
        elif (item < node.info) :
            node.left = self.insert_item(node.left, item)
            return node
        else :
            node.right = self.insert_item(node.right, item)
            return node

  
    def inorder(self, node):
        '''[4]'''
        if (node is not None):
            self.inorder(node.left)
            self.order_list.append(node.info)
            self.inorder(node.right)
    
    def preorder(self, node):
        '''[5]'''
        if (node is not None):
            self.preorder(node.left)
            self.preorder(node.right)
            self.order_list.append(node.info)
    
    def postorder(self, node):
        '''[6]'''
        if (node is not None):
            self.preorder(node.right)
            self.preorder(node.left)
            self.order_list.append(node.info)

    def delete(self, item):
        '''[7]'''
        self.delete_node(self.root, item)
    
    def delete_node(self, current, item):
        '''[8]'''
        ''' NOT WORKS'''
        if (item < current.info):
            self.delete_node(current.left, item)
        elif (item > current.info):
            self.delete_node(current.right, item)
        else :
            del current

    def get_predecessor(tree, data):
        '''[9]'''
        while (tree.right != None):
            tree = tree.right
        data = tree.info
        
