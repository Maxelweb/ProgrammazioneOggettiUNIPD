# Programmazione a Oggetti (P2)

## Informazioni

Esercizi di Programmazione a oggetti - 2018/2019 (UniPD)



## Compilazione in QT

- Nel file .pro aggiungere in sources e in headers i relativi .cpp e .h per eseguire una corretta compilazione.


## Note importanti

- __const__: Si utilizza per evitare modifiche involontarie (side effects) dell'oggetto di invocazione da parte di un metodo.
**Un oggetto const si può usare come oggetto di invocazione soltanto per metodi dichiarati costanti.**

- __static__: Si utilizza quando l'azione del metodo è indipendente dall'oggetto di invocazione (ossia l'oggetto di invocazione non è necessario per la definizione del metodo).
**Un campo dati si può dichiarare static all'interno della definizione della classe, ma va inizializzato fuori.**

- __friend__: poichè una funzione esterna ad una classe non ha accesso ai campi dati privati relativi a quella classe è opportuno usare questo dichiaratore (all'interno della classe) per dichiarare una funzione amica. 