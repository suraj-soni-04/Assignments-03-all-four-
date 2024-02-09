#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <windows.h>
#include <string.h>
#include <..\headers\Point3D.h>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\OBJWriter.h>
#include <..\headers\OBJReader.h>
using namespace std;
int main()
{
    string inputFile = "..\\objFiles\\cube.obj";
    string outputFile = "..\\outputFile\\file.txt";

    ObjReader objReader;
    ObjWriter objWriter;
    Triangulation triangulation;
    vector<Point3D> uniquePoints = triangulation.getPoints();
    vector<Triangle> triangles = triangulation.getTriangles();

    cout << "*** STARTED ***" << endl;
    Sleep(2000);
    cout << "Processing the '.obj' file...." << endl;
    Sleep(2000);
    objReader.fileReader(inputFile, uniquePoints, triangles);
    Sleep(2000);
    cout << "'.obj' file processed!..." << endl;
    Sleep(1000);
    cout << "Converting to '.txt' file..." << endl;
    Sleep(2000);
    objWriter.fileWriter(outputFile, uniquePoints, triangles);
    cout << "*** END ***" << endl;
return 0;
}