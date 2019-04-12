#include "RangeIO.h"

#include <string>

using namespace std;


int RangeIO::readInt(istream &in)
{
    string aInt;
    bool ok = false;
    int ret;
    while (!ok)
    {
        in >> aInt;
        try
        {
            for (char c : aInt)
            {
                if (c != '-' && (c < '0' || c > '9'))
                {
                    ok = false;
                    throw invalid_argument("");
                }
            }
            ret = stoi(aInt); 
            ok = true;
        }
        catch (const out_of_range &e)
        {
            cout << "Error: The integer you input is out of range" << endl;
            cout << "Please try again: ";
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: Your input contains invalid characters" << endl;
            cout << "Please try again: ";
        }
    }
    return ret;
}

// 与readInt的不同之处仅仅在于使用getline读入
int RangeIO::readIntFromLine(istream &in)
{
    string aInt;
    bool ok = false;
    int ret;
    while (!ok)
    {
        getline(in, aInt);
        try
        {
            for (char c : aInt)
            {
                if (c != '-' && (c < '0' || c > '9'))
                {
                    ok = false;
                    throw invalid_argument("");
                }
            }
            ret = stoi(aInt); 
            ok = true;
        }
        catch (const out_of_range &e)
        {
            cout << "Error: The integer you input is out of range" << endl;
            cout << "Please try again: ";
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: Your input contains invalid characters" << endl;
            cout << "Please try again: ";
        }
    }
    return ret;
}

int RangeIO::readInt(istream &in, int minVal, int maxVal)
{
    if (minVal > maxVal)
    {
        throw string("Error in readInt(in, minVal, maxVal): minVal can not be larger than maxVal");
    }
    int aInt = readInt(in);
    while (aInt < minVal || aInt > maxVal)
    {
        cout << "Error: The integer you input is out of the range of [" << minVal << "," << maxVal << "]\n";
        cout << "Please try again: ";
        aInt = readInt(in);
    }
    return aInt;
}

int RangeIO::readInt(istream &in, int maxVal)
{
    return readInt(in, 0, maxVal);
}

int RangeIO::readIntFromLine(istream &in, int minVal, int maxVal)
{
    if (minVal > maxVal)
    {
        throw string("Error in readInt(in, minVal, maxVal): minVal can not be larger than maxVal");
    }
    int aInt = readIntFromLine(in);
    while (aInt < minVal || aInt > maxVal)
    {
        cout << "Error: The integer you input is out of the range of [" << minVal << "," << maxVal << "]\n";
        cout << "Please try again: ";
        aInt = readInt(in);
    }
    return aInt;
}

int RangeIO::readIntFromLine(istream &in, int maxVal)
{
    return readIntFromLine(in, 0, maxVal);
}
