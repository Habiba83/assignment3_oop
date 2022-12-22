#include <bits/stdc++.h>
using namespace std;
template <class T>
class HRvector
{
private:
    int v_size, capacity;
    T *Aptr;

public:
    // constructors and Big 4
    HRvector(int cap = 1)
    {
        capacity = cap;
        Aptr = new T[capacity];
        v_size = capacity;
        Aptr = new T[capacity];
    }
    HRvector(T *arr, int n)
    {
        v_size = n;
        Aptr = new T[n];
        for (int i = 0; i < n; i++)
        {
            *(Aptr + i) = *(arr + i);
        }
    }
    HRvector(HRvector &obj)
    {
        v_size = obj.v_size;
        capacity = obj.capacity;
        Aptr = new T[capacity];
        for (int i = 0; i < obj.v_size; i++)
        {
            *(Aptr + i) = *(obj.Aptr + i);
        }
    }
    HRvector &operator=(HRvector &obj)
    {
        if (this != &obj)
        {
            delete[] Aptr;
            v_size = obj.v_size;
            capacity = obj.capacity;
            Aptr = new T[capacity];
            for (int i = 0; i < obj.v_size; i++)
            {
                *(Aptr + i) = *(obj.Aptr + i);
            }
        }
        else if (this == obj)
        {
            return *this;
        }
    }
    HRvector &operator=(HRvector &&obj)
    {
        if (this != &obj)
        {
            delete[] Aptr;
            v_size = obj.v_size();
            capacity = obj.capacity;
            Aptr = new T[capacity];
            for (int i = 0; i < obj.v_size; i++)
            {
                *(Aptr + i) = *(obj.Aptr + i);
            }
            obj.Aptr = nullptr;
        }
        else if (this == obj)
        {
            return *this;
        }
    }
    ~HRvector()
    {
        delete[] Aptr;
    }
    // acess operations
    T &operator[](int &index)
    {
        if (index < 0 || index > v_size - 1)
            subscript_error();
        else
            return *(Aptr + index);
    }
    void subscript_error()
    {
        cout << "ERROR this index is out of range";
        exit(-1);
    }
    // capacity operations
    int get_size() const
    {
        // returning size
        return v_size;
    }
    int get_capacity() const
    {
        // returning capacity
        return capacity;
    }
    bool empty()
    {
        // checking if the vector is empty
        if (v_size == 0)
        {
            return true;
        }
        else
            return false;
    }
    void clear()
    {
        delete[] Aptr;
        Aptr = new T[capacity];
        v_size = 0;
        // cout << " the vector cleared" << endl;
    }
    void resize(int new_size)
    {
        v_size = new_size;
        capacity = new_size;
    }
    void push_back(T element)
    {
        if (v_size < capacity)
        {
            Aptr[v_size++] = element;
        }
        else
        {
            T *newAptr = new T[capacity * 2];
            capacity *= 2;
            for (int i = 0; i < v_size; i++)
            {
                newAptr[i] = Aptr[i];
            }
            delete[] Aptr;
            Aptr = newAptr;
            newAptr = nullptr;
            Aptr[v_size++] = element;
        }
    }
    void pop_back()
    {
        if (v_size == 0)
        {
            cout << "the vector has no elemets";
        }
        else
            --v_size;
    }
    bool operator==(HRvector<T> &obj)
    {
        if (this->v_size != obj.v_size)
            return false;
        else
        {
            for (int i = 0; i < obj.v_size; i++)
            {
                if (this->Aptr[i] != obj[i])
                    return false;
            }
        }
        return true;
    }
    bool operator<(HRvector<T> &obj)
    {
        int len = (this->v_size < obj.v_size) ? this->v_size : obj.v_size;
        for (int i = 0; i < len; i++)
        {
            if (this->Aptr[i] < obj[i])
                return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, HRvector<T> obj)
    {
        for (int i = 0; i < obj.v_size; i++)
        {
            out << obj[i] << endl;
        }
        return out;
    }
    typedef T *Iterator;
    Iterator begin()
    {
        return &Aptr[0];
    }
    Iterator end()
    {
        // int end = this->v_size;
        return &Aptr[this->v_size];
    }
    void erase(const Iterator i)
    {
        if (i > this->end() || i < this->begin())
            throw "index out of range";
        HRvector<T> temp(0);
        Iterator t = this->begin();
        for (int k = 0; k < this->v_size; k++)
        {
            if (t != i)
            {
                temp.push_back(this->Aptr[k]);
            }
            t++;
        }
        this->clear();
        for (int k = 0; k < temp.v_size; k++)
        {
            this->push_back(temp.Aptr[k]);
        }
    }
    void erase(Iterator i1, Iterator i2)
    {
        if (i1 > this->end() || i2 > this->end() || i1 < this->begin() || i2 < this->begin())
            throw "index out of range";

        HRvector<T> temp(0);
        int i = 0, j = (this->v_size - 1);
        for (Iterator t = this->begin(); t < i1; t++)
        {
            temp.push_back(this->Aptr[i]);
            i++;
        }
        for (Iterator t = this->end()-1; t > i2; t--)
        {
            temp.push_back(this->Aptr[j]);
            j--;
        }
        this->clear();
        for (int k = 0; k < temp.v_size; k++)
        {
            this->push_back(temp.Aptr[k]);
        }
    }
    void insert(Iterator i, T element)
    {
        if (i > this->end() || i < this->begin())
            throw "index out of range";
        HRvector<T> temp(1);
        static int j = 0;
        temp.clear();
        for (int k = 0; k < this->get_size(); k++)
        {
            temp.push_back(this->Aptr[k]);
        }
        for (Iterator t = this->begin(); t <= this->end(); t++)
        {
            if (t == i)
            {
                break;
            }
            j++;
        }
        this->v_size += 1;
        for (int i = j; i < this->v_size; i++)
        {
            if (i == j)
            {
                this->Aptr[i] = element;
            }
        }
        for (int k = j + 1; k < this->v_size; k++)
        {
            this->Aptr[k] = temp[j];
            j++;
        }
    }
};
