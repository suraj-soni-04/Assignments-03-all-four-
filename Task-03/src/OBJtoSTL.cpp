#include <..\headers\OBJtoSTL.h>
#include <..\headers\ObjReader.h>
#include <..\headers\ObjWriter.h>
#include <..\headers\Triangulation.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <sstream>
using namespace std;

void OBJtoSTLConverter::objToStlConvertor(string &fromObjFilePath, string &toSTLFilePath)
{
    ObjReader objReader;
    ObjWriter objWriter;
    Triangulation triangulation;
    vector<Point3D> uniquePoints = triangulation.getPoints();
    vector<Triangle> triangles = triangulation.getTriangles();
    objReader.fileReader(fromObjFilePath, uniquePoints, triangles);
    objWriter.fileWriter("..\\resources\\file.txt",uniquePoints, triangles);

    ifstream inputFile("..\\resources\\file.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file "<<endl;
        return;
    }

    ofstream outputFile(toSTLFilePath);
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file " << endl;
        return;
    }

    outputFile << "solid Cube" << endl;

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z))
        {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        outputFile << "  facet normal 0 0 0" << endl;
        outputFile << "    outer loop" << endl;
        outputFile << "      vertex " << x << " " << y << " " << z << endl;
        if (!(getline(inputFile, line)))
        {
            cerr << "Incomplete input for triangle." << endl;
            break;
        }
        istringstream iss2(line);
        if (!(iss2 >> x >> y >> z))
        {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        outputFile << "      vertex " << x << " " << y << " " << z << endl;
        if (!(getline(inputFile, line)))
        {
            cerr << "Incomplete input for triangle." << endl;
            break;
        }
        istringstream iss3(line);
        if (!(iss3 >> x >> y >> z))
        {
            cerr << "Error reading line: " << line << endl;
            continue;
        }
        outputFile << "      vertex " << x << " " << y << " " << z << endl;
        outputFile << "    endloop" << endl;
        outputFile << "  endfacet" << endl;
    }

    outputFile << "endsolid Cube" << endl;

    inputFile.close();
    outputFile.close();
}