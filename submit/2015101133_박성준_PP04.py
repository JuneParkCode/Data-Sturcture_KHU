MAX_ITEMS = 100

class StackType:
    def __init__(self):
        self.info = []

    def is_empty(self):
        return (len(self.info) == 0)
        
    def is_full(self):
        return (len(self.info) == MAX_ITEMS)
        
    def push(self, item):
        self.info.append(item)

    def pop(self):
        self.info.pop()

    def top(self):
        return len(self.info)