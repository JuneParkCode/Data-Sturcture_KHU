class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None
        self.back = None

class DoublyLL:
    def __init__(self):
        self.head = NodeType('head')
    
    def find_item(self, item):
        '''[1]'''
        node = self.head
        while node is not None :
            if node.info is item :
                return node
            node = node.next
        return None
    
    def insert_item(self, item, new):
        '''[2]'''
        node = self.find_item(item)
        if node is None :
            node = self.head
        newNode = NodeType(new)
        if node.next is not None :
            node.next.back = newNode
        newNode.next = node.next
        newNode.back = node
        node.next = newNode
        return

    def delete_item(self, item):
        '''[3]'''
        node = self.find_item(item)
        if node is None :
            return
        else:
            node.back.next = node.next
            node.next.back = node.back
        del node    
        return

    def __str__(self):
        cur_node = self.head
        items = []
        while cur_node is not None:
            items.append("(" + str(cur_node.info) + ")\n")
            cur_node = cur_node.next
        return "".join(items)