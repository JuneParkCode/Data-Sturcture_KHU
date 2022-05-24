#include <iostream>
#include <stdexcept>
float  Divide(int x, int y)
{
  if (y == 0)
    throw std::overflow_error("Divided by zero!");
  return (x / y);
}

int main(void)
{
  float res;
  try
  {
    res = Divide(5, 0);
  }
  catch (std::overflow_error &e)
  {
    std::cout << e.what() << std::endl;
  }

  std::cout << res << std::endl;
  return (0);
}