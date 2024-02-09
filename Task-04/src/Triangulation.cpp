#include <..\headers\Triangulation.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

Triangulation::Triangulation()
{

}
Triangulation::~Triangulation()
{

}
vector<Triangle>& Triangulation::getTriangles()
{
    return this->mTraingles;
}
vector<Point3D>& Triangulation::getPoints()
{
    return this->mUnique3DPoints;
}