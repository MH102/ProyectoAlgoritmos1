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
    vector<Country> paisesVecinos;
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

    vector<Country> getPaisesVecinos()
    {
        return paisesVecinos;
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
            sort(coordsA.begin(), coordsA.end());
            sort(coordsB.begin(), coordsB.end());
            if (coordsA.front().first <= coordsB.front().first)
            {
                for (pair<double, double> xy : coordsB)
                {
                    for (pair<double, double> xy2 : coordsA)
                    {
                        if (xy.first < xy2.first)
                        {
                            break;
                        }
                        else
                        {
                            string first = to_string(xy.second);
                            string second = to_string(xy2.second);
                            if (first == second)
                                return true;
                        }
                    }
                }
            }
            else
            {
                for (pair<double, double> xy : coordsA)
                {
                    for (pair<double, double> xy2 : coordsB)
                    {
                        if (xy.first < xy2.first)
                        {
                            break;
                        }
                        else
                        {
                            string first = to_string(xy.second);
                            string second = to_string(xy2.second);
                            if (first == second)
                                return true;
                        }
                    }
                }
            }
            return false;
        }
        else
        {
            return false;
        }
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
        for (int i = 0; i < countryBorder.size(); i++)
        {
            cout << "(" << countryBorder.at(i).first << "," << countryBorder.at(i).second << ")";
        }
        cout << "]" << endl;
        cout << "Style (color): " << color << endl;
        cout << "Style (frule): " << styleRule << endl;
    }
};
#endif