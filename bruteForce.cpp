#include <iostream>
#include <string.h>
#include <conio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    char password[30];
    cout<<"Enter your integer password : ";
    char ch;
    int i = 0; 
    int tries = 0;
    while (true)
    {
        ch = getch();
        if(ch==13)
        {
            password[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            password[i] = ch;
            i++;
            cout<<"*";
        }
    }
    char predicted_pass[30];
    while (strcmp(predicted_pass,password)!=0)
    {
        
        int length = strlen(password);
        for(i = 0; i < length; i++)
        {
            tries++;
            predicted_pass[i] = (char)((rand()%10)+48);
        }
        predicted_pass[i]='\0';
        cout<<predicted_pass<<endl;
        if(strcmp(predicted_pass,password)==0)
        {
            break;
        } 
    }
    cout<<"tries: "<<tries<<endl;
    cout<<"Your password is : "<<predicted_pass<<endl;
    
}
