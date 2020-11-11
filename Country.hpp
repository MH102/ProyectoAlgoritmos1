#ifndef COUNTRY
#define COUNTRY

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Country
{
private:
    string idCountry;
    string countryName;
    string countryCode;
    vector<vector<double>> countryBorder;
    vector<Country> paisesVecinos;
    string color;
    string styleRule;

public:
    Country() {} //Mejor eliminar antes de llegar al main

    Country(string pidCountry, string pCountryName, string pCountryCode, vector<vector<double>> pCountryBorder, string pColor, string pStyleRule)
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

    vector<Country> getPaisesVecinos()
    {
        return paisesVecinos;
    }

    vector<vector<double>> getCountryBorder()
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

    void addPaisVecino(Country pais)
    {
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

    bool puntoEstaDentroDeLinea(double extremoIzq, double extremoDer, double punto)
    {
        if (extremoIzq >= punto && extremoDer <= punto)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool dosLineasColisionan(pair<double, double> lineaA, pair<double, double> lineaB)
    {
        if (puntoEstaDentroDeLinea(lineaA.first, lineaA.second, lineaB.first) || puntoEstaDentroDeLinea(lineaA.first, lineaA.second, lineaB.second))
        {
            return true;
        }
        if (puntoEstaDentroDeLinea(lineaB.first, lineaB.second, lineaA.first) || puntoEstaDentroDeLinea(lineaB.first, lineaB.second, lineaA.second))
        {
            return true;
        }
        return false;
    }
    bool seIntersecan(Country pais)
    {
        vector<vector<double>> coordsA = getCountryBorder();
        vector<vector<double>> coordsB = pais.getCountryBorder();
        pair<double, double> xExtremesA = make_pair(coordsA.at(0).back(), coordsA.at(0).front());
        pair<double, double> xExtremesB = make_pair(coordsB.at(0).back(), coordsB.at(0).front());
        pair<double, double> yExtremesA = make_pair(coordsA.at(1).back(), coordsA.at(1).front());
        pair<double, double> yExtremesB = make_pair(coordsB.at(1).back(), coordsB.at(1).front());
        return (dosLineasColisionan(xExtremesA, xExtremesB) && dosLineasColisionan(yExtremesA, yExtremesB));
    }

    void printVecinos()
    {
        for (int indexCountry = 0; indexCountry < paisesVecinos.size(); indexCountry++)
        {
            cout << paisesVecinos.at(indexCountry).getCountryName() << endl;
        }
    }

    void print() //Mejor eliminar antes de llegar al main
    {
        cout << "idCountry: " << idCountry << endl;
        cout << "Country Name: " << countryName << endl;
        cout << "Country Code: " << countryCode << endl;
        cout << "Border: " << endl;
        cout << "[";
        for (int i = 0; i < countryBorder.at(0).size(); i++)
        {
            cout << "(" << countryBorder.at(0).at(i) << "," << countryBorder.at(1).at(i) << ")";
        }
        cout << "]" << endl;
        cout << "Style (color): " << color << endl;
        cout << "Style (frule): " << styleRule << endl;
    }
};
#endif