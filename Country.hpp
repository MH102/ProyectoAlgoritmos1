#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Country
{
    private:
        string idCountry;
        string countryName;
        string countryCode;
        vector<vector<pair<double, double>>> countryBorder;
        vector<Country> paisesVecinos;
        string color;
        string styleRule;

    public:
        Country(){}//Mejor eliminar antes de llegar al main 

        Country(string pidCountry, string pCountryName, string pCountryCode, vector<vector<pair<double, double>>> pCountryBorder, string pColor, string pStyleRule)
        {
            idCountry = pidCountry;
            countryName = pCountryName;
            countryCode = pCountryCode;
            countryBorder = pCountryBorder;
            color = pColor;
            styleRule = pStyleRule;
        }

        string getidCountry()
        {
            return idCountry;
        }
        
        string getCountryName()
        {
            return countryName;
        }
        
        string getCountryCode()
        {
            return countryCode;
        }

        vector<Country> getPaisesVecinos(){
            return paisesVecinos;
        }
        
        vector<vector<pair<double, double>>> getCountryBorder()
        {
            return countryBorder;
        }
        
        string getColor()
        {
            return color;
        }
        
        string getStyleRule()
        {
            return styleRule;
        }

        void addPaisVecino(Country pais){
            paisesVecinos.push_back(pais);
        }
        
        vector<pair<double, double>> sumarVectores(vector<vector<pair<double, double>>> vec1)
        {
            vector<pair<double, double>> res;
            for (vector<pair<double, double>> v : vec1)
            {
                for (pair<double, double> p : v)
                    res.push_back(p);
            }
            return res;
        }
        
        bool seIntersecan(Country pais)
        {
            Country initCountry;
            Country nextCountry;

            for (pair<double, double> initCountry : sumarVectores(countryBorder))
            {
                for (pair<double, double> nextCountry : sumarVectores(pais.getCountryBorder()))
                {
                    if (initCountry.first - nextCountry.first < 1 && initCountry.first - nextCountry.first > -1)
                    {
                        if (initCountry.second - nextCountry.second < 1 && initCountry.second - nextCountry.second > -1)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        void printVecinos() {
            for (int indexCountry = 0; indexCountry < paisesVecinos.size(); indexCountry++){
                cout<< paisesVecinos.at(indexCountry).getCountryName() << endl;
            }
        }
        
        void print()//Mejor eliminar antes de llegar al main
        {
            cout << "idCountry: " << idCountry << endl;
            cout << "Country Name: " << countryName << endl;
            cout << "Country Code: " << countryCode << endl;
            cout << "Border: " << endl;
            for (int i = 0; i < countryBorder.size(); i++)
            {
                cout << "[";
                for (int j = 0; j < countryBorder.at(i).size(); j++)
                {
                    cout << "(" << countryBorder.at(i).at(j).first << "," << countryBorder.at(i).at(j).second << ")";
                }
                cout << "]" << endl;
            }
            cout << "Style (color): " << color << endl;
            cout << "Style (frule): " << styleRule << endl;
        }
};