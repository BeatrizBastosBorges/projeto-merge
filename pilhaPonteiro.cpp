#include <iostream>
#include <locale.h>

/*Desenvolvido por Beatriz Bastos Borges e Miguel Luizatto Alves.*/

using namespace std;

#define MAX 30

struct No
{   
    float dado;
    struct No *prox;
};

struct Pilha
{
    No *topo;
};

Pilha* init()
{
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha* p)
{
    return (p->topo == NULL);
}

int count(Pilha *p)
{
    int i = 0;
    No *no;
    no = p->topo;
    while (no != NULL)
    {
        i++;
        no = no->prox;
    }
    return i;
}

void print(Pilha* p)
{
    No* no;
    no = p->topo;
    cout << "Qtde de elementos: " << count(p) << endl;
    while (no != NULL) 
    {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "--------------------" << endl;
}

void freePilha(Pilha* p) 
{
    No* no;
    no = p->topo;
    while (no != NULL) 
    {
        No* aux = no->prox;
        free(no);
        no = aux;
    }
    free(p);
}

void push(Pilha* p, float v)
{
    No *no = new No;
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

float pop(Pilha* p)
{
    float v;
    int podeDesempilhar = (p->topo != NULL);
    if (podeDesempilhar)
    {
        No *no = p->topo;
        v = no->dado; 
        p->topo = no->prox;
        free(no);
    }
    else
    {
        v = -1;
    }

    return v;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    Pilha *pilhaFloat = new Pilha();
    pilhaFloat = init();

    Pilha *pilhaPar = new Pilha();
    pilhaPar = init();

    Pilha *pilhaImpar = new Pilha();
    pilhaImpar = init();

    cout << "Pilha vazia: " << (isEmpty(pilhaFloat) ? "SIM" : "NÃO") << endl;
    
    cout << "\n";

    cout << "Digite 30 valores para popular a lista. Cada valor deve ser maior que o anterior." << endl;
    int valor = 0;
    int aux = valor;
    for (int i = 0; i < 30; i++)
    {
        cin >> valor;
        while (valor < aux)
        {
            cout << "O valor digitado é menor que o anterior. Digite novamente" << endl;
            cin >> valor;
        }

        push(pilhaFloat, valor);

        aux = valor;
        valor = 0;
    }
    
    cout << "\n";

    cout << "Pilha completa: " << endl;
    print(pilhaFloat);

    for (int j = 0; j < 30; j++)
    {
        float aux2 = pop(pilhaFloat);
        if ((int)aux2 % 2 == 0)
            push(pilhaPar, aux2);
        else
            push(pilhaImpar, aux2);
    }

    cout << "\n";

    cout << "Pilha par: " << endl;
    print(pilhaPar);

    cout << "\n";

    cout << "Pilha ímpar: " << endl;
    print(pilhaImpar);
    
    return 0;
}

