#include <iostream>
using namespace std;

class Pizza {
private:
	string sabor;

public:
	Pizza() {}
	Pizza(string sabor) {
		this->sabor = sabor;
	} 

    void setSabor(string sabor);
    void print();

};

class Lista {
private:
    Pizza **pizza;  //1 declarar o vetor de vetores 
    int TAM;
    int n;             // tamanho corrente da lista
    bool posicaoValida(int);
    bool vazia();

public:
    Lista (): Lista(100)  { }
    Lista(int tam) {
        n = 0;
        TAM = tam;
        pizza = new Pizza*[TAM];  //aloca a memoria para o vetor 
    }

    void insere(Pizza *);
    void print();
};

//-----------------------------------------------------------------------------------------------
void Pizza::setSabor(string sabor){
    this->sabor = sabor;

}

void Pizza::print(){
    cout << sabor << "";
}

// ------------------- LISTA
void Lista::insere(Pizza *x) {
    if (n < TAM) {
        n++;
        Pizza *ptr = x;
        pizza[n] = ptr;
    } else {
        cout << "Lista cheia!\n";
    }
}

void Lista::print() {
    for (int i = 1; i <= n; i++)  {
        pizza[i]->print();
        cout << endl;
    }
}

//---------------------------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {

    const int tam = 10;
    Lista l(tam);
    Pizza a("Queijo");
    Pizza b("Calabresa");
    Pizza c("Portuguesa");

    l.insere(&a);
    l.insere(&b);
    l.insere(&c);

    l.print();

    return 0;
}