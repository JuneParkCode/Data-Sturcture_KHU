MAX_ITEMS = 10

class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class StackType:
    def __init__(self):
        self.topPtr = None

    def is_full(self):
        try:
            location = NodeType("test")
            del location
            return False
        except:
            return True

    def is_empty(self):
        return self.topPtr == None

    def push(self, item):
        newNode = NodeType(item)
        if (self.topPtr is None):
            self.topPtr = newNode
        else:
            newNode.next = self.topPtr
            self.topPtr = newNode

    def pop(self):
        if self.topPtr is None:
            self.topPtr = None
        else:
            temp = self.topPtr
            self.topPtr = self.topPtr.next
            temp.next = None
            del temp

    def top(self):
        if self.is_empty():
            print("Failed to Top")
        else:
            return self.topPtr.info

    def __str__(self):
        location = self.topPtr
        while location != None:
            print(location.info, end=" ")
            location = location.next
