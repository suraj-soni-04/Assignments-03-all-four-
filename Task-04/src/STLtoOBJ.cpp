#include <..\headers\STLtoOBJ.h>
#include <..\headers\STLReader.h>
#include <..\headers\STLWriter.h>
#include <..\headers\Triangulation.h>
#include <..\headers\Point3D.h>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <sstream>
#include<unordered_map>
using namespace std;

void STLtoOBJConverter::stlToObjConvertor(string &fromStlFilePath, string &toObjFilePath)
{

    STLReader stlReader;
    STLWriter stlWriter;
    Triangulation triangulation;
    vector<Point3D> uniquePoints = triangulation.getPoints();
    vector<Triangle> triangles = triangulation.getTriangles();
    unordered_map<int, Point3D> mapping;
    
    
    stlReader.fileReader(fromStlFilePath,uniquePoints, triangles, mapping);
    stlWriter.fileWriter("..\\resources\\file.txt",uniquePoints, triangles, mapping);

    ifstream inputFile("..\\resources\\file.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file " << endl;
        return;
    }

    ofstream outputFile(toObjFilePath);
    if (!outputFile.is_open())
    {
        cerr << "Error opening output file " << endl;
        return;
    }

    for(auto vertex:uniquePoints)
    {
        outputFile<<"v "<<vertex.getMX()<<" "<<vertex.getMY()<<" "<<vertex.getMZ()<<endl;
    }

    for (auto triangle:triangles)
    {
        outputFile << "f" << " "<< triangle.getVertex1()<<" "<<triangle.getVertex2()<<" "<<triangle.getVertex3()<<endl;        
    }

    inputFile.close();
    outputFile.close();
}