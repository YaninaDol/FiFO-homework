#include <iostream>
template<typename T>
struct Node {
	T value;
	Node* next;

	Node()
	{

	}

	Node(Node* node) {
		next = NULL;
		value = node->value;
	}
};


template <typename T>
class FIFO {
private:
	Node<T>* head;
	unsigned long size;
public:
	explicit FIFO()
	{
		this->head = NULL;
		this->size = 0;
	}

	void add(T value) {
		if (this->head == NULL) {
			this->head = new Node<T>();
			this->head->value = value;
			this->head->next = NULL;
		}
		else
		{
			Node<T>* tmp = this->head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}

			tmp->next = new Node<T>();
			tmp->next->value = value;
			tmp->next->next = NULL;
		}

	}
	void show() {
		Node<T>* iter = this->head;
		while (iter != NULL)
		{
			std::cout << iter << " " << iter->next << " " << iter->value << "\n";
			iter = iter->next;
		}

	}

	Node<T>* remove() {
		Node<T>* iter = this->head;
		this->head = this->head->next;
		Node<T>* forReturn = new Node<T>(iter);
		delete iter;
		return forReturn;
	}
};
int main()
{
	FIFO<int> example;

	example.add(1);
	example.add(2);
	example.add(3);

	example.show();

	Node<int>* first = example.remove();
	std::cout << first << " " << first->value << "\n";

	Node<int>* second = example.remove();
	std::cout << second << " " << second->value << "\n";
	example.show();
}
