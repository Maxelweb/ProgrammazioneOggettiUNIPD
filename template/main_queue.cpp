#include "queue.h"
#include <ostream>

using namespace std;

int main(){

    Queue<int>* coda = new Queue<int>;

    for(int i=0; i < 10; i++)
        coda->add(i*3.14);

    /*for(int i=0; i < 10; i++)
        cout << coda->remove() << endl;
    */

    cout << *coda << endl;

    if(coda->is_empty()) cout << "Coda vuota"<< endl;
    else cout << "Coda PIENA"<< endl;

    cout << *coda << endl;
    cout << coda->first() << endl;
}
