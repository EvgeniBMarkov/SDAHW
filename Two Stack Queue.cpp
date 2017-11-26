#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class TwoStackQueue
{
	stack<T> MainStack;
	stack<T> AuxStack;
public:	
    
    TwoStackQueue() {};
    ~TwoStackQueue() {};
    
	void enqueue(T input)
    {
		AuxStack.push(input);
	}

	void dequeue()
	{
        while(!AuxStack.empty())
        {
            MainStack.push(AuxStack.top());
            AuxStack.pop();
        }
        
        if(!MainStack.empty())MainStack.pop();
        
        while(!MainStack.empty())
        {
            AuxStack.push(MainStack.top());
            MainStack.pop();
        }
    }
    
    void printTop()
    {
        while(!AuxStack.empty())
        {
            MainStack.push(AuxStack.top());
            AuxStack.pop();
        }
        
        if(!MainStack.empty()) cout<<MainStack.top()<<endl;
        else 
        {
            cout<<"Empty"<<endl;
        }
        
        while(!MainStack.empty())
        {
            AuxStack.push(MainStack.top());
            MainStack.pop();
        }
    }
};

int main() {
    TwoStackQueue<int> TSQueue;
    
    int numberOfCommands;
    cin>>numberOfCommands;
    
    int command;
    int var=0;
    
    for(int i=0; i<numberOfCommands; i++)
    {
        cin>>command;
        switch(command)
        {
            case 1 :
                cin>>var;
                TSQueue.enqueue(var);
                break;
            case 2 : TSQueue.dequeue(); break;
            case 3 : TSQueue.printTop(); break;
        }
    }
    return 0;
}
