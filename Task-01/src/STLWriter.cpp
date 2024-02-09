#include <vector>
#include <..\headers\Triangle.h>
#include <..\headers\Triangulation.h>
#include <..\headers\Point3D.h>
#include <..\headers\STLWriter.h>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

STLWriter* STLWriter::getInstance()
{
    if(stlWriter==nullptr) stlWriter=new STLWriter();
    return stlWriter;
}

STLWriter *STLWriter::stlWriter=nullptr;

STLWriter::STLWriter()
{

}


void STLWriter::fileWriter(string filePath, Triangulation *triangulation, unordered_map<int,Point3D> &mapping)
{

    ofstream outFile(filePath);
    if (!outFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    
    vector<Triangle> triangles=triangulation->getTriangles();
    for(auto iterator:triangles)
    {
        auto i1=mapping[iterator.getVertex1()];
        auto i2=mapping[iterator.getVertex1()];
        auto i3=mapping[iterator.getVertex1()];

        outFile <<  i1.getMX() << " " << i1.getMY() << " " << i1.getMZ() << endl;
        outFile <<  i2.getMX() << " " << i2.getMY() << " " << i2.getMZ() << endl;
        outFile <<  i3.getMX() << " " << i3.getMY() << " " << i3.getMZ() << endl;
    }
    outFile.close();
}
