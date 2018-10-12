template <class T>
class dList
{
	private:
		class nodo
		{
			public:
				T info;
				nodo *prev, *next;
				nodo(const T& t, nodo* p=0, nodo* n=0): info(t), prev(p), next(n) { }
				~nodo(){ if(next) delete next; }
			
		};

		nodo *first, *last;
		static nodo* copy(nodo* f, nodo*& lst)
		{
			if(!f) { lst=0; return 0; }
			// f != 0

			nodo *t, *p;
			p = new nodo(f->info, 0, 0);
			t=p; 

			// p punta al primi nodo della nuova lista
			// t punta all'ultimo nodo corrente della nuova lista
			while(f->next != 0)
			{
				t->next = new nodo(f->next->info, t, 0);
				t = t->next;
				f = f->next;
			}
			// f->next == 0
			// t punta all'ultimo nodo della nuova lista
			lst = t; 
			return p; 
		}

		/* 
		static void destroy(nodo * f)
		{
			if(f)
			{
				destroy(f->next);
				delete f; 
			}
		}
		*/

		static bool compareLex(nodo * f1, nodo* f2)
		{
			if(!f1 && f2) return true;
			if(f1 && !f2 ||	!f1 && !f2) return false;
			// f1!=0 && f!=0

			if(f1->info < f2->info) return true;
			if(f1->info > f2->info) return false;
			// f1!=0 && f2!=0 && f1->info == f2->info
			return compareLex(f1->next, f2->next);
		}

	public: 
		
		class const_iterator 
		{
			friend class dList; 
			
			private: 
				const nodo* ptr;
				const_iterator(nodo* n=0): ptr(n) {}

			public: 
				const_iterator& operator++()
				{ 
					if(ptr) ptr = ptr->next; 
					return *this; 
				}
				bool operator==(const const_iterator& cit) const { return ptr == cit.ptr; }
				bool operator!=(const const_iterator& cit) const { return ptr != cit.ptr; }
				const T& operator*() const { return ptr->info; }
				const T* operator->() const { return &(ptr->info); } 
				
		}

		const_iterator begin() const { return const_iterator(first); } 
		const_iterator end() const { return const_iterator(); }

		dList(const dList& l): first(copy(l.first, last)) {} 
		dList& operator=(const dList& l)
		{
			if(this != &l) 
			{
				if(first) delete first;
				first = copy(l.first, last);
			}
			return *this;
		} 
		~dList() { if(first) delete first; }
		
		void insertFront(const T& t)
		{
			if(!first) last=first= new nodo(t, 0, 0); 
			else
			{
				first = new nodo(t, 0, first);
				first->next->prev = first;  
			}
		}

		void insertBack(const T& t)
		{
			if(!last) last=first= new nodo(t, 0, 0); 
			else
			{
				last = new nodo(t, last, 0);
				last->prev->next = last;  
			}
		}

		dList(int k, const T& t): first(0), last(0)
		{
			for(int i=0; i<k; ++i) insertFront(t); 
			// for(int i=0; i<k; ++i) insertBack(t); 
		} 

		bool operator< (const dList& l) const
		{
			return compareLex(first, l.first); 
		}

	
};