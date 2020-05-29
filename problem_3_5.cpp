//Sort the stacks in ascending order.
//complexity O(n)

#include<iostream>
#include<stack>
using namespace std;


 stack<int> sortStack(stack<int> input)
{
    int temp;
    stack<int> sortedStack;
    temp = input.top();

    while(input.empty()!= true)
    {
        if(sortedStack.empty()==true)
        {
            sortedStack.push(input.top());
            input.pop();
        }
        else
        {
            temp = input.top();
            input.pop();
            if(temp > sortedStack.top())
            {
                sortedStack.push(temp);
            }
            else
            {
                while(sortedStack.top()> temp)
                {
                    input.push(sortedStack.top());
                    sortedStack.pop();
                }
                sortedStack.push(temp);
            }
        }
    }

    stack<int> returnStack;

    while(sortedStack.empty()!=true)
    {
        returnStack.push(sortedStack.top());
        sortedStack.pop();
    }

    return returnStack;
}

int main()
{
   stack<int> input;
   input.push(31);
   input.push(37);
   input.push(22);
   input.push(99);
   input.push(29);
   input.push(12);

   input= sortStack(input);

   cout<<"sorted Stack: "<<endl;
   while(input.empty()!=true)
   {
       cout<<input.top()<<endl;
       input.pop();
   }
}
