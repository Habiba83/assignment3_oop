#include <iostream>
using namespace std;
template <class T>
class stack
{
    T *data;
    int top;
    int capacity;

public:
    class StackOverFlowException{};
    class StackEmptyException{};
    stack(int size = 6);
    void push(T);
    void pop();
    T top_elemnt();
    int size();
    bool isEmpty();
    bool isFull();
    ~stack() {
        delete[] data;
    }
    void operator=(stack&);
};
template <class T>
stack<T>::stack(int n)
{
    data = new T[n];
    capacity = n;
    top = -1;
}
template <class T>
void stack<T>::push(T value)
{
    if (isFull())
    {
        throw StackOverFlowException();
    }

    cout << "Inserting " << value << endl;
    data[++top] = value;
}
template <class T>
void stack<T>::pop()
{
    if (isEmpty())
    {
        throw StackEmptyException();
    }
    T poped=data[top--];
    cout<<poped<<" deleted "<<endl;
}
template <class T>
T stack<T>::top_elemnt(){
    return data[top];
}
template <class T>
int stack<T>::size() {
    return top + 1;
}
template <class T>
bool stack<T>::isEmpty() {
  if(top == -1)
      return true;
  else
      return false;
}
template <class T>
bool stack<T>::isFull() {
    return top == capacity - 1;
}
template<class T>
void stack<T> :: operator=( stack& obj){
    delete [] data;
    capacity = obj.capacity;
    top = obj.top;
    data = new T[capacity];
    for (int i = 0; i<obj.size(); i++) {
        *(data + i) = *(obj.data + i);
    }
}
void manage_stack() {
    cout << "enter the size to create stack:\n";
    int size;
    cin >> size;
    stack<char> st(size);
    cout << "enter ur choice:\n";
    cout << "1)push a value.\n";
    cout << "2)print the top.\n";
    cout << "3)pop from the stack.\n";
    cout << "4)check if empty.\n";
    cout << "5) get size.\n";
    cout << "6) Exit.\n";
    while (true) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            char value;
            cout << "enter the value:";
            cin >> value;
            try {
                st.push(value);
            }
            catch (stack<int>::StackOverFlowException) {
                cout << " sorry,the stack is full" << endl;
            }
        }
        if (choice == 2) {
            cout << st.top_elemnt() << endl;
        }
        if (choice == 3) {
            try {
                st.pop();
            }
            catch (stack<int>::StackEmptyException) {
                cout << "the stack is empty" << endl;
            }
        }
        if (choice == 4) {
            cout << st.isEmpty();
        }
        if (choice == 5) {
            cout << st.size();
        }
        if (choice == 6)
            exit(0);
    }
}
int main(){
    manage_stack();
}