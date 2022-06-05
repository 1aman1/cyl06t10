#include <iostream>
#include <algorithm>

int binarySearch(int *arr, int left, int right, int x)
{
  if (right >= left)
  {
    int mid = left + (right - left) / 2;

    std::cout << left << " : " << right << std::endl;

    if (arr[mid] == x)
      return mid;

    // If element is smaller than mid, then possibility reduces to left subarray
    if (arr[mid] > x)
      return binarySearch(arr, left, mid - 1, x);

    // If element is smaller than mid, then possibility reduces to right subarray
    return binarySearch(arr, mid + 1, right, x);
  }

  // We reach here when element is not present in array
  return -1;
}

int main()
{
  size_t size;
  int item;

  std::cout << "size of array : ";
  std::cin >> size;

  int *arr = new int[size - 1];

  for (int i = 0; i < size; ++i)
    std::cin >> arr[i];

  std::cout << "find value ? ";
  std::cin >> item;

  binarySearch(arr, 0, size, item) != -1 ? std::cout << "found\n" : std::cout << "cant find\n";

  return 0;
}
