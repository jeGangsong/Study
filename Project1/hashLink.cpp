#include <iostream>

using namespace std;

struct Node {
	int key;
	int value;
	Node* next;
};

Node* heashtable[10];
Node* last[10];

void addNode(int from, int n, int value) {
	if (heashtable[from] == nullptr) {
		heashtable[from] = new Node({ n,value,nullptr });
		last[from] = heashtable[from];
		return;
	}

	last[from]->next = new Node({ n,value,nullptr });
	last[from] = last[from]->next;

}

int hashFunc(int n) {
	return n % 3;
}

void insert(int key, int value) {
	int hashIndex = hashFunc(key);
	//중복이 있는 지 검사

	for (Node* p = heashtable[hashIndex]; p != nullptr; p = p->next) {
		if (p->key == key) p->value = value;
	}

	addNode(hashIndex, key, value);
}

int getNum(int key) {
	int hashIndex = hashFunc(key);
	//중복이 있는 지 검사

	for (Node* p = heashtable[hashIndex]; p != nullptr; p = p->next) {
		if (p->key == key) return p->value;
	}
	return 0;
}

int main() {

	//15371537 , 10 , 22 , 10 , 22

	insert(15371537,100);
	insert(22,200);
	insert(10,200);
	insert(10,300);
	insert(10,900);

	cout << getNum(22) << "\n";
	cout << getNum(21) << "\n";
	cout << getNum(15371537) << "\n";
	cout << getNum(10);


	

}