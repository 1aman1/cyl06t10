#include <iostream>

int main()
{
	size_t Len, shift;

	std::cin >> Len;
	int *arr = new int[Len - 1];

	std::cout << "the " << Len << " elements are : ";
	for (int i = 0; i < Len; ++i)
		std::cin >> arr[i];

	// shifting elements by this rotation parameter
	std::cin >> shift;

	for (int i = 0; i < Len; ++i)
		std::cout << arr[(i + shift) % Len] << " ";

	std::cout << std::endl;
	return 0;
}
