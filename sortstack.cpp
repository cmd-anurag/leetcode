#include <bits/stdc++.h>
#include<stack>

using namespace std;

void insert(stack<int> &stack, int temp) {
	if(stack.empty() || stack.top() < temp) {
		stack.push(temp);
		return;
	}
	int n = stack.top();
	stack.pop();
	insert(stack, temp);
	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) {
		return;
	}
	
	int temp = stack.top();
	stack.pop();

	sortStack(stack);

	insert(stack, temp);
}

int main() {

}