#include "std_lib_facilities.h"

#define BAD_INPUT 1000   //defining bad input when user tries to input more than one digit number


using namespace std;

vector<string> spelled{"zero","one", "two", "three", "four", "five", 
                             "six", "seven", "eight", "nine"};

vector<string> digit{"0","1", "2", "3", "4", "5", "6", "7", "8", "9"};

//this function reads through two vectors and retunrs the users input in int

int get_Number(string numb)
{
    for(int i=0;i<10;i++)
    {
        if(numb==spelled[i]|| numb==digit[i])
        {
            return i;
        }
    }

    return BAD_INPUT;
}

//this function performs the math by the two user input and the operation and returns the answer

int do_math(int x, int y, string op)
{
    int z;
    if(op=="+")
    {
        z=x+y;

    }else if(op=="-")
    {
        z=x-y;

    }else if(op=="*")
    {
        z=x*y;

    }else if(op=="/")
    {
        z=x/y;

    }

    return z;
}


//this function returns the full form of the operation based on the user's input

string return_operation(string op)
{
    string operation;
    if(op=="+")
    {
        operation="sum of";
    }else if(op=="-")
    {
        operation="differeence between";
    }else if(op=="*")
    {
        operation="product of";
    }else if(op=="/")
    {
        operation= "division of";
    }

    return operation;
}


//this fuction prints the answer if user's input is valid otherwise prints error message

void get_result(string numb1, string numb2, string op)
{
    int x=get_Number(numb1);
    int y=get_Number(numb2);

    string operation = return_operation(op);

    if(x!=BAD_INPUT && y!=BAD_INPUT)  //if user's input is not one digit number
    {
        int z=do_math(x,y,op);
        cout<<"The "<<operation<<" "<<x<<" and "<<y<<" is "<<z<<".";

    }else{

        cout<<"Please put one digit numbers or just the operations(+,-,*,/)";
    }


}



int main()
{

    string x;
    string y;
    string op;

    cout<<"Please enter two digits (number or spelled out in lower case) and operation (+,-,*,/): \n";
    cin>>x>>y>>op;

    get_result(x,y,op);

    return 0;
}