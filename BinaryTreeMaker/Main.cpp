#include <iostream>
#include <stack>

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void insertData(Node* nodes, Node& node, Node* parent)
{
	if (nodes[0].data == node.data)
		return;

	if (node.data < parent->data)
	{
		if (parent->left == NULL)
		{
			parent->left = &node;
		}
		else
		{
			insertData(nodes, node, parent->left);
		}
	}
	else
	{
		if (parent->right == NULL)
		{
			parent->right = &node;
		}
		else
		{
			insertData(nodes, node, parent->right);
		}
	}
}

int main()
{
	int inputs[10] = { 5, 1, 3, 2, 4, 6, 8, 7, 10, 9 };
	int inputLength = 10;

	Node* nodes = new Node[inputLength];
	for (int i = 0; i < inputLength; ++i)
	{
		nodes[i].data = 0;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}

	for (int i = 0; i < 10; ++i)
	{
		nodes[i].data = inputs[i];
		insertData(nodes, nodes[i], &nodes[0]);
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
