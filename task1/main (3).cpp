#include"HRVector.h"
int main()
{
    vector<int> v = {15, 20, 30, 35, 36};
    int *arr = new int[5]{15, 20, 30, 35, 36};
    HRvector<int> obj3(arr, 5);
    v.insert(v.begin() + 3, 5);
    // cout << "obj size first" << obj3.get_size() << endl;
    obj3.insert(obj3.begin() + 3, 5);
    // cout << "obj size" << obj3.get_size() << endl;
    //  v.insert(v.begin(),2);
    for (int i = 0; i < obj3.get_size(); i++)
    {
        cout << obj3[i] << endl;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[i]" << v[i] << endl;
    }
    /*i
    /*int capacity;
    cin >> capacity;
    HRvector<int> obj1(capacity);
    for (int i = 0; i < capacity; i++)
    {
        cin >> obj1[i];
    }
    cout << (obj1 == obj3) << endl;
    cout << obj1;
    HRvector<int> obj2(obj1);
    int size = obj2.get_size();
    cout << size << endl;
    // obj2.clear();
    obj2.push_back(19);
    obj2.push_back(900);
    obj2.push_back(00);
    obj2.push_back(40);
    obj2.pop_back();
    for (int i = 0; i < obj2.get_size(); i++)
    {
        cout << obj2[i] << endl;
    }
    for (int i = 0; i < obj1.get_size(); i++)
    {
        cout << obj1[i] << endl;
    }
    cout << obj1.get_size() << endl;
    obj2.resize(8);
    cout << obj2.get_size() << endl;
    cout << obj2.get_capacity() << endl;
    cout << obj2.empty() << endl;
    obj2.clear();
    cout << obj2.get_size() << endl;
    cout << obj2.empty() << endl;
    // obj2.pop_back();
    // for(int i=0;i<size;i++){
    // cout<<obj2[i]<<endl;
    //}*/
}