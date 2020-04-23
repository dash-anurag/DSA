/*
    This program is an example for a classic recurssion program.Towers of Hanoi.
    Date:22/04/2020
*/
#include<iostream>
using namespace std;
void Move(int n,char from,char to)
{
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
}
void TOH(int n,char left,char middle,char right)
{
    if(n==1)
        Move(1,left,right);
    else
    {
        TOH((n-1),left,right,middle);
        Move(n,left,right);
        TOH((n-1),middle,right,left);
    }
}

int main(void)
{
    int n=3; //No of disks
    TOH(n,'L','M','R');
    return 0;
}