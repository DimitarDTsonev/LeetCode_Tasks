// Task : https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26

class Node {
public:
	int val;
	std::vector<Node*> children;

	Node() : val(0), children{} {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, std::vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

std::vector<int> vec{};

void postOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	for (Node* iter : root->children)
	{
		postOrder(iter);
	}

	vec.push_back(root->val);
}

std::vector<int> postorder(Node* root) {
	postOrder(root);

	return vec;
}

void printVec(const std::vector<int>& vec)
{
	for (int iter : vec)
	{
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Example 1:
	std::vector<Node*> vec = { new Node(3), new Node(2), new Node(4)};
	std::vector<Node*> vec1 = { new Node(5), new Node(6)};
	
	Node* root = new Node(1, vec);
	root->children[0]->children = vec1;

	std::vector<int> res = postorder(root);
	printVec(res);

	return 0;
}
