#ifndef LISTCAT_H_INCLUDED
#define LISTCAT_H_INCLUDED

#include <exception>
#include <iostream>
#include <string>

#define TAMMAX 500

using namespace std;

class ListCatException : public exception{ // es para hacer excepciones , un error

	protected:
		string msg;

	public:
		explicit ListCatException(const char* message) : msg(message){}

		explicit ListCatException(const string& message ) : msg(message){}

		virtual~ListCatException() throw (){}

		virtual const char* what() const throw() { return msg.c_str();}

};


template<class T> // clase plantila T identificador
class ListCat {
    private:
        T data[TAMMAX];
        int last;
        void exchange(T&, T&);// metodos de ordenamiento
    public:
        ListCat();
        ~ListCat();
        bool isEmpty();
        bool isFull();
        void insertData(int, T);
        void deleteData(int);
        int firstPos();
        int lastPos();
        int previousPos(int);
        int nextPos(int);
        int findData(T);
        T retrieve(int); //recuperar
        void bubbleSort(); // ordenamiento burbuja
        void print();
        void deleteAll();
        void shellSort();
        void seleccion();
        void selectSort();
        void insertSort();
    };
template<class T>// empiesas de cero por eso -1

ListCat<T>::ListCat() {
    last = -1;
    }
template<class T>
ListCat<T>::~ListCat() {
    deleteAll();
    }
template<class T>
bool ListCat<T>::isEmpty() {
    return last == -1;
    }
template<class T>
bool ListCat<T>::isFull() {
    return last == TAMMAX - 1;
    }
template<class T>
void ListCat<T>::insertData(int p, T e) { // p = posicion  T class, e elvalor que se da
    if(isFull()) {
        throw ListCatException("Error!, Desbordamiento de datos");
        }
    if(p < -1 or p > last) {
        throw ListCatException("Error!, Posicion invalida");
        }

    int i=last+1;
    while(i > p and i != 0) {
        data[i] = data[i-1];
        i--;
        }
    data[p+1] = e;
    last ++;
    }
template<class T>
void ListCat<T>::deleteData(int p) {
    if(isEmpty()) {
        throw ListCatException("Error!, Insuficiencia de datos");

        }
    if(p < 0 or p > last) {
        throw ListCatException("Error!, Posicion invalida");

        }

    int i = p;
    while(i < last) {
        data[i] = data[i+1];
        i++;
        }
    last--;
    }
template<class T>
int ListCat<T>::firstPos() {
    if(isEmpty()){
            return -1;
    }
    return 0;
    }
template<class T>
int ListCat<T>::lastPos() {
    return last;
    }
template<class T>
int ListCat<T>::previousPos(int p) {
    if(isEmpty() or p < 1 or p > last ){
        return -1;
    }

    return p-  1;
    }
template<class T>
int ListCat<T>::nextPos(int p) {
    if(isEmpty() or p < 0 or p >= last){
        return -1;
    }

    return p + 1;
    }
template<class T>
int ListCat<T>::findData(T e) {
    int i;
    while(i <= last){
        if(data[i] == e){
            return i;
            }
            i++;
        }
    return -1;
    }
template<class T>
T ListCat<T>::retrieve(int p) {
    if(isEmpty()){
        throw ListCatException("Error!, Insuficiencia de datos");

    }
    if(p < 0 or p > last){
        throw ListCatException("Error!, Posicion invalida");

    }

    return data[p];
    }
template<class T>
void ListCat<T>::bubbleSort() {
    int i = last;
    int j;
    bool change;// bandera

    do{
            change = false;
            j = 0;
            while(j < 1){
                if(data[j] > data[j + 1])
                    exchange(data[j], data[j + 1]);
                    change =  true;
            }
        i--;
    }while(change);
    }
template<class T>
void ListCat<T>::print() {
    int i = 0;
    while(i <= last){
        cout << data[i].print() << ", ";
        i++;
    }

    }
template<class T>
void ListCat<T>::deleteAll() {
    last = -1;
    }
template<class T>
void ListCat<T>::shellSort(){
    float factor = 2.0 / 3.0;
    int i;
    int limit;
    int dif;

    for(dif =  last * factor; dif > 0; dif *= factor){
            for(limit = last - dif, i = 0;i <= limit; i++){
                if(data[i] > data[i + dif]){
                    exchange(data[i], data[i + dif]);
                }
            }
    }
}

template<class T>
void ListCat<T>::exchange(T& a,T& b){
    T aux = a;
    a = b;
    b = aux;
    }



template<class T>
void ListCat<T>::seleccion()
{
    int i = last;
    int aux;
    int menor;
    for(int j=0; j < i; j++)
        if(data[i]);

}

template<class T>
void ListCat<T>::insertSort()
{
    int i, j;
    int aux;

    i = 0;
    while(i < last)
    {
        aux = data[i];
        j = i;

        while(j > 0 and aux < data[j-1])
        { data[j] = data[j-1];
            j--;
        }
        if(i != j)
        {
            data[j] = aux;
        }
        i++;
    }
}
template<class T>
void ListCat<T>::selectSort()
{
    int i, j , m;

    i = 0;
    while(i<last)
    {
        m = i;
        j = i + 1;
        while(j <= last)
        {
            if(data[j] < data[m])
            {
                m = j;
            }
            j++;
        }
        if(i != m)
        {
            exchange(data[i], data[m]);
        }
        i++;
    }
}
#endif // LISTCAT_H_INCLUDED
