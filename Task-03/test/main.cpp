#include <iostream>
#include <windows.h>
#include <string.h>
#include <..\headers\Point3D.h>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\OBJWriter.h>
#include <..\headers\OBJReader.h>
#include <..\headers\OBJToSTL.h>

using namespace std;
int main()
{
    OBJtoSTLConverter objToStlConvertor;
    string fromObjFilePath = "..\\resources\\cube.obj";
    string toStlFilePath = "..\\resources\\cube.stl";
    cout << "Reading '.obj' file..." << endl;
    Sleep(2000);
    cout << "Converting to '.stl' file..." << endl;
    Sleep(2000);
    objToStlConvertor.objToStlConvertor(fromObjFilePath, toStlFilePath);
    Sleep(2000);
    cout << "** DONE **" << endl;
    cout << "Conversion Completed on the given path!" << endl;
    return 0;
}