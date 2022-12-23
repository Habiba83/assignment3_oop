//Rania Khaled 20210129
//Task2 -> Q9
#include <bits\stdc++.h>
using namespace std;
template <class T>
class Rset
{
private:
    vector<T> v;

public:
    Rset() {}
    Rset(vector<T> obj)
    {
        for (int i = 0; i < int(obj.size()); i++)
        {
            this->v.push_back(obj[i]);
        }
    }
    void add(T item)
    {
        bool check = true;
        for (int i = 0; i < this->v.size(); i++)
        {
            if (v[i] == item)
                check = false;
        }
        if (check)
            this->v.push_back(item);
    }
    void remove(T item)
    {
        for (int i = 0; i < int(this->v.size()); i++)
        {
            if (v[i] == item)
                v.erase(v.begin() + i);
        }
    }
    int size()
    {
        return this->v.size();
    }
    bool exist(T item)
    {
        bool check = false;
        for (int i = 0; i < int(this->v.size()); i++)
        {
            if (v[i] == item)
                check = true;
        }
        return check;
    }
    T *array()
    {
        T *arr = new T[this->v.size()];
        for (int i = 0; i < int(this->v.size()); i++)
        {
            arr[i] = v[i];
        }
        return arr;
    }
    friend ostream &operator<<(ostream &out, Rset<T> rhs)
    {
        for (int i = 0; i < int(rhs.size()); i++)
        {
            out << rhs.v[i] << endl;
        }
        return out;
    }
    T &operator[](int index)
    {
        if (index >= this->size())
        {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return this->v[index];
    }
};

int main()
{
    vector<string> ve = {"a", "b", "c"};
    Rset<string> obj(ve);
    obj.add("5");
    cout << obj[4];
}