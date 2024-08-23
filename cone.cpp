#include <iostream>
#include <fstream>
#include <cmath>

const double PI = 3.141592653589793;
const double radius = 1.00;
const double height = 5;
int division = 100;

struct Vertex
{
    double x, y, z;
};

Vertex findNormal(const Vertex &v1, const Vertex &v2, const Vertex &v3)
{
    // Calculate normal
    double normalX = (v2.y - v1.y) * (v3.z - v1.z) - (v2.z - v1.z) * (v3.y - v1.y);
    double normalY = (v2.z - v1.z) * (v3.x - v1.x) - (v2.x - v1.x) * (v3.z - v1.z);
    double normalZ = (v2.x - v1.x) * (v3.y - v1.y) - (v2.y - v1.y) * (v3.x - v1.x);

    // Normalize the normal
    double length = std::sqrt(normalX * normalX + normalY * normalY + normalZ * normalZ);
    normalX /= length;
    normalY /= length;
    normalZ /= length;

    Vertex normal = {normalX, normalY, normalZ};
    return normal;
}

void writeFacet(std::ofstream &stlFile, const Vertex &v1, const Vertex &v2, const Vertex &v3)
{
    Vertex normal = findNormal(v1, v2, v3);

    // Write the facet to the STL file
    stlFile << "  facet normal " << normal.x << " " << normal.y << " " << normal.z << "\n";
    stlFile << "    outer loop\n";
    stlFile << "      vertex " << v1.x << " " << v1.y << " " << v1.z << "\n";
    stlFile << "      vertex " << v2.x << " " << v2.y << " " << v2.z << "\n";
    stlFile << "      vertex " << v3.x << " " << v3.y << " " << v3.z << "\n";
    stlFile << "    endloop\n";
    stlFile << "  endfacet\n";
}

void writeCircleDown(std::ofstream &stlFile, double zed)
{
    
    for (int i = 0; i < division; ++i)
    {
        double theta1 = (2 * PI * i) / division;
        double theta2 = (2 * PI * (i + 1)) / division;
        Vertex v1 = {0, 0, zed};
        Vertex v2 = {radius * cos(theta1), radius * sin(theta1), zed};
        Vertex v3 = {radius * cos(theta2), radius * sin(theta2), zed};
        // Write the facet to the STL file
        Vertex normal = {0, 0, -1};
        stlFile << "  facet normal " << normal.x << " " << normal.y << " " << normal.z << "\n";
        stlFile << "    outer loop\n";
        stlFile << "      vertex " << v3.x << " " << v3.y << " " << v3.z << "\n";
        stlFile << "      vertex " << v2.x << " " << v2.y << " " << v2.z << "\n";
        stlFile << "      vertex " << v1.x << " " << v1.y << " " << v1.z << "\n";
        stlFile << "    endloop\n";
        stlFile << "  endfacet\n";
    }
}

void writeSTL()
{
    // Open the STL file
    std::ofstream stlFile("cone.stl");

    stlFile << "solid cone\n";
    writeCircleDown(stlFile, 0);
    for (int i = 0; i < division; ++i){
        double theta1 = 2 * PI * i / division;
        double theta2 = 2 * PI * (i + 1) / division;

        // Calculate the vertices of the first triangle
        Vertex v1 = {radius * std::cos(theta1),
                    radius * std::sin(theta1),
                    0};

        Vertex v2 = {radius * std::cos(theta2),
                    radius * std::sin(theta2),
                    0};

        Vertex v3 = {0, 0, height};
        writeFacet(stlFile, v1, v2, v3);
    }
    stlFile << "endsolid cone\n";

    stlFile.close();

    std::cout << "cone.stl file has been generated." << std::endl;
}

int main()
{
    writeSTL();
    return 0;
}
