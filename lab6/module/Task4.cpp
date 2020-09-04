#include <iostream>

using namespace std;

#define EMPTY nullptr

template<typename T>
class Node {
public:
	Node *ptrNextNode;
	T data;
	Node(T data = T(), Node* ptrNextNode = EMPTY) {
		this->data = data;
		this->ptrNextNode = ptrNextNode;
	}
};

template<typename T>
class List {
public:
	int getsize() {
		return size;
	}
	void push_back(T data){
		if (ptrHeadNode == nullptr) {
			ptrHeadNode = new Node<T>(data);
		} else {
			Node<T>* ptrCurrentNode = this->ptrHeadNode;

			while (ptrCurrentNode->ptrNextNode != nullptr) {
				ptrCurrentNode = ptrCurrentNode->ptrNextNode;
			}
			ptrCurrentNode->ptrNextNode = new Node<T>(data);
		}
		size++;
	};
	void push_front(T data){
		Node<T>* ptrPreviosNode = new Node<T>(data,ptrHeadNode);
		ptrHeadNode = ptrPreviosNode;
		size++;

	};
	void pop_back(){};
	void pop_front(){};
	void insert(int position,T data);
	void unique();
	void merge(List<T> spisok);
	T front();
	T back();

private:
	Node<T> *ptrHeadNode;
	int size;
};


void Task4() {
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_front(3);
}

