#include <..\headers\Triangulation.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

Triangulation *Triangulation::triangulation=nullptr;

Triangulation* Triangulation::getInstance()
{
    if(triangulation==nullptr) triangulation=new Triangulation();
    return triangulation;
}
vector<Triangle> Triangulation::getTriangles()
{
    return this->mTraingles;
}
vector<Point3D>  Triangulation::getPoints()
{
    return this->mUnique3DPoints;
}
Triangulation::Triangulation()
{
}