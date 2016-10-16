>>>>>>>Version 2 for friends who know about functions.
#include<iostream.h>
#include<conio.h>
void swapmethod1(int &a, int &b)
{
     int temp;
     temp=a;
     a=b;
     b=temp;
}
void swapmethod2(int &a, int &b)
{
     a=a+b;
     b=a-b;
     a=a-b;
}
void swapmethod3(int &a, int &b)
{
     a=a*b;
     b=a/b;
     a=a/b;
}
void swapmethod4(int &a, int &b)
{
     a=a^b;
     b=a^b;
     a=a^b;
}
int main()
{
     int x,y;
     cout<<"Enter two numbers :";
     cin>>x>>y;

     cout<<"\n\nBefore swapping x="<<x<<" y="<<y;
     swapmethod1(x,y);
     cout<<"\nAfter swapping  x="<<x<<" y="<<y;

     cout<<"\n\nBefore swapping x="<<x<<" y="<<y;
     swapmethod2(x,y);
     cout<<"\nAfter swapping  x="<<x<<" y="<<y;

     cout<<"\n\nBefore swapping x="<<x<<" y="<<y;
     swapmethod3(x,y);
     cout<<"\nAfter swapping  x="<<x<<" y="<<y;

     cout<<"\n\nBefore swapping x="<<x<<" y="<<y;
     swapmethod4(x,y);
     cout<<"\nAfter swapping  x="<<x<<" y="<<y;

     getch();
     return 0;
}

/*
HOW TO SWAP

METHOD 1. USING THREE VARIABLES


This is the simplest method to swap values. This method uses three variables, of which two are those variable whose values are going to be swapped and third one is a temporary variable which helps us in doing this.
let us see how to implement it in C/C++

int A=5;
int B=10;
int temp;
///////Now see how to swap////////
temp=A;
A=B;
A=temp;
//////////done swapping///////////
HOW TO SWAP

METHOD 1. USING THREE VARIABLES


This is the simplest method to swap values. This method uses three variables, of which two are those variable whose values are going to be swapped and third one is a temporary variable which helps us in doing this.
let us see how to implement it in C/C++

int A=5;
int B=10;
int temp;
///////Now see how to swap////////
temp=A;
A=B;
A=temp;
//////////done swapping///////////
*/
