from enum import Enum

MAX_ITEMS = 100

class Compare(Enum):
    LESS = 0
    GREATER = 1
    EQUAL = 2
    
class ItemType:
    """ Item Type """

    def __init__(self, val):
        """ [1] """
        self.value = val

    def compared_to(self, otherItem):
        """ [2] """
        if self.value < otherItem.value :
            return (Compare.LESS)
        elif self.value > otherItem.value :
            return (Compare.GREATER)
        else :
            return (Compare.EQUAL)
    def __str__(self):
        """ [3] """
        return (str(self.value))


class SortedType:
    """ Chapter 3: Sorted List """

    def __init__(self):
        """ [4] """
        self.length = 0
        self.info = [ItemType(0) for i in range(MAX_ITEMS)]
        self.current_pos = -1

    def make_empty(self):
        self.length = 0

    def length_is(self):
        return self.length

    def is_full(self):
        if self.length == MAX_ITEMS:
            return True
        return False

    def insert_item(self, item):
        """ [5] """
        i = 0
        while self.info[i].value < item.value and i < self.length :
            i += 1
        self.length += 1
        temp = 0
        while i < self.length :
            temp = self.info[i]
            self.info[i] = item
            item = temp
            i += 1            

    def retrieve_item(self, item): # Binary Search
        """ [6] """
        first = 0
        last = self.length
        found = False
        while first < last and found == False :
            midPoint = (first + last) // 2
            comp = item.compared_to(self.info[midPoint])
            if (comp == Compare.LESS):
                last = midPoint - 1
            elif (comp == Compare.GREATER):
                first = midPoint + 1
            else :
                found = True
        return (found)

    def delete_item(self, item):
        """ [7] """
        i = 0
        while self.info[i].value != item.value and i < self.length :
            i += 1
        while i < (self.length - 1) :
            self.info[i] = self.info[i + 1]
            i += 1
        self.length -= 1

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        """ [8] """
        return ' '.join(map(str, self.info[0:self.length]))