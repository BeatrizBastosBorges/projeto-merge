#include <iostream>
#include <locale.h>

/*Elabore um programa que permita digitar 30 n�meros inteiros.

Garantir que cada n�mero digitado seja maior do que o anterior, mantendo a ordem crescente da digita��o.

Ap�s digitado, cada n�mero dever� ser empilhado em uma estrutura respectiva, de acordo com o fato dele ser par ou �mpar.

Finalizada a digita��o dos 30 n�meros, os valores dever�o ser desempilhados e mostrados na tela, garantindo uma sequ�ncia decrescente.

Obs: Desenvolver essa solu��o implementando as pilhas em forma de lista encadeada e de vetor.*/

using namespace std;
#define MAX 30

struct Pilha {
    int qtde;
    float elementos[MAX];
};

Pilha* init()
{
    Pilha* p = new Pilha;
    p->qtde = 0;
    return p;
}

int isEmpty(Pilha* p)
{
    return (p->qtde == 0);
}

int count(Pilha* p)
{
    return (p->qtde);
}

void freePilha(Pilha* p)
{
    free(p);
}

int push(Pilha* p, float v)
{
    int podeEmpilhar = (p->qtde < MAX);
    if (podeEmpilhar)
        p->elementos[p->qtde++] = v;

    return podeEmpilhar;
}

int pop(Pilha* p)
{
    int podeDesempilhar = (p->qtde > 0);
    float v;

    if (podeDesempilhar)
    {
        v = p->elementos[p->qtde - 1];
        p->qtde--;
    }
    else
    {
        v = - 1;
    }
        

    return v;
}

void print(Pilha* p) {
    cout << "\nQtde de elementos: " << count(p) << endl;
    for (int i = p->qtde - 1; i >= 0; --i) {
        cout << p->elementos[i] << endl;
    }
    cout << "--------------------" << endl;

}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    Pilha* pilhaFloat;
    pilhaFloat = new Pilha();
    pilhaFloat = init();

    Pilha* pilhaPar = new Pilha();
    pilhaPar = init();

    Pilha* pilhaImpar = new Pilha();
    pilhaImpar = init();

    cout << "Pilha vazia: " << (isEmpty(pilhaFloat) ? "Sim" : "N�o") << endl;

    cout << "\n";

    cout << "Digite 30 valores para popular a lista. Cada valor deve ser maior que o anterior." << endl;

    int valor = 0;
    int aux = valor;
    for (int i = 0; i < 30; i++)
    {
        cin >> valor;
        while (valor < aux)
        {   
            cout << "O valor digitado � menor que o anterior. Digite novamente" << endl;
            cin >> valor;
        }

        push(pilhaFloat, valor);
        
        aux = valor;
        valor = 0;
    }
    
    int aux2;
    for(int j = 0; j < 30; j++)
    {
        aux2 = pilhaFloat->elementos[j];
        if (aux2 % 2 == 0)
            push(pilhaPar, aux2);

        else
            push(pilhaImpar, aux2);
    }

    cout << "Pilha completa: " << endl;
    print(pilhaFloat);

    cout << "\n";
    cout << "\n";
    
    cout << "Pilha par: " << endl;
    print(pilhaPar);
    
    cout << "\n";
    cout << "\n";
   
    cout << "Pilha �mpar: " << endl;
    print(pilhaImpar);
    return 0;
}

