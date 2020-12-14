#include "grafo.h"
#include <fstream>

Grafo::Grafo(string nomeArquivo, int x)
{
    list <string> lista = this->leLinhas(nomeArquivo); //chama método que abre o arquivo
    this->tam = lista.size();
    this->iteracao = x;
    this->criaMatriz(lista);        //a partir das listas, cria a matriz
    this->apagaMatriz(lista);
    this->criaListaDeTemposFilosofos();
}

Grafo::~Grafo()
{
    cout<<"Destruiu Grafo"<<endl;
    //dtor
}

list<string> Grafo::leLinhas(string nomeArquivo)
{
    fstream file;   //cria objeto do arquivo
    file.open(nomeArquivo);
    list <string> lista;
    string linhas;
    if(!file.is_open())
    {
        cout<<"ERRO AO ABRIR ARQ";
        exit(0);
    }
    while(!file.eof())
    {
        getline(file, linhas);
        if(linhas.empty()) break;   //interrompe caso ache linha em branco
        lista.push_back(linhas);
    }
    file.close();   //fecha o arquivo
    return lista;
}

void Grafo::criaMatriz(list<string> lista)
{
    this->matrix = new int*[lista.size()];
    string linhas;
    //int teste=0;
    for(unsigned int i=0; i<lista.size(); i++)
    {
        auto it = next(lista.begin(), i); // pega o endereo de memoria do item da lista, comçeando no inicio da lista
        linhas = *it;                     // pegando o n-esimo elemento da lista, apontando pro iterador
        this->matrix[i] = new int[lista.size()]; //inicializando vetor coluna da matriz
        this->converteLinhaArquivoColunaMatriz(i, linhas);
    }
}

void Grafo::criaListaDeTemposFilosofos()
{
    this->tempo = new double [this->tam];
    for(int i=0; i<tam; i++) { this->tempo[i] = 0; }
}

double Grafo::getMediaFilosofoComSedeEmSegundos(int id_filosofo)
{
    return this->tempo[id_filosofo]/this->iteracao;
}

void Grafo::apagaMatriz(list <string> lista)
{   list<string>::iterator it1, it2;
    it1 = lista.begin();
    it2 = lista.begin();
    advance(it2, lista.size());
    lista.erase(it1, it2);
}

void Grafo::converteLinhaArquivoColunaMatriz(int i, string linhas)
{
    string token;
    size_t pos = 0;
    int j = 0;
    while((pos = linhas.find(DELIMITER)) != string::npos)   //acha pos do delimitador (, )
    {
        token = linhas.substr(0, pos);      //pega pedaço da string do começo até o delimitador
        this->matrix[i][j] = stoi(token);    //armazena token na matriz de grafos
        linhas.erase(0, pos + DELIMITER.length());  //apaga de uma posição ate a outra da string
        j++;                //incrementa a coluna
    }
}

int Grafo::calculaAresta(int indice)   //retorna numero de arestas de cada filosofo
{
    int arestas=0;
    for(int j=0;j<tam;j++)
    {
        if(this->matrix[indice][j]==1)
        {
            arestas++;
        }
    }
    return arestas;
}

int Grafo::totalGarrafas()  //retorna numero de garrafas totais
{
    int num_garrafas=0;
    int tot_garrafas=0;
    for(int i=0;i<tam;i++)
    {
        for(int j=0; j<tam; j++)
        if(this->matrix[i][j] ==1)
        {
            num_garrafas++;
        }
        tot_garrafas = num_garrafas/2;
    }
    return tot_garrafas;
}

void Grafo::liberaMemoria()
{
    delete this->matrix;
    //free (this->matrix);
}
