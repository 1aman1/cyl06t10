#include <iostream>

void oThen1_Solution1(int arr[], int n)
{
  int left = 0, right = n - 1;

  while (left < right)
  {
    while (!(arr[left] & 1) && left < right)
      left++;

    while (arr[right] & 1 && left < right)
      --right;

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
  // int arr[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

  oThen1_Solution1(arr, 10);

  for (int i = 0; i < 10; ++i)
    std::cout << arr[i] << " ";

  std::cout << std::endl;

  return 0;
}
