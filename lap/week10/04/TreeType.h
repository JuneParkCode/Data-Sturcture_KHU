#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;
#include "QueType.h"
#include "SortedType.h"
enum OrderType
{
  PRE_ORDER,
  IN_ORDER,
  POST_ORDER
};
class TreeType
{
public:
  TreeType();  // constructor
  ~TreeType(); // destructor
  TreeType(const TreeType &originalTree);
  void operator=(const TreeType &originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int LengthIs() const;
  void RetrieveItem(ItemType &item, bool &found);
  void InsertItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  void GetNextItem(ItemType &item, OrderType order,
                   bool &finished);
  void Print(std::ofstream &outFile) const;

private:
  TreeNode *root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

void AddElement(TreeType &tree, int Array[], int from, int to);
void MakeTree(TreeType &tree, SortedType<int> &list);