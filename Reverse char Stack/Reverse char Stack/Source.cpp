#include <iostream>
using namespace std;
class Stack
{
public:
	int top;
	unsigned capacity;
	char* arr;

	
	Stack* CreateStack(unsigned capacity)
	{
		Stack* stack = new Stack();
		stack->capacity = capacity;
		stack->top = -1;
		stack->arr = new char[(stack->capacity * sizeof(char))];
		return stack;
	}
	int isFull(Stack* stack)
	{
		return (stack->top == stack->capacity - 1);
	}
	int isEmpty(Stack* stack)
	{
		return (stack->top == -1);
	}
	void push(Stack* stack, char item)
	{
		if (isFull(stack))
			return;
		
			stack->arr[++stack->top] = item;
	}
	char pop(Stack* stack)
	{
		if (isEmpty(stack))
			return -1;
		else
			return stack->arr[stack->top--];
	}
	void reverse(char str[])
	{
		int n = strlen(str);
		Stack* stack = CreateStack(n);
		for (int i = 0; i < n; i++)
			push(stack, str[i]);
		for (int i = 0; i < n; i++)
			str[i]=pop(stack);
		
		
	}
	void display()
	{
		char str[] = "tobias boon";
		reverse(str);
		cout << "Reversed string is " << str << endl;
	}
};
int main()
{
	Stack s;
	s.display();
	return 0;
}