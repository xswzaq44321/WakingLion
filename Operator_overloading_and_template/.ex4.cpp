#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template<typename T>
struct Node{
	Node(){
		data = {};
		next = nullptr;
	}
	Node(T bar){
		data = bar;
		next = nullptr;
	}

	T data;
	Node *next;
};

template<typename T>
class LinkedList{
	public:
		LinkedList(){
			head = nullptr;
			size = 0;
		}
		~LinkedList(){
			Node<T> *temp = head;
			Node<T> *prev = nullptr;
			for(; temp != nullptr; prev = temp, temp = temp->next){
				// delete each node from head to toe
				delete prev;
			}
			delete prev;
		}

		int size;
		Node<T> *head;

		void push_back(T bar){
			Node<T> *newNode = new Node<T>(bar);
			if(head == nullptr){
				// start a new list
				head = newNode;
			}else{
				Node<T> *temp;
				// find last node
				for(temp = head; temp->next != nullptr; temp = temp->next);
				temp->next = newNode;
			}
			++size;
		}
		void pop_back(){
			if(head == nullptr)
				return;
			Node<T> *prev, *temp;
			// find last node, assign previous node to prev
			for(temp = head, prev = nullptr; temp->next != nullptr; prev = temp, temp = temp->next);
			if(prev == nullptr){
				// prev == nullptr means that there is only one node in this linked list
				head = nullptr;
				delete temp;
			}else{
				prev->next = nullptr;
				delete temp;
			}
			--size;
		}
		T at(int index){
			if(index >= size){
				throw std::out_of_range("Out of Range error: Yo dude, there is only " + std::to_string(size) + " elements in this linked list.");
			}
			Node<T> *temp = head;
			for(int i = 0; i < index; ++i){
				temp = temp->next;
			}
			return temp->data;
		}
};

int main(){
	LinkedList<double> *ll = new LinkedList<double>();
	ll->push_back(1.1);
	ll->push_back(1.2);
	ll->push_back(5.2);
	ll->push_back(-100.2189);
	ll->push_back(3.141);
	ll->push_back(2.718);
	ll->push_back(1.618);

	for(int i = 0; i < ll->size; ++i){
		cout << ll->at(i) << " ";
	}
	cout << endl;
	ll->pop_back();
	ll->pop_back();
	for(int i = 0; i < ll->size; ++i){
		cout << ll->at(i) << " ";
	}
	cout << endl;
	delete ll;
}
