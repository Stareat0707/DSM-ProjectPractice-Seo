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
	Node* checkNode = NULL;
	while (true)
	{
		if (node && node != checkNode)
		{
			stack.push(node);
			do
			{
				if (node->right)
					stack.push(node->right);
				if (node->left)
					stack.push(node->left);
				node = node->left;
			} while (node);
		}
		if (!stack.empty())
		{
			node = stack.top();
			stack.pop();
			if (node->left && node->right == NULL && node->left != checkNode)
			{
				if (node)
					stack.push(node);
				node = node->left;
			}
			if (node->right == NULL || node->right == checkNode)
			{
				std::cout << node->data << std::endl;
				checkNode = node;
			}
		}
		else
			break;
	}

	delete[] nodes;
	nodes = NULL;

	return 0;
}
