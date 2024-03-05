#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* left;
	Node* right;
	Node* parent;

	Node(T d=NULL) {
		data = d;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

template <typename T>
class BST {

private:
	Node<T>* root;
	int treeSize;
public:
	BST(Node<T>* rootNode) {
		root = rootNode;
		treeSize = 1;
	}

	void setData(Node<T>* node, T data) {

		if (node == nullptr) return;
		
		node->data = data;
	}

	T& getData(Node<T>* node) {

		return node->data;
	}

	void insert(T value) {
		Node<T>* node = new Node<T>(value);
		Node<T>* tmp = root;

		if (root == nullptr) {
			root = node;
			return;
		}

		if (node == nullptr) return;
		Node<T>* tmpRoot = nullptr;

		while (tmp != nullptr) {

			tmpRoot = tmp;
			if (tmp->data > node->data) {
				tmp = tmp->left;
			}
			else if (tmp->data < node->data) {
				tmp = tmp->right;
			}
			else {
				cout << "���� ���ڰ� �����մϴ�." << "\n";
				return;
			}
		}

		if (tmpRoot->data > node->data) {
			tmpRoot->left = node;
			node->parent = tmpRoot;
			treeSize++;
		}
		else {
			tmpRoot->right = node;
			node->parent = tmpRoot;
			treeSize++;
		}
	}

	void remove(T target) {

		Node<T>* node = root;

		Node<T>* nodeParent = root;
		
		//root�� ����� ��� ���� ó��
		if (root->data == target) {
			node = node->left;
			while (node->right != nullptr) {
				node = node->right;
			}
			nodeParent->data = node->data;
			
			if (node->parent->left != nullptr && node->parent->left->data == node->data) {
				node->parent->left = nullptr;
			}
			else {
				node->parent->right = nullptr;
			}
			treeSize--;
			delete node;
			return;
		}

		//Searching
		bool flag = false;
		while (node != nullptr) {
			nodeParent = node;
			if (node->data > target) {
				node = node->left;
			}
			else if (node->data < target) {
				node = node->right;
			}
			else {
				nodeParent = node->parent;
				flag = true;
				break;
			}
		}

		// target�� ã�Ҵٸ�
		if (flag) {
			// �ڽ��� �θ��� ���
			Node<T>* targetNode = node;
			if (node->left != nullptr && node->right != nullptr) {
				node = node->left;
				while (node->right != nullptr) {
					node = node->right;
				}
				targetNode->data = node->data;
				node->parent->right = nullptr;

				treeSize--;
				delete node;
				return;
			}
			// �ڽ��� �Ѹ��� ���
			else if (node->left != nullptr) {
				node = node->left;
				while (node->right != nullptr) {
					node = node->right;
				}

				//targetNode�� target���� �ٷ� ���� data�� �ٲ۴�.
				targetNode->data = node->data;
				if (node->parent->left != nullptr && node->parent->left->data == node->data) {
					node->parent->left = nullptr;
				}
				else {
					node->parent->right = nullptr;
				}	
				treeSize--;
				delete node;
			}
			// �ڽ��� �Ѹ��ε� ������ �ڽĸ� �ִ� ���
			else if (node->right != nullptr) {
				
				node = node->right;
				while (node->left != nullptr) {
					node = node->left;
				}

				//targetNode�� target���� �ٷ� ū data�� �ٲ۴�
				targetNode->data = node->data;
				if (node->parent->left != nullptr && node->parent->left->data == node->data) {
					node->parent->left = nullptr;
				}
				else {
					node->parent->right = nullptr;
				}
				treeSize--;
				delete node;
			}
			//�ڽ��� ���� ���
			else {
				if (nodeParent->left != nullptr && nodeParent->left->data == target) {
					nodeParent->left = nullptr;
				}
				else {
					nodeParent->right = nullptr;
				}
				treeSize--;
				delete node;
				
			}
		}
		else {
			cout << "�ش��ϴ� ������ �������� �ʽ��ϴ�." << "\n";
			return;
		}
	}

	Node<T>* SearchNode(T target) {
		
		Node<T>* tmp = root;

		while (tmp != nullptr) {
			if (tmp->data > target) {
				tmp = tmp->left;
			}
			else if (tmp->data < target) {
				tmp = tmp->right;
			}
			else {
				return tmp;
			}
		}

		cout << "�ش��ϴ� �����͸� ���� ��尡 �����ϴ�.\n";
		return nullptr;
	}

	void inorder(Node<T>* node) {

		if (node == nullptr) return;

		inorder(node->left);
		cout << node->data << " " << "\n";
		inorder(node->right);
		
	}

	int size() {
		return this->treeSize;
	}
};

int main() {

	Node<int>* root = new Node<int>(6);

	BST<int> bst(root);

	bst.insert(7);
	bst.insert(10);
	bst.insert(8);
	bst.insert(3);
	bst.insert(2);

	bst.inorder(root);

	bst.remove(3);
	bst.remove(6);


	Node<int>* ptr = bst.SearchNode(6);

	bst.inorder(root);
	cout << "BST Node Num : " << bst.size() << "\n";


	
	
}