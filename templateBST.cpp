#include <iostream>
#include <queue>
#include<sstream>
#include <stack>
using namespace std;

struct Nodo {
	int dato;
	Nodo* left;
	Nodo* right;

	Nodo(int dato) {
		this->dato = dato;
		left = nullptr;
		right = nullptr;
	}
};

class BST {
	Nodo* raiz=nullptr;
	Nodo* insertarNodoAux(Nodo* nodo, int dato);
	Nodo* buscarNodoAux(Nodo* nodo, int dato);
	void imprimirEnOrdenAux(Nodo* nodo);
	void imprimirPreOrdenAux(Nodo* nodo);
	void imprimirPostOrdenAux(Nodo* nodo);
	int heightAux(Nodo* nodo);
	int sizeAux(Nodo* nodo);
public:
	void insertarNodo(int dato);
	Nodo* buscarNodo(int dato);
	void imprimirEnOrden();
	void imprimirPreOrden();
	void imprimirPostOrden();
	void destruirArbol(Nodo* nodo);
	void imprimirPorProfundidadDFS();
	void imprimirPorAnchuraBFS();
	int size();
	int height();
	~BST();
};

void BST::insertarNodo(int dato) {
	raiz = insertarNodoAux(raiz, dato);
}

// Función auxiliar para insertar un nodo en el árbol
Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
	if (nodo == nullptr)
		return new Nodo(dato);

	if (dato < nodo->dato)
		nodo->left = insertarNodoAux(nodo->left, dato);
	else
		nodo->right = insertarNodoAux(nodo->right, dato);
	return nodo;
}

Nodo* BST::buscarNodo(int dato) {
	return buscarNodoAux(raiz, dato);
}

// Función auxiliar para buscar un nodo en el árbol
Nodo* BST::buscarNodoAux(Nodo* nodo, int dato) {
	if (nodo == nullptr || nodo->dato == dato)
		return nodo;

	if (dato < nodo->dato)
		return buscarNodoAux(nodo->left, dato);
	else
		return buscarNodoAux(nodo->right, dato);
}


void BST::imprimirEnOrden() {
	imprimirEnOrdenAux(raiz);
	cout << endl;
}

void BST::imprimirEnOrdenAux(Nodo* nodo) {
	if (nodo == nullptr)
		return;

	imprimirEnOrdenAux(nodo->left);
	cout << nodo->dato << " ";
	imprimirEnOrdenAux(nodo->right);
}

void BST::imprimirPreOrden() {
	imprimirPreOrdenAux(raiz);
	cout << endl;
}

void BST::imprimirPreOrdenAux(Nodo* nodo) {
	if (nodo == nullptr)
		return;

	cout << nodo->dato << " ";
	imprimirPreOrdenAux(nodo->left);
	imprimirPreOrdenAux(nodo->right);
}

void BST::imprimirPostOrden() {
	imprimirPostOrdenAux(raiz);
	cout << endl;
}

void BST::imprimirPostOrdenAux(Nodo* nodo) {
	if (nodo == nullptr)
		return;

	imprimirPostOrdenAux(nodo->left);
	imprimirPostOrdenAux(nodo->right);
	cout << nodo->dato << " ";
}

void BST::imprimirPorAnchuraBFS() {
	if (raiz == nullptr){
		cout<< "Arbol vacio";
	}else{
		stringstream ss;
		queue<Nodo*> q;
		q.push(raiz);
		while (!q.empty()){
			Nodo *node = q.front();
			q.pop();
			ss<<node->dato<<" ";
			if (node->left != nullptr) q.push(node->left);
			if (node->right != nullptr) q.push(node->right);
		}
		cout<< ss.str()<<endl;
	}
}

void BST::imprimirPorProfundidadDFS() {
	if (raiz == nullptr){
		cout<< "Arbol vacio";
	}else{
		stringstream ss;
		stack<Nodo*> q;
		q.push(raiz);
		while (!q.empty()){
			Nodo *node = q.top();
			q.pop();
			ss<<node->dato<<" ";
			if (node->right != nullptr) q.push(node->right);
			if (node->left != nullptr) q.push(node->left);

		}
		cout<< ss.str()<<endl;
	}
}

BST::~BST() {
	destruirArbol(raiz);
}

void BST::destruirArbol(Nodo* nodo) {
	if (nodo == nullptr)
		return;

	destruirArbol(nodo->left); 	// Recorrer el subárbol izquierdo
	destruirArbol(nodo->right);	// Recorrer el subárbol derecho

	delete nodo; // Eliminar el nodo actual
}

int BST::size() {
	return sizeAux(raiz);
}

// Función auxiliar para obtener el tamaño del árbol
int BST::sizeAux(Nodo* nodo) {
	if (nodo == nullptr) {
		return 0;
	}
	return 1 + sizeAux(nodo->left) + sizeAux(nodo->right);
}


// Función para obtener la altura del árbol
int BST::height() {
	return heightAux(raiz);
}

// Función auxiliar para obtener la altura del árbol
int BST::heightAux(Nodo* nodo) {
	if (nodo == nullptr) {
		return -1;
	}
	return 1 + max(heightAux(nodo->left), heightAux(nodo->right));
}


int main() {
	// Casos implementandose
	BST arbol1;

	arbol1.insertarNodo(12);
	arbol1.insertarNodo(8);
	arbol1.insertarNodo(20);
	arbol1.insertarNodo(5);
	arbol1.insertarNodo(1);
	arbol1.insertarNodo(15);
	arbol1.insertarNodo(25);
	arbol1.insertarNodo(7);
	arbol1.insertarNodo(11);
	arbol1.insertarNodo(9);
	arbol1.insertarNodo(13);
	arbol1.insertarNodo(22);
	arbol1.insertarNodo(18);
	arbol1.insertarNodo(26);

	BST arbol2;

	arbol2.insertarNodo(1);
	arbol2.insertarNodo(5);
	arbol2.insertarNodo(7);
	arbol2.insertarNodo(8);
	arbol2.insertarNodo(9);
	arbol2.insertarNodo(11);
	arbol2.insertarNodo(12);
	arbol2.insertarNodo(13);
	arbol2.insertarNodo(15);
	arbol2.insertarNodo(18);
	arbol2.insertarNodo(20);
	arbol2.insertarNodo(22);
	arbol2.insertarNodo(25);
	arbol2.insertarNodo(26);

	cout<<"----------------------------------------\n";
	cout<<"Salida para el caso 1:\n";
	cout<<"Salida pre-order: -> ";
	arbol1.imprimirPreOrden();
	cout<<"Salida in-order: -> ";
	arbol1.imprimirEnOrden();
	cout<<"Salida post-order: -> ";
	arbol1.imprimirPostOrden();
	cout<<"Salida por anchura: -> ";
	arbol1.imprimirPorAnchuraBFS();
	cout<<"Salida por profundidad: -> ";
	arbol1.imprimirPorProfundidadDFS();
	cout<<"----------------------------------------\n";
	cout<<"Salida para el caso 2:\n";
	cout<<"Salida pre-order: -> ";
	arbol2.imprimirPreOrden();
	cout<<"Salida in-order: -> ";
	arbol2.imprimirEnOrden();
	cout<<"Salida post-order: -> ";
	arbol2.imprimirPostOrden();
	cout<<"Salida por anchura: -> ";
	arbol2.imprimirPorAnchuraBFS();
	cout<<"Salida por profundidad: -> ";
	arbol2.imprimirPorProfundidadDFS();





}
