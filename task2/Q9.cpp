#include <bits\stdc++.h>
using namespace std;
template <class T>
class set1
{
private:
    vector<T> v;

public:
    set1(){}
    set1(vector<T> obj)
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
    friend ostream &operator<<(ostream &out, set1<T> obj)
    {
        for (int i = 0; i < int(obj.size()); i++)
        {
            out << obj.v[i] << endl;
        }
        return out;
    }
    T& operator[](int index)
{
    if (index >= this->size()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return this->v[index];
}
};

int main()
{
    vector<string> ve={"a","b","c"};
    set1<string> obj(ve);
    obj.add("5");
    cout<<obj[1];
}