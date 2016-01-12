#include <iostream>
#include <cassert>

class list_element {
	public:
		int value;
		list_element *next;
		list_element(): value(0), next(NULL) {};
		list_element(int n, list_element *next): value(n), next(next) {};
};

class list {
	private:
		list_element *head;
		list_element *tail;
		list_element *cursor;
	public:
		list(): head(NULL), tail(NULL), cursor(NULL) {};
		list(list_element *head, list_element *tail, list_element *cursor): head(head), tail(tail), cursor(cursor) {};
		list(const int *array, int n);
//		list(const list &list);
		~list();
		void prepend(int n);
		void append(int n);
		void add_at_cursor(int n);
		list_element* get_head() { return this->head; }
		list_element* get_tail() { return this->tail; }
		list_element* get_cursor() { return this->cursor; }
		void advance_cursor() { this->cursor = this->cursor->next; }
		bool is_empty() const;
		void print();
};

inline std::ostream& operator<<(std::ostream &out, list my_list) {
	list_element *temp = my_list.get_head();
	while ((temp != NULL) && (temp->next != NULL)) {
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
	if (temp != NULL)
		std::cout << temp->value << '\n';
	return out;
}

list::list(const int *array, int n) {
	std::cout << "constructor 1\n";
	assert((n!= 0) && (array != NULL));
	list_element *temp = new list_element(array[0], NULL);
	this->head = this->tail = this->cursor = temp;
	for (int i = 1; i < n; i ++) {
		temp = new list_element(array[i], NULL);
		this->tail->next = temp;
		this->tail = temp;
//		this->append(array[i]);
		std::cout << "constructor 1 in loop\n";
	}
}
/*
list::list(const list &list) {
	std::cout << "constructor 2\n";
	if (list.is_empty()) {
		std::cout << "constructor 2 again\n";
		this->head = NULL;
		this->tail = NULL;
		this->cursor = NULL;
	} else {
		list_element *temp = list.head;
		while (temp != NULL) {
			this->append(temp->value);
			temp = temp->next;
		}
	}
}
*/
list::~list() {
	std::cout << "in destructor\n";
	this->cursor = this->head;
	while (this->cursor != NULL) {
		this->cursor = this->cursor->next;
		delete this->head;
		this->head = this->cursor;
	}
}

bool list::is_empty() const {
	if (this->head == NULL) return true;
	else return false;
}

void list::print() {
	cursor = this->head;
//	assert(cursor != NULL);
	while (cursor != NULL) {
		std::cout << cursor->value << " ";
		cursor = cursor->next;
	}
	std::cout << '\n';
}

void list::prepend(int n) {
	list_element *temp = new list_element(n, this->head);
	if (this->is_empty()) {
		this->head = temp;
		this->tail = this->head;
		this->cursor = this->head;
	} else {
		this->head = temp;
	}
}

void list::append(int n) {
	list_element *temp = new list_element(n, NULL);
	if (this->is_empty()) {
		std::cout << "appending to empty list\n";
		this->head = temp;
		this->tail = this->head;
		this->cursor = this->head;
	} else {
		this->tail->next = temp;
		this->tail = temp;
	}
}

void list::add_at_cursor(int n) {
	if (this->is_empty()) {
		list_element *temp = new list_element(n, NULL);
		this->head = temp;
		this->tail = this->head;
		this->cursor = this->head;
	} else {
		list_element *temp = new list_element(n, this->cursor->next);
		this->cursor->next = temp;
	}
}

int main(void) {
	int a[4] = {1, 2, 3, 4};
	list my_list(a, 4);
//	my_list.append(3);
	std::cout << my_list;
//	std::cout << my_list.get_cursor()->value << '\n';
	my_list.prepend(5);
//	my_list.add_at_cursor(1);
//	my_list.prepend(6);
//	std::cout << my_list;
//	my_list.advance_cursor();
//	std::cout << my_list.get_cursor() << '\n';
//	my_list.append(4);
//	std::cout << my_list;
	return 0;
}
