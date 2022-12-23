//Rania Khaled 20210129
//Task2 -> Q5
#include <bits\stdc++.h>
using namespace std;
class board
{
    int n = 5;
    string **arr = new string *[n];

public:
    board()
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = new string[5];
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = " ";
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            arr[0][i] = "t"+to_string(i);
            arr[i][0] = "l"+to_string(i);
        }
    }
    void print()
    {
        cout << "---------------------" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "|";
            for (int j = 0; j < 5; j++)
            {
                cout << ' ' << this->arr[i][j] << " |";
            }
            cout << endl;
            cout << "---------------------" << endl;
        }
    }
    void move(string obj)
    {
        char c=obj[0];
        int row=0,colomn=0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (arr[i][j]==obj){
                    row=i;
                    colomn=j;
                   break;}
            }
        }
        
        if (c == 'l')
        {
         if (this->arr[row][colomn + 1] == " ")
            {
                this->arr[row][colomn] = " ";
                this->arr[row][colomn + 1] = obj;
            }
            else if (this->arr[row][colomn + 1] != " "&&this->arr[row][colomn + 2] == " ")
            {
                this->arr[row][colomn + 2] = obj;
                this->arr[row][colomn] = " ";
            }
        }
        else if (c=='t')
        {
           if (this->arr[row + 1][colomn] == " ")
            {
                this->arr[row + 1][colomn] = obj;
                this->arr[row][colomn] = " ";
            }
            else if (this->arr[row + 1][colomn] != " " && this->arr[row+2][colomn] ==" ")
            {
                this->arr[row + 2][colomn] = obj;
                this->arr[row][colomn] = " ";
            }
        }
    }
    int checkingforwinner()
    {

        int counter1 = 0, counter2 = 0;
        for (int i = 1; i < 4; i++)
        {
            if (arr[i][4] != " ")
                counter1++;
        }
        if (counter1 == 3)
            return 1;
        for (int i = 1; i < 4; i++)
        {
            if (arr[4][i] != " ")
                counter2++;
        }
        if (counter2 == 3)
            return 2;
    }
};
class game
{
    board b;
    int turn = 1;

public:
    game()
    {
        while (true)
        {
            cout<<"player "<<turn<<"'s turn"<<endl;
             b.print();
            cout<<"enter the rocket you want to move"<<endl;
            string rocket;
            cin>>rocket;
            b.move(rocket);
            int c = b.checkingforwinner();
            if (turn==1)
                turn=2;
            else
                turn==1;
            if (c == 1)
            {
                b.print();
                cout << "player 1 won" << endl;
                break;
            }
            else if (c == 2)
            {
                b.print();
                cout << "player 2 won" << endl;
                break;
            }
        }
    }
};
