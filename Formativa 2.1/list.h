//Salvador Santana Blanco

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <sstream>

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&);

	std::string toString() const;
	void insertion(T);
	int search(T);
	void update(int, T);
	T deleteAt(int);
	void addFirst(T);
	bool empty() const;

private:
	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::List(const List<T> &source) {
	Link<T> *p, *q;

	if(source.empty()){
		size = 0;
		head = 0;
	} else{
		p = source.head;
		head = new Link<T> (p->value);

		q = head;
		p = p->next;
		while(p != 0){
			q->next = new Link<T> (p->value);
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
bool List<T>::empty() const {
	return (head==0);
}

template <class T>
void List<T>::addFirst(T val) {
	Link<T> *newLink;
	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::insertion(T val) {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if(empty()){
		addFirst(val);
		return;
	}
	p = head;
	while(p->next != 0){
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
int List<T>::search(T val){
	int index = 0;
	Link<T> *p;

	p = head;
	while(p != 0){
		if(p->value == val){
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

template <class T>
void List<T>::update(int index, T val){
	int pos = 0;
	Link<T> *p;
	p = head;
	while (pos != index) {
		p = p->next;
		pos++;
	}
	p->value = val;
}

template <class T>
T List<T>::deleteAt(int index){
	int pos;
	T val;
	Link<T> *p, *q;
	if (index == 0) {
		p = head;
        head = p->next;
		val = p->value;
        delete p;
		size--;
		return val;	
	} 

	p = head;
    q = p->next;
	pos = 1;
	while (pos != index) {
        p = q;
        q = p->next;
        pos++;
	}
	val = q->value;
    p->next = q->next;
	size--;
	delete q;
	return val;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}


#endif