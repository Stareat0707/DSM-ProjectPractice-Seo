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

	std::stack<Node*> stack;

	Node* node = nodes;
	while (true)
	{
		while (node)
		{
			stack.push(node);
			node = node->left;
		}
		if (!stack.empty())
		{
			node = stack.top();
			stack.pop();
			std::cout << node->data << std::endl;

			node = node->right;
		}
		else
			break;
	}

	delete[] nodes;
	nodes = NULL;

	return 0;
}
