#include "grafo.h"
#include "bar.h"
#include "filosofo.h"

int main(int argc, char* argv[])
{
    cout<<"O BAR DOS FILÓSOFOS ESTÁ ABERTO!"<<endl;
    const int numero_iteracoes = 6;
    Grafo grafo("teste.txt", numero_iteracoes);   //Entre com o grafo e o número de vezes que o filosofo irá BEBER
    Bar bar(grafo);
    vector <Filosofo* > filosofo;
    vector <thread *> filo(grafo.tam); //cria thread com 5 filosofos
    for (int i=0; i<grafo.tam; i++)
    {
        filosofo.push_back(new Filosofo(i, bar, grafo));
    }
    for(int i=0; i<grafo.tam;i++)
    {
        filo[i] = filosofo[i]->criaTrhead();
    }

    for(int i=0;i<grafo.tam;i++)
    {
        filo[i]->join();
    }

    for(int i=0;i<grafo.tam;i++)
    {
        cout<<"O filosofo "<< i << " ficou "<< grafo.getMediaFilosofoComSedeEmSegundos(i) <<" milisegundos com sede!"<<endl;
    }


    filosofo.clear();
    filo.clear();
	
    for(int i=0;i<grafo.tam;i++){
        delete filosofo[i];
        delete filo[i];
        delete[] grafo.matrix[i];
        cout<<"deletou filosofos e matrix"<<endl;
    }
   
    delete[] grafo.matrix;
    delete[] grafo.tempo;

    return 0;
}
