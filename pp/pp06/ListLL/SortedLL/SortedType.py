class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class SortedType:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def is_full(self):
        try:
            location = NodeType("test")
            return False
        except:
            return True

    def length_is(self):
        return self.length

    def make_empty(self):
        while self.listData != None:
            tempPtr = self.listData.next
            del self.listData
            self.listData = tempPtr
        self.length = 0

    def retrieve_item(self, item):
        location = self.listData
        found = False
        moreToSearch = location != None

        while moreToSearch and not found:
            if location.info < item:
                location = location.next
                moreToSearch = location != None
            elif location.info == item:
                found = True
            else:
                moreToSearch = False

        return found

    def insert_item(self, item):
        location = self.listData
        predLoc = None
        moreToSearch = location != None
        ####
        newItem = NodeType(item)
        if location is None:
            self.listData = newItem
            self.length += 1
            return
        if location.info > item:
            temp = self.listData
            self.listData = newItem
            newItem.next = temp
            self.length += 1
            return
        found = False
        while not found:
            if location.info == item or location.next is None or \
                (location.info < item and location.next.info > item):
                found = True
            else:
                location = location.next
        predLoc = location
        newItem.next = location.next
        predLoc.next = newItem
        self.length += 1

    def delete_item(self, item):
        location = self.listData
        newItem = NodeType(item)
        if location.info is item:
            location.next = None
            self.listData = None
            self.length -= 1
            del location
            return
        predLoc = None
        moreToSearch = location != None
        found = False
        while moreToSearch and not found:
            if location.next.info < item:
                location = location.next
                moreToSearch = location != None
            elif location.next.info == item:
                found = True
            else:
                moreToSearch = False
        predLoc = location
        location = predLoc.next
        predLoc.next = predLoc.next.next
        location.next = None
        del location
        self.length -= 1
        
    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        item = self.currentPos.info
        self.currentPos = self.currentPos.next

        return item

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return " ".join(items)
