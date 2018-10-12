
// trialbero.h

#ifndef TRIALBERO_H
#define TRIALBERO_H

#include <iostream>

template<class T>
class trialbero;


template <class T> // dichiarazione incompleta del template di funzione
std::ostream& operator<<(std::ostream&, const trialbero<T>&);

// Quando faccio una dich. di amicizia rispetto a un template di classe, quel nome deve essere noto.
// Dunque l'ho messo all'inizio.

template <class T>
class trialbero{

	// dichiarazione di amicizia
	friend std::ostream& operator<< <T> (std::ostream&, const trialbero&); 
	// posso omettere trialbero<T>& essendo dentro

	private: 

		class nodo {

			public: 
				T info;
				nodo *sx, *cx, *dx;
				nodo(const T& t, nodo* s=0, nodo* c=0, nodo* d=0) : info(t), sx(s), cx(c), dx(d) { }
		};

		nodo* root;

		static nodo* copy(nodo*); 
		static void destroy(nodo*);
		static bool search(nodo*, const T&);
		static bool equals(nodo*, nodo*);
		static void print(nodo*, std::ostream&); 

	public: 

		trialbero();
		trialbero(const trialbero&);
		trialbero& operator=(const trialbero &); 
		~trialbero();
		void insert(const T&); 
		bool search(const T&) const; 
		bool operator==(const trialbero&) const;

};


// Definizione del template di metodi

template <class T>
trialbero<T>::trialbero(): root(0) {}


template <class T>
typename void trialbero<T>::destroy(typename trialbero<T>::nodo* r)
{
	// Distruzione in POST-ORDINE

	if(r)
	{
		destroy(r->sx);
		destroy(r->cx);
		destroy(r->dx);
		delete(r);
	}
}


template <class T>
trialbero<T>::trialbero(const trialbero<T>& t) : root(copy(t.root)) {}


template <class T>
trialbero<T>& trialbero<T>::operator=(const trialbero<T>& t)
{
	if(this != &t)
	{
		destroy(root);
		root = copy(t.root);
		// Codice identico all'albero binario
	}
}


template <class T>
trialbero<T>::~trialbero<T> () { destroy(root); }


template<class T>
void trialbero<T>::insert(const T& t)
{
	// root = new nodo(t, copy(root), copy(root), copy(root)); 
	// Crea Garbage!
	// Quindi usiamo:
	root = new nodo(t, copy(root), copy(root), root);
}


template <class T>
bool trialbero<T>search(typename trialbero<T>::nodo* r, const T& t) {
	if(!r) return false;
	// r!=0
	// T renda disponibili operator==
	if(r->info == t) return true;
	return search(r->sx, t) || search(r->cx, t) || search(r->dx, t);
}


template <class T>
bool trialbero<T>::search(const T& t) const
{
	return search(t.root, t); 
}


template <class T>
bool trialbero<T>::equals(typename trialbero<T>::nodo* r1, typename trialbero<T>::nodo* r2) const 
{
	// Se alberi entrambi vuoti => uguali
	// Se alberi uno vuoto e l'altro no => diversi

	if(!r1 && !r2) return true; 
	// r1 || r2

	if(!r1 || !r2) return false;
	// r1 != 0 & r2 != 0

	return r1->info == r2->info && equals(r1->sx, r2->sx) 
			&& equals(r1->cx, r2->cx) && equals(r1->dx, r2->dx);
}


template <class T>
bool trialbero<T>::operator==(const trialbero& t) const 
{
	return equals(root, t.root);
}


template <class T>
std::ostream& operator<<(std::ostream& os, const trialbero<T>& t)
{
	print(t.root, os);
	return os;
}


template <class T>
void trialbero<T>::print(typename trialbero<T>::nodo* r, std::ostream& os)
{
	if(r){

		print(r->sx, os);
		os << r->info << " ";
		print(r->cx, os);
		print(r->dx, os);
	}
}


template <class T> // trialbero<T>::nodo* è un tipo implicito, uso typename
typename trialbero<T>::nodo* trialbero<T>::copy(typename trialbero<T>::nodo* r)
{
	if(!r) return 0;
	// r != 0
	return new nodo(r->info, copy(r->sx), copy(r->cx), copy(r->dx));
}