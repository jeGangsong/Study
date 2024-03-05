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
				cout << "같은 숫자가 존재합니다." << "\n";
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
		
		//root를 지우는 경우 따로 처리
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

		// target을 찾았다면
		if (flag) {
			// 자식이 두명인 경우
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
			// 자식이 한명인 경우
			else if (node->left != nullptr) {
				node = node->left;
				while (node->right != nullptr) {
					node = node->right;
				}

				//targetNode와 target보다 바로 작은 data와 바꾼다.
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
			// 자식이 한명인데 오른쪽 자식만 있는 경우
			else if (node->right != nullptr) {
				
				node = node->right;
				while (node->left != nullptr) {
					node = node->left;
				}

				//targetNode와 target보다 바로 큰 data와 바꾼다
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
			//자식이 없는 경우
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
			cout << "해당하는 변수가 존재하지 않습니다." << "\n";
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

		cout << "해당하는 데이터를 가진 노드가 없습니다.\n";
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