#include <vector>
#include <iostream>
#include <cmath>
#include <list>
#include <string>
using namespace std;

class Item
{
    string nombre, direccion;
    long id;

public:
    Item(long _id, string _nombre, string _direccion)
    {
        this->direccion = _direccion;
        this->id = _id;
        this->nombre = _nombre;
    }
};

template <class T>
class Tree
{
private:
    template <class G>
    class Node
    {
    public:
        Node<G> *r;
        Node<G> *l;
        G e;
        Node(G e) : e(e) { r = l = nullptr; }
    };
    Node<T> *root;

    bool (*compare)(T, T);

    int (*busqueda)(T, T);

    void (*imprimir)(T);

    void add(T e, Node<T> *&tmp)
    {
        if (tmp == nullptr)
            tmp = new Node<T>(e);
        else if (compare(e, tmp->e))
            add(e, tmp->r);
        else
            add(e, tmp->l);
    }

    void print(Node<T> *tmp)
    {
        if (tmp == nullptr)
            return;
        print(tmp->l);
        imprimir(tmp->e);
        print(tmp->r);
    }

    bool buscar(Node<T> *nodo, T e)
    {
        if (nodo == nullptr)
            return false;
        else
        {
            int r = busqueda(nodo->e, e);
            if (r == 0)
                return true;
            else if (r < 0)
            {
                return buscar(nodo->r, e);
            }
            else
            {
                return buscar(nodo->l, e);
            }
        }
    }

    void _minimo(Node<T> *nodo)
    {
        if (nodo->l == nullptr)
            cout << nodo->e.toString() << endl;
        else
            return _minimo(nodo->l);
    }
    void _maximo(Node<T> *nodo)
    {
        if (nodo->r == nullptr)
            cout << nodo->e.toString() << endl;
        else
            return _maximo(nodo->r);
    }

    int _cantidad(Node<T> *nodo)
    {
        if (nodo == nullptr)
            return 0;
        else
        {
            int ci, cd;
            ci = _cantidad(nodo->l);
            cd = _cantidad(nodo->r);
            return 1 + ci + cd;
        }
    }
    int _altura(Node<T> *nodo)
    {
        if (nodo == nullptr)
            return 0;
        else
        {
            int ai, ad;
            ai = 1 + _altura(nodo->l);
            ad = 1 + _altura(nodo->r);
            return ai > ad ? ai : ad;
        }
    }

    bool _eliminar(Node<T> *&nodo, T e)
    {
        if (nodo == nullptr)
            return false;
        else
        {
            int r = compare(nodo->e, e);
            if (r < 0)
            {
                return _eliminar(nodo->r, e);
            }
            else if (r > 0)
            {
                return _eliminar(nodo->l, e);
            }
            else
            {
                if (nodo->r == nullptr && nodo->l == nullptr)
                {
                    nodo = nullptr;
                    delete nodo;
                    return true;
                }
                else if (nodo->l == nullptr)
                {
                    nodo = nodo->r;
                    return true;
                }
                else if (nodo->r == nullptr)
                {
                    nodo = nodo->l;
                    return true;
                }
                else
                {
                    Node<T> *aux = nodo->r;
                    while (aux->l != nullptr)
                    {
                        aux = aux->l;
                    }
                    nodo->e = aux->e;
                    return _eliminar(nodo->r, aux->e);
                }
            }
        }
    }

public:
    Tree(bool (*comparar)(T, T), int (*buscar)(T, T), void (*imprime)(T))
    {
        root = nullptr;
        this->compare = comparar;
        this->busqueda = buscar;
        this->imprimir = imprime;
    }

    void add(T e)
    {
        add(e, root);
    }

    void print() { print(root); }

    bool Buscar(T e)
    {
        return buscar(root, e);
    }
    void Minimo()
    {
        _minimo(root);
    }
    void Maximo()
    {
        _maximo(root);
    }
    int cantidad()
    {
        return _cantidad(root);
    }
    int altura()
    {
        return _altura(root);
    }
    int profundidad()
    {
        return _altura(root) - 1;
    }
};

template <class T>
class HashTable
{
    int capacity;
    list<T> *table;

public:
    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(int key)
    {
        return (key % capacity);
    }

    HashTable(int c)
    {
        int size = getPrime(c);
        this->capacity = size;
        table = new list<T>[capacity];
    }
    void insertItem(int key, int data)
    {
        int index = hashFunction(key);
        table[index].push_back(data);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);

        list<int>::iterator i;
        for (i = table[index].begin();
             i != table[index].end(); i++)
        {
            if (*i == key)
                break;
        }

        if (i != table[index].end())
            table[index].erase(i);
    }

    void displayHash()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << "table[" << i << "]";
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

/*
void stoogesort(array L, i = 0, j = length(L)-1){
     if (L[i] > L[j]){        // Compara si el elemento más a la izquierda es más grande que el más a la derecha
         L[i] ↔ L[j]            // Intercambiar el elemento más a la izquierda con el más a la derecha
         }
     if (j - i + 1) > 2 {       // Si hay al menos tres elementos en el arreglo
         t = floor((j - i + 1) / 3)
         stoogesort(L, i  , j-t)  // Ordenar los primeros 2/3 del arreglo
         stoogesort(L, i+t, j)    // Ordenar los últimos 2/3 del arreglo
         stoogesort(L, i  , j-t)  // Ordenar los primeros 2/3 del arreglo denuevo
         }
 }

 procedure slowsort(A[], i, j)          // Sort array range A[i ... j] in-place.
    if i ≥ j then
        return
    m := floor( (i+j)/2 )
    slowsort(A, i, m)                  // (1.1)
    slowsort(A, m+1, j)                // (1.2)
    if A[j] < A[m] then
        swap A[j] , A[m]               // (1.3)
    slowsort(A, i, j-1)                // (2)

*/
/*
float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}
*/