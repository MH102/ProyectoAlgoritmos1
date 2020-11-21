#include "XML/XMLParser.hpp"
#include "Comparator/ComparatorDinamico.hpp"
#include "Comparator/ComparatorDivide.hpp"
#include "Comparator/ComparatorBacktracking.hpp"
using namespace std;
void menu();
void pintarBackTracking(vector<string> listaColores, XMLParser * parser, vector<Country> countryList);
void pintarDinamico(vector<string> listaColores, XMLParser * parser, vector<Country> countryList);
void pintarDivide(vector<string> listaColores, XMLParser * parser, vector<Country> countryList);
vector<string> codeColores;
vector<Country> countryList;
XMLParser *parser = new XMLParser();
int main()
{
    menu();
    return 0;
}

void menu(){
    countryList = parser->parseToCountries();
    cout<<"<---------Bienvenido al sistema de pintado global--------->"<<endl;
    cout<<"1. Agregar Color\n2. Iniciar\n3. Prueba rapida\n4. Salir"<<endl;
    cout<<"=>";
    int option;
    string code;
    cin >> option;
    cin.get();
    switch(option){
        case 1:
            cout<<"Ingrese el codigo de color a utilizar:"<<endl;
            cout<<"=>";
            cin >> code;
            cin.get();
            codeColores.push_back(code);
            return menu();
        case 2:
            if(codeColores.size()>=3){
                if(codeColores.size() <= 11){
                    cout << "Metodo Backtracking: " << endl;
                    pintarBackTracking(codeColores, parser, countryList);
                    cout << "Metodo Dinamico: " << endl;
                    pintarDinamico(codeColores, parser, countryList);
                    cout << "Metodo divide y venceras: " << endl;
                    pintarDivide(codeColores, parser, countryList);
                }
                else{
                    cout << "Hay mas de 11 colores" << endl;
                }
            }
            else{
                cout << "Hay menos de 3 colores" << endl;
            }
            return menu();
        case 3:
            codeColores.push_back("#e63946");
            codeColores.push_back("#e9c46a");
            codeColores.push_back("#457b9d");
            codeColores.push_back("#2a9d8f");
            cout << "Metodo Backtracking: " << endl;
            pintarBackTracking(codeColores, parser, countryList);
            cout << "Metodo Dinamico: " << endl;
            pintarDinamico(codeColores, parser, countryList);
            cout << "Metodo divide y venceras: " << endl;
            pintarDivide(codeColores, parser, countryList);
            return menu();
        case 4:
            return;
        default: 
            cout << "Opcion invalida" << endl;
            return menu();
    }
}

void pintarBackTracking(vector<string> listaColores, XMLParser * parser, vector<Country> countryList)
{
    ComparatorBacktracking comparator(parser);
    for(string color : listaColores)
    {
        comparator.insertarColor(color);
    }
    comparator.comparar(countryList);
    comparator.imprimir();
}
void pintarDinamico(vector<string> listaColores, XMLParser * parser, vector<Country> countryList)
{
    ComparatorDinamico comparator(parser);
    for(string color : listaColores)
    {
        comparator.insertarColor(color);
    }
    comparator.comparar(countryList);
    comparator.imprimir();
}
void pintarDivide(vector<string> listaColores, XMLParser * parser, vector<Country> countryList)
{
    ComparatorDivide comparator(parser);
    for(string color : listaColores)
    {
        comparator.insertarColor(color);
    }
    comparator.comparar(countryList,0,0);
    comparator.imprimir();
}
