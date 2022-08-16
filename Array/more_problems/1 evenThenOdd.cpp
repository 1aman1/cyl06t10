#include <iostream>

// doesn't maintain the order
void evenThenOdd(int arr[], int n)
{
  int left = 0, right = n - 1;
  while (left < right)
  {
    while (arr[right] & 1 && left < right)
      right--;
    while (!(arr[left] & 1) && left < right)
      left++;
    if (left < right)
    {
      arr[left] = arr[left] ^ arr[right];
      arr[right] = arr[left] ^ arr[right];
      arr[left] = arr[left] ^ arr[right];

      ++left;
      --right;
    }
  }
}

int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  evenThenOdd(arr, 10);

  for (auto &e : arr)
    std::cout << e << " ";

  std::cout << std::endl;

  return 0;
}
