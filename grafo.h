#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <chrono>

using namespace std;

class Grafo
{
    private:
        string const DELIMITER = ", ";
        //percorre o arquivo e transforma em linhas e colunas na martiz
        void criaMatriz(list<string> lista);
        void converteLinhaArquivoColunaMatriz(int i, string linhas);
        void criaListaDeTemposFilosofos(); //cria lista de tempos dos filosofos

    public:
        //variaveis
        int** matrix;
        int tam;        //numero de vertices
        int iteracao;
        double* tempo;

        //construtor/destrutor
        Grafo(string nomeArquivo, int iteracoes);
        virtual ~Grafo();

    public:
        //metodos
        list<string> leLinhas(string nomeArquivo);
        int calculaAresta(int indice);
        int totalGarrafas();
        void liberaMemoria();
        void apagaMatriz(list<string> lista);
        double getMediaFilosofoComSedeEmSegundos(int id_filosofo);
};

#endif // GRAFO_H

