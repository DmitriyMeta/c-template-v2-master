#include <iostream>
#include <stdexcept>
template <typename T, unsigned N> class Vector
{
  private:
    T *temp;
    unsigned size;
    unsigned capacity;

  public:
    Vector() : temp(nullptr), size(0), capacity(N) { temp = new T[N]; }
    void add(T &value)
    {
        if (capacity == size) {
            capacity *= 2;
            T *p = new T[capacity];
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
            T *p = new T[capacity];
            for (unsigned i = 0; i < size; ++i) {
                p[i] = temp[i];
            }
            delete[] temp;
            temp = p;
        }
    }

    Vector(const Vector &other)
        : temp(new T[other.size]), size(other.size), capacity(other.size)
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
        temp = new T[size];
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

    T *begin() { return temp; }

    T *end() { return temp + size; }

    Vector(T *begin, T const *end) : temp(nullptr), size(0), capacity(N)
    {
        temp = new T[N];
        for (auto *i = begin; i != end; ++i) {
            add(*i);
        }
    }

    ~Vector() { delete[] temp; }
};

int main()
{
    return 0;
}