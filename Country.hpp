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
            for (pair<double, double> pais1 : sumarVectores(countryBorder))
            {
                for (pair<double, double> pais2 : sumarVectores(pais.getCountryBorder()))
                {
                    if (pais1.first - pais2.first < 1 && pais1.first - pais2.first > -1)
                    {
                        if (pais1.second - pais2.second < 1 && pais1.second - pais2.second > -1)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
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