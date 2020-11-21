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
    vector<pair<double, double>> countryBorder;
    string color;
    string styleRule;

public:
    struct sort_pred
    {
        bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right)
        {
            return left.second < right.second;
        }
    };

    Country() {} //Mejor eliminar antes de llegar al main

    Country(string pidCountry, string pCountryName, string pCountryCode, vector<pair<double, double>> pCountryBorder, string pColor, string pStyleRule)
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

    vector<pair<double, double>> getCountryBorder()
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
        vector<pair<double, double>> coordsA(getCountryBorder());
        vector<pair<double, double>> coordsB(pais.getCountryBorder());
        pair<double, double> xExtremesA = make_pair(coordsA.back().first, coordsA.front().first);
        pair<double, double> xExtremesB = make_pair(coordsB.back().first, coordsB.front().first);
        sort(coordsA.begin(), coordsA.end(), sort_pred());
        sort(coordsB.begin(), coordsB.end(), sort_pred());
        pair<double, double> yExtremesA = make_pair(coordsA.back().second, coordsA.front().second);
        pair<double, double> yExtremesB = make_pair(coordsB.back().second, coordsB.front().second);
        if (dosLineasColisionan(xExtremesA, xExtremesB) && dosLineasColisionan(yExtremesA, yExtremesB))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print() //Mejor eliminar antes de llegar al main
    {
        cout << "idCountry: " << idCountry << endl;
        cout << "Country Name: " << countryName << endl;
        cout << "Country Code: " << countryCode << endl;
        cout << "Border: " << endl;
        cout << "[";
        for (int borderIndex = 0; borderIndex < countryBorder.size(); borderIndex++)
        {
            cout << "(" << countryBorder.at(borderIndex).first << "," << countryBorder.at(borderIndex).second << ")";
        }
        cout << "]" << endl;
        cout << "Style (color): " << color << endl;
        cout << "Style (frule): " << styleRule << endl;
    }
};
#endif