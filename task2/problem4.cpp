
#include<iostream>
using namespace std;

void RedGreen(int n, string arr[], int index)
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
    RedGreen(n, arr, index+1);
    
    arr[index] = "Green ";
    RedGreen(n, arr, index+1);
}

void RedYellowGreen(int n, string arr[], int index)
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
    RedYellowGreen(n, arr, index+1);

    arr[index] = "Yellow ";
    RedYellowGreen(n, arr, index+1);
    
    arr[index] = "Green ";
    RedYellowGreen(n, arr, index+1);
}
 
int main()
{
    int n;
    int choice;

    cout << "Does your country have traffic lights in Red, Yellow and Green colors or in Red and Green colors?" << endl;
    cout << "Enter 1 for Red, Yellow and Green colors or 2 for Red and Green colors : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Please enter the number of traffic lights you have passed : ";
        cin >> n;
        string arr[n];
        RedYellowGreen(n, arr, 0);
    }
    else if (choice  == 2)
    {
        cout << "Please enter the number of traffic lights you have passed : ";
        cin >> n;
        string arr[n];
        RedGreen(n, arr, 0);
    }
}