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

void oThen1_Solution2(int arr[], int n)
{
  int countZeros = 0;
  for (int i = 0; i < 10; ++i)
    if (arr[i] == 0)
      ++countZeros;

  int i;
  for (i = 0; i < n; ++i)
  {
    if (i < countZeros)
      arr[i] = 0;
    else
      arr[i] = 1;
  }
}

int main()
{
  // int arr[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0};

  oThen1_Solution1(arr, 10);
  //  oThen1_Solution2( arr, 10 );

  for (int i = 0; i < 10; ++i)
    std::cout << arr[i] << " ";

  std::cout << std::endl;

  return 0;
}
