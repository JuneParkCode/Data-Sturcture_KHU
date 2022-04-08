class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class QueType:
    def __init__(self):
        self.front = None
        self.rear = None

    def make_empty(self):
        while self.front != None:
            tempPtr = self.front
            self.front = self.front.next
            del tempPtr
        self.rear = None

    def is_full(self):
        try:
            location = NodeType("test")
            del location
            return False
        except:
            return True

    def is_empty(self):
        return self.front == None

    def enqueue(self, item):
        newNode = NodeType(item)
        if self.rear is None:
            self.front = newNode
            self.rear = newNode
        else:
            temp = self.rear
            self.rear = newNode
            temp.next = newNode

    def dequeue(self):
        item = None
        if self.is_empty():
            return None
        if self.front is self.rear:
            self.rear = None
            item = self.front.info
            del self.front
            self.front = None
        else:
            node = self.front
            self.front = node.next
            item = node.info
            del node
        return item

        
