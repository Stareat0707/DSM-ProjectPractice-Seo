#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::stack<char> stack;

	std::string input;
	std::cin >> input;

	for (int i = 0; i < input.size(); ++i)
	{
		char c = input.at(i);
		switch (c)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			if (stack.empty())
				stack.push(c);
			else
			{
				char top = stack.top();
				if ((top == '+' || top == '-') && (c == '*' || c == '/'))
					stack.push(c);
				else
				{
					while (!stack.empty())
					{
						std::cout << stack.top();
						stack.pop();
					}
					stack.push(c);
				}
			}
			break;
		default:
			std::cout << input.at(i);
		}
	}

	while (!stack.empty())
	{
		std::cout << stack.top();
		stack.pop();
	}

	std::cout << std::endl;
	return 0;
}
