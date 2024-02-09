#include <iostream>
#include <unordered_map>
#include <windows.h>
#include <string.h>
#include <..\headers\Point3D.h>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\STLWriter.h>
#include <..\headers\STLReader.h>
#include <..\headers\STLtoOBJ.h>

using namespace std;
int main()
{
    STLtoOBJConverter stlToObjConvertor;
    string fromStlFilePath = "..\\resources\\cube.stl";
    string toObjFilePath = "..\\resources\\cube.obj";
    cout << "Reading '.stl' file..." << endl;
    Sleep(2000);
    cout << "Converting to '.obj' file..." << endl;
    Sleep(2000);
    stlToObjConvertor.stlToObjConvertor(fromStlFilePath, toObjFilePath);
    Sleep(2000);
    cout << "Conversion Completed on the given path!" << endl;
    cout << "** END **";
    return 0;
}