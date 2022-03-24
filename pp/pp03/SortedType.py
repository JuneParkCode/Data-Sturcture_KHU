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

    def compared_to(self, otherItem):
        """ [2] """
    
    def __str__(self):
        """ [3] """

class SortedType:
    """ Chapter 3: Sorted List """

    def __init__(self):
        """ [4] """

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

    def retrieve_item(self, item): # Binary Search
        """ [6] """

    def delete_item(self, item):
        """ [7] """

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        """ [8] """