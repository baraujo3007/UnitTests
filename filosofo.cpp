#include "filosofo.h"
#include "grafo.h"

Filosofo::Filosofo(const int n, Bar& bar, Grafo& g1):filosofo_id(n), bar(bar), g1(g1)
{
    //ctor
}

Filosofo::~Filosofo()
{
    cout<<"Destruiu Filosofo"<<endl;
    //dtor
}

thread* Filosofo::criaTrhead()
{
    return new thread([=]{ existir();});
}

void Filosofo::existir()
{
    for (this->i; i<=g1.iteracao; i++)
    {
        tranquilo();

        bebendo();
    }
}

void Filosofo::tranquilo()
{   //auto comeca_tranq = chrono::steady_clock::now();
    cout<<"Filosofo " << filosofo_id << " está TRANQUILO!"<<endl;
    this_thread::sleep_for(chrono::milliseconds(rand()%2000)); //Coloca a thread para dormir por um tempo entre 0 e 2s
    //auto termina_tranq = chrono::steady_clock::now();
    //auto tempo_tranquilo = chrono::duration_cast<chrono::milliseconds>(termina_tranq - comeca_tranq).count();
}

void Filosofo::bebendo()
{
    auto comeca_sede = chrono::steady_clock::now();  //Pega o tempo atual e armazena
    cout<<"Filosofo "<< filosofo_id <<" está com SEDE, pegando garrafas."<<endl;

    int garrafa_sorteada = 2 + rand()%(g1.calculaAresta(filosofo_id)-2+1);//sorteia numero de garrafas entre 2 e n, sendo n numero de garrafas adjacentes a ele
    lock_guard<mutex> lock_gar(bar.garrafas[garrafa_sorteada]);  //garante que pegou as garrafas entre 2 e n adjacentes a ele
    auto termina_sede = chrono::steady_clock::now(); //Pega o tempo final até conseguir a garrafa
    g1.tempo[filosofo_id] += chrono::duration<double>(termina_sede - comeca_sede).count();
    this_thread::sleep_for(chrono::milliseconds(1000));    //Bebe por 1s.
    cout<<"Filosofo "<< filosofo_id <<" está BEBENDO! "<<garrafa_sorteada<<" garrafas e ficou "<< g1.tempo[filosofo_id] << " segundos com sede"<<endl;
    cout<<"Filosofo "<< filosofo_id << " bebeu "<< this->i <<" vezes"<<endl;

    cout<<"Filosofo "<< filosofo_id << " esta devolvendo a garrafa\n";
}

