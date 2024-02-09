#include <iostream>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <windows.h>
#include <string.h>
#include <..\headers\Point3D.h>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\STLWriter.h>
#include <..\headers\STLReader.h>

using namespace std;
int main()
{
    string inputFile = "..\\stlFiles\\cube.stl";
    string outputFile = "..\\outputFile\\file.txt";

    STLReader *stlReader=STLReader::getInstance();
    STLWriter *stlWriter=STLWriter::getInstance();
    Triangulation *triangulation=Triangulation::getInstance();


    cout<<"B : "<<sizeof(triangulation)<<endl;
    cout<<"A : "<<sizeof(*triangulation)<<endl;


    unordered_map<int, Point3D> mapping;
    vector<Point3D> uniquePoints;
    vector<Triangle> uniqueTriangles;

    // cout << "*** STARTED ***" << endl;
    // //Sleep(2000);
    // cout << "Processing the '.stl' file...." << endl;
    // //Sleep(2000);
    cout<<"t : "<<unsigned(triangulation)<<endl;
    stlReader->fileReader(inputFile,triangulation , mapping);
    cout<<"**"<<triangulation->getPoints().size()<<endl;
    cout<<"Bx : "<<sizeof(triangulation)<<endl;
    cout<<"Ax : "<<sizeof(*triangulation)<<endl;

    //Sleep(2000);
    // cout << "'.stl' file processed!..." << endl;
    // cout << "Converting to '.txt' file..." << endl;
    // //Sleep(3000);
    stlWriter->fileWriter(outputFile,triangulation, mapping);
    cout << "*** END ***" << endl;
    return 0;
    }