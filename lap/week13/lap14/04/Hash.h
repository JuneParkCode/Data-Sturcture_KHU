#include "Student.h"
#include <cstring>

const int MAX_ITEMS = 20000;

int getSumOfString(char *str)
{
    int len = strlen(str);
    int sum = 0;
    if (len % 2 == 1) len ++; // make len even
    for (int j = 0; j < len; j+=2)
        sum = (sum + 100 * str[j] + str[j+1]) % 19937;
    return sum;
}

template<class T>
class HashTable
{
    private:
        T info[MAX_ITEMS];
        T emptyItem;
        int length;
    public:
        // HashTable()
        // {
        //     length = 0;
        //     emptyItem = 
        // }
        HashTable(T emptyKey)
        {
            length = 0;
            emptyItem = emptyKey;
        }
        int Hash(char *key) const
        {
            return (getSumOfString(key) % MAX_ITEMS);
        }
        void RetrieveItem(T &item, bool &found)
        {
            int idx = Hash(item.getKey());
            while (
                idx < MAX_ITEMS 
                && info[idx] != item 
                && info[idx] != emptyItem
                )
            {
                ++idx;
            }
            found = (info[idx] == item && idx < MAX_ITEMS);
        }
        void InsertItem(T item)
        {
            int location;
            location = Hash(item.getKey());
            while (info[location] != item.emptyItem())
                location = (location + 1) % MAX_ITEMS;
            info[location] = item;
            length++;
        }
};