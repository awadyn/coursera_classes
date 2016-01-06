#include <iostream>
#include <cstdlib>
#include <cassert>

const int str_size = 32;

struct node {
	char *str;
	node *next;
};

class slist {
	private:
		node *head, *tail;
	public:
		slist():head(NULL), tail(NULL) {};
		slist(node *head):head(head) {};
		slist(node *head, node *tail):head(head), tail(tail) {};
		~slist();
		node* get_head() { return this->head; }
		node* get_tail() { return this->tail; }
		void prepend(char *str);
		void append(char *str);
};

slist::~slist() {
	std::cout << "Calling destructor..\n";
	node *temp = this->head;
	while (temp != NULL) {
		temp = temp->next;
		delete head;
		head = temp;
	}
}

void slist::prepend(char *str) {
	node *new_node = new node;
	assert(new_node != 0);
	new_node->str = new char[str_size];
	new_node->str = str;
	new_node->next = this->head;
	this->head = new_node; 
}

void slist::append(char *str) {
	node *new_node = new node;
	assert(new_node != 0);
	new_node->str = new char[str_size];
	new_node->str = str;
	new_node->next = NULL;
	this->tail->next = new_node;
	this->tail = new_node;
}

slist* create_list (node *head) {
	int size;
	std::cout << "Input list size: ";
	std::cin >> size;
	char **strings = new char * [size];
	std::cout << "Input list values in the form: str_1 str_2 str_3 ..." << '\n';
	for (int i = 0; i < size; i ++) {
		strings[i] = new char[str_size];
		std::cin >> strings[i];
	}
	node *temp = head;
	for (int i = 0; i < size - 1; i ++) {
		temp->str = new char[str_size];
		temp->str = strings[i];
		temp->next = new node;
		temp = temp->next;
	}
	temp->str = new char[str_size];
	temp->str = strings[size - 1];
	temp->next = NULL;
	slist *list = new slist(head, temp);
	return list;
}

void print_list (slist *list) {
	node *temp = list->get_head();
	while (temp->next != NULL) {
		std::cout << temp->str << ", ";
		temp = temp->next;
	}
	std::cout << temp->str << '\n';
}


int main(void) {
	node *head = new node;
	slist *list = create_list(head);
	print_list(list);
	list->prepend("hello! ");
	print_list(list);
	list->append(" :)");
	print_list(list);
//	~slist();
	
	return 0;
}
