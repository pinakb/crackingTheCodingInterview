//implement myQueue Class using two stacks
// complexity: O(n)
#include<iostream>
#include<stack>
using namespace std;

class myQueue{

public:

    //Variables
    stack<int> s1, s2;
    void add(int item);
    void removeItem();
    int peek();


};

void myQueue::add(int item)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(item);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

}

void myQueue::removeItem()
{
    cout<<"removed item: "<<s1.top()<<endl;
    s1.pop();
}

int myQueue::peek()
{
    return s1.top();
}


int main()
{
    myQueue q;

    for(int i=1; i<=10; i++)
    {
        q.add(i);
        cout<<"Item added: "<<i<<endl;
    }

    for(int x=0; x< 5; x++)
    {
        q.removeItem();
    }
}
