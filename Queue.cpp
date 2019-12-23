#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int size;
	
	cout << "size of Queue : ";
	
	while(cin >> size == false || size == 0)
	{
		cout << "size of Queue is must be int (size > 0)" << endl;
		
		cin.clear();
		cin.ignore(100, '\n');
		
		cout << "size of Queue : ";
	}
	
	int queue[size] = {NULL};
	
	int front = size - 1; 
	int back = size - 1;
	
	int n;
	string order = "none";
	
	while(true)
	{
		cout << "Enqueue : input \"push\"" << endl << "Dequeue : input \"pop\"" << endl;
		
		cin >> order;
		
		if(order == "push")
		{
			cout << "push (only int) : ";
			while(cin >> n == false)
			{
				cout << "push value is must be int" << endl;
				
				cin.clear();
				cin.ignore(100, '\n');
				cout << "push (only int) : ";
			}
			if(queue[back] != NULL)
			{
				front--;
				if(front < 0)
				{
					front = size - 1;
				}
			}
			queue[back] = n;
			back--;
			if(back < 0)
			{
				back = size - 1;
			}
			
			int temp = front;
			
			for(int i = 0 ; i < size ; i++)
			{
				if(temp < 0)
				{
					temp += size;
					cout << queue[temp] << " ";
				}
				else
				{
					cout << queue[temp] << " ";
				}
				
				temp--;
			}
			cout << endl;
		}
		else if(order == "pop" && queue[front] != NULL)
		{
			cout << "pop : " << queue[front] << endl;
			
			queue[front] = NULL;
			front--;
			if(front < 0)
			{
				front = size - 1;
			}
		}
		else if(queue[front] == NULL)
		{
			cout << "Queue is empty" << endl;
		}
		
		cin.clear();
		cin.ignore(100, '\n');
	} 
}
