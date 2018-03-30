#include <iostream>
#include <stack>

struct Node
{
	char data;
	Node* left;
	Node* right;
};

int main()
{
	int nodeNum;
	std::cin >> nodeNum;

	Node* nodes = new Node[nodeNum];
	for (int i = 0; i < nodeNum; ++i)
	{
		char data, temp1, temp2;

		std::cin >> data >> temp1 >> temp2;

		Node* left = (temp1 == '.') ? NULL : &nodes[temp1 - 'A'];
		Node* right = (temp2 == '.') ? NULL : &nodes[temp2 - 'A'];

		nodes[i] = { data,left,right };
	}

	std::stack<Node> stack;

	stack.push(nodes[0]);

	Node node;
	while (!stack.empty())
	{
		node = stack.top();
		stack.pop();
		std::cout << node.data << std::endl;
		if (node.right != NULL)
		{
			stack.push(*(node.right));
		}
		if (node.left != NULL)
		{
			stack.push(*(node.left));
		}
	}

	delete[] nodes;
	nodes = NULL;

	return 0;
}
