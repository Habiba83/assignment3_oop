
//Rania khaled 20210129
//Task2 -> Q4
#include<iostream>
using namespace std;

void TwoColours(int n, string arr[], int index)
{   
    int num = 1;
    
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << num << '.';
            cout << arr[i];
            num++;
        }
        cout << endl;
        return;
    }
    
    arr[index] = "Red ";
    TwoColours(n, arr, index+1);
    
    arr[index] = "Green ";
    TwoColours(n, arr, index+1);
}

void ThreeColours(int n, string arr[], int index)
{   
    int num = 1;
    
    if (index == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << num << '.';
            cout << arr[i];
            num++;
        }
        cout << endl;
        return;
    }
    
    arr[index] = "Red ";
    ThreeColours(n, arr, index+1);

    arr[index] = "Yellow ";
    ThreeColours(n, arr, index+1);
    
    arr[index] = "Green ";
    ThreeColours(n, arr, index+1);
}
 
int main()
{
    int choice,num;

    cout << "Enter 1 for Red, Yellow and Green colors or 2 for Red and Green colors : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Please enter the number of traffic lights: ";
        cin >> num;
        string arr[num];
        ThreeColours(num, arr, 0);
    }
    else if (choice  == 2)
    {
        cout << "Please enter the number of traffic lights : ";
        cin >> num;
        string arr[num];
        TwoColours(num, arr, 0);
    }
}
