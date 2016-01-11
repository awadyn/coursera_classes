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
		void prepend(int n);
		void append(int n);
		void add_at_cursor(int n);
		list_element* get_head() { return this->head; }
		list_element* get_tail() { return this->tail; }
		list_element* get_cursor() { return this->cursor; }
		void advance_cursor() { this->cursor = this->cursor->next; }
		bool is_empty();
		void print();
};

inline std::ostream& operator<<(std::ostream &out, list my_list) {
	list_element *temp = my_list.get_head();
//	assert (temp != NULL);
	while ((temp != NULL) && (temp->next != NULL)) {
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
	if (temp != NULL)
		std::cout << temp->value << '\n';
	return out;
}

bool list::is_empty() {
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
	list my_list;
	std::cout << my_list;
	my_list.print();
//	my_list.add_at_cursor(2);
	my_list.append(3);
	std::cout << my_list.get_cursor()->value << '\n';
//	my_list.print();
	my_list.prepend(5);
//	my_list.print();
//	my_list.add_at_cursor(1);
	my_list.prepend(6);
	std::cout << my_list;
	my_list.advance_cursor();
	std::cout << my_list.get_cursor() << '\n';
//	my_list.print();
	my_list.append(4);
//	my_list.print();
	std::cout << my_list;
	return 0;
}
