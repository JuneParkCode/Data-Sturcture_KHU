MAX_ITEMS = 100
LESS = 0
GREATER = 1
EQUAL = 2

 

class ItemType:

    def __init__(self, val):
        self.value = val
       

    def compared_to(self, item):
        #"[가]"
        if self.value < item.value :
            return LESS
        elif self.value > item.value:
            return GREATER
        else :
            return EQUAL


    def print(self):
        print(self.value, end='')

 

class SortedType:

    def __init__(self):
        self.length = 0
        self.info = []
        self.current_pos = -1

   

    def insert_item(self, item):
        location = 0
        more_to_search = location < self.length

        #“[나]”
        while more_to_search == True:
            comp = self.info[location].compared_to(item)
            if comp is GREATER :
                more_to_search = False
            elif comp is EQUAL :
                more_to_search = False
            else :
                location += 1
                more_to_search = location < self.length


        self.info.insert(self.length, item)
     

        for i in range(self.length, location, -1):
            self.info[i] = self.info[i-1]

        self.info[location] = item
        self.length += 1

    def reset_list(self):

        self.current_pos = -1

   

    def get_next_item(self):

        self.current_pos += 1

        return self.info[self.current_pos]

 

if __name__ == '__main__':

    my_sort = SortedType()

   

    N = int(input("N: "))

    M = int(input("M: "))

    k = int(input("k: "))

   

    #”[다]”
    i = 1
    j = 1
    while i <= N:
        j = 1
        while j <= M:
            my_sort.insert_item(ItemType(i*j))
            j+=1
        i+=1   

    my_sort.reset_list()

   

    for i in range(k):

        result = my_sort.get_next_item()
    result.print()