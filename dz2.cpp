#include <iostream>
#include <stdexcept>

template <unsigned N> class Vector
{
  private:
    int *temp;
    unsigned size;
    unsigned capacity;

  public:
    Vector() : temp(nullptr), size(0), capacity(N) { temp = new int[N]; }
    void add(int value)
    {
        if (capacity == size) {
            capacity *= 2;
            int *p = new int[capacity];
            for (unsigned i = 0; i < size; ++i) {
                p[i] = temp[i];
            }
            delete[] temp;
            temp = p;
        }
        temp[size] = value;
        size++;
    }
    void pop()
    {
        --size;
        if (capacity > 2 * size) {
            capacity = size;
            int *p = new int[capacity];
            for (unsigned i = 0; i < size; ++i) {
                p[i] = temp[i];
            }
            delete[] temp;
            temp = p;
        }
    }

    Vector(const Vector &other)
        : temp(new int[other.size]), size(other.size), capacity(other.size)
    {
    }

    Vector &operator=(const Vector &other)
    {
        if (this == &other) {
            return *this;
        }
        delete[] temp;
        size = other.size;
        capacity = other.size;
        temp = new int[size];
        for (unsigned i = 0; i < size; ++i) {
            temp[i] = other.temp[i];
        }
        return *this;
    }

    unsigned get_size() const { return size; }

    int &operator[](unsigned i)
    {
        if (i >= size) {
            throw std::runtime_error("error");
        }
        return temp[i];
    }

    int *begin() { return temp; }

    int *end() { return temp + size; }

    Vector(int *begin, int const *end) : temp(nullptr), size(0), capacity(N)
    {
        temp = new int[N];
        for (auto *i = begin; i != end; i++) {
            add(*i);
        }
    }

    ~Vector() { delete[] temp; }
};

int main()
{
    return 0;
}