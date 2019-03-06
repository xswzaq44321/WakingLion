#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

typedef struct Node{
	Node(){
		data = 0;
		next = nullptr;
	}
	Node(int bar){
		data = bar;
		next = nullptr;
	}

	int data;
	Node *next;
}Node;

class LinkedList{
	public:
		LinkedList(){
			head = nullptr;
			size = 0;
		}
		~LinkedList(){
			Node *temp = head;
			Node *prev = nullptr;
			for(; temp != nullptr; prev = temp, temp = temp->next){
				// delete each node from head to toe
				delete prev;
			}
			delete prev;
		}

		int size;
		Node *head;

		void push_back(int bar){
			Node *newNode = new Node(bar);
			if(head == nullptr){
				// start a new list
				head = newNode;
			}else{
				Node *temp;
				// find last node
				for(temp = head; temp->next != nullptr; temp = temp->next);
				temp->next = newNode;
			}
			++size;
		}
		void pop_back(){
			if(head == nullptr)
				return;
			Node *prev, *temp;
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
		int at(int index){
			if(index >= size){
				throw std::out_of_range("Out of Range error: Yo dude, there is only " + std::to_string(size) + " elements in this linked list.");
			}
			Node *temp = head;
			for(int i = 0; i < index; ++i){
				temp = temp->next;
			}
			return temp->data;
		}
};

int main(){
	LinkedList *ll = new LinkedList();
	ll->push_back(10);
	ll->push_back(20);
	ll->push_back(30);
	ll->push_back(5);
	ll->push_back(0);
	ll->push_back(8000);
	ll->push_back(92000);
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
