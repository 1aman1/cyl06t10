#include <iostream>
#include <vector>
#include <ctime>

#define RANDOM_RANGE 200
#define SIZE 12

class Array
{
private:
    // void test();

protected:
    std::vector<int> array;
    int size_of_arr = 0;

public:
    Array(int x);
    void print_array();
};

Array::Array(int x)
{
    size_of_arr = x;
    srand(time(nullptr));

    for (int i = 0; i < size_of_arr; ++i)
    {
        array.push_back(rand() % RANDOM_RANGE);
    }
}

void Array::print_array()
{
    std::cout << "\narray: ";
    for (auto itr = array.begin(); itr != array.end(); ++itr)
    {
        std::cout << *itr << " : ";
    }
}

// Heap implementation
class heap : public Array
{
private:
    void build_heap();
    void heapify(int, int);

public:
    heap(int x) : Array(x) {}
    void sort_heap();
};

void heap::heapify(int index, int heap_len)
{
    int l = index * 2 + 1;
    int r = index * 2 + 2;
    int largest = index;

    if (l < heap_len && array[l] > array[largest])
        largest = l;

    if (r < heap_len && array[r] > array[largest])
        largest = r;

    if (largest != index)
    {
        std::swap(array[largest], array[index]);

        heapify(largest, heap_len);
    }
}

void heap::build_heap()
{
    for (int i = size_of_arr / 2 - 1; i >= 0; --i)
    {
        heapify(i, size_of_arr);
    }
}

void heap::sort_heap()
{
    // first prepare the array sequence into a heap
    build_heap();

    // sort logic
    for (int i = size_of_arr - 1; i > 0; --i)
    {
        std::swap(array[i], array[0]);
        heapify(0, i);
    }
}

int main()
{
    heap obj(SIZE);

    obj.print_array();

    obj.sort_heap();

    obj.print_array();

    return 0;
}