#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

constexpr int RANDOM_RANGE = 200;
constexpr int SIZE = 12;

class Array_t
{
protected:
    std::vector<int> array;
    int _size_of_arr = 0;

public:
    Array_t(int x);
    void print_array();
};

Array_t::Array_t(int len)
{
    array.resize(len);
    _size_of_arr = len;

    srand(time(nullptr));
    std::generate(array.begin(),
                  array.end(),
                  []()
                  { return rand() % RANDOM_RANGE; });
}

void Array_t::print_array()
{
    std::cout << "\narray: ";
    for (auto itr = array.begin(); itr != array.end(); ++itr)
    {
        std::cout << *itr << " : ";
    }
}

// Heap implementation
class Heap_t : public Array_t
{
private:
    void
    heapify(int, int);

    void
    build_heap();

public:
    Heap_t(int x) : Array_t(x) {}

public:
    void
    push(int);

    int
    pop();

    bool
    is_heap();

    void
    sort_heap();
};

bool Heap_t::is_heap()
{
    for (auto i = 0; i < _size_of_arr / 2; ++i)
    {
        if ((array[i]) < array[i * 2 + 1] ||
            (i * 2 + 2 < _size_of_arr && array[i * 2 + 2] > array[i]))
            return false;
    }
    return true;
}

int Heap_t::pop()
{
    int heap_top = array.front();

    std::swap(array.front(), array.back());

    array.pop_back();
    --_size_of_arr;

    build_heap();

    return heap_top;
}

void Heap_t::push(int newValue)
{
    array.push_back(newValue);
    ++_size_of_arr;

    build_heap();
}

void Heap_t::heapify(int index, int heap_len)
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

void Heap_t::build_heap()
{
    for (int i = _size_of_arr / 2 - 1; i >= 0; --i)
    {
        heapify(i, _size_of_arr);
    }
}

void Heap_t::sort_heap()
{
    // first prepare the array sequence into a Heap_t
    build_heap();

    // sort logic
    for (int i = _size_of_arr - 1; i > 0; --i)
    {
        std::swap(array[i], array[0]);
        heapify(0, i);
    }
}

int main()
{
    Heap_t obj(SIZE);

    std::cout << "\nDefault array: ";
    obj.print_array();
    std::cout << "\nis Heap_t ? " << std::boolalpha << obj.is_heap();

    obj.print_array();
    obj.push(500);
    obj.print_array();

    std::cout << "\npopped: " << obj.pop();
    obj.print_array();
    std::cout << "\nis Heap_t ? " << std::boolalpha << obj.is_heap();

    obj.sort_heap();
    obj.print_array();
    std::cout << "\nis Heap_t ? " << std::boolalpha << obj.is_heap();

    obj.push(1000);
    obj.print_array();
    std::cout << "\nis Heap_t ? " << std::boolalpha << obj.is_heap();

    std::cout << std::endl;
    return 0;
}