#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
		Node(){
			next = nullptr;
		}
		Node(T data){
			this->data = data;
			next = nullptr;
		}

		T data;
		Node* next;
};

template<typename T>
class LinkedList{
	public:
		LinkedList(){
			size = 0;
			head = nullptr;
		}

		int size;
		Node<T> *head;

		void push_back(T data);
		void push_front(T data);
		void pop_back();
		void pop_front();
		T operator[](const int index);
};

template<typename T>
void LinkedList<T>::push_back(T data){
	Node<T> *newNode = new Node<T>(data);
	if(head == nullptr){
		head = newNode;
	}else{
		Node<T> *temp;
		for(temp = head; temp->next != nullptr; temp = temp->next);
		temp->next = newNode;
	}
	++size;
}
template<typename T>
void LinkedList<T>::pop_back(){
	if(head == nullptr)
		return;
	Node<T> *prev = nullptr, *temp = head;
	for(; temp->next != nullptr; prev=temp, temp=temp->next);
	if(prev == nullptr){
		head = nullptr;
	}else{
		prev->next = nullptr;
	}
	delete temp;
	--size;
}
template<typename T>
T LinkedList<T>::operator[](const int index){
	Node<T>* temp = head;
	for(int i = 0; i < index; ++i, temp = temp->next);
	return temp->data;
}
template<typename T>
void LinkedList<T>::push_front(T data){
	Node<T>* newNode = new Node<T>(data);
	newNode->next = head;
	head = newNode;
	++size;
}
template<typename T>
void LinkedList<T>::pop_front(){
	if(head == nullptr)
		return;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	--size;
}

int main(){
	LinkedList<int> ll;
	ll.push_back(3);
	ll.push_back(1);
	ll.push_back(4);
	for(int i = 0; i < ll.size; ++i){
		cout << ll[i] << " ";
	}
	cout << endl;
	ll.pop_back();
	ll.pop_front();
	ll.push_front(2);
	ll.push_front(5);
	for(int i = 0; i < ll.size; ++i){
		cout << ll[i] << " ";
	}
	cout << endl;
	/*******************************
	 * this program should output:
	 * 3 1 4
	 * 5 2 1
 	 *******************************/
}
