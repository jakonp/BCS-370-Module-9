//
//  main.cpp
//  BCS-370-Module-9
//
//  Created by Nick Jakobczyk on 11/22/20.
//

#include <iostream>
#include<stack>

using namespace std;

class appStroke{
    stack<char>stackPrimary;
    stack<char>stackSecondary;

    public:
    void displayScreen()
    {
        stack<char>temp;
        while(!stackPrimary.empty())
        {
            temp.push(stackPrimary.top());
            stackPrimary.pop();
        }
        
        while(!temp.empty())
        {
            cout<<temp.top();
            stackPrimary.push(temp.top());
            temp.pop();
        }
        cout << endl;
    }

    void draw()
    {
        cout<<"Enter new stroke character: ";
        char x;
        cin>>x;
        stackPrimary.push(x);
        displayScreen();
    }

    void erase()
    {
        stackPrimary.pop();
        displayScreen();
    }


    void undo()
    {
        stackSecondary.push(stackPrimary.top());
        stackPrimary.pop();
        displayScreen();
    }

    void redo()
    {
        if(!stackPrimary.empty())
        {
            stackPrimary.push(stackSecondary.top());
            stackSecondary.pop();
        }
        displayScreen();
    }

    
};

int main()
{
    class appStroke Stroke;
  

     int flag = 1;
        while(flag) {
            char val;
            cout << "1 : Draw" << endl;
            cout << "2 : Erase" << endl;
            cout << "3 : Undo" << endl;
            cout << "4 : Redo" << endl;
            cout << "5 : Exit" << endl;
            cout << "Enter your choice: ";
            cin >> val;
            switch(val)
            {
                case '1' : Stroke.draw();
                break;
                case '2' : Stroke.erase();
                break;
                case '3' : Stroke.undo();
                break;
                case '4' : Stroke.redo();
                break;
                case '5' : flag = 0;
                break;
                default : cout << "-=-=-Invalid Choice-=-=-" << endl;
                break;
            }
}
}
