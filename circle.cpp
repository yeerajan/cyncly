#include <iostream>
#include <fstream>
#include <cmath>

const double radius = 1;
const double PI = 3.141592653589793;

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

void writeSTL()
{

    std::ofstream stlFile("circle.stl");

    stlFile << "solid circle\n";
    int N = 100;
    for (int i = 0; i < N; ++i)
    {
        double theta1 = (2 * PI * i) / N;
        double theta2 = (2 * PI * (i + 1)) / N;
        Vertex v1 = {0, 0, 0};
        Vertex v2 = {radius * cos(theta1), radius * sin(theta1), 0};
        Vertex v3 = {radius * cos(theta2), radius * sin(theta2), 0};
        // Write the facet to the STL file
        stlFile << "  facet normal " << 0 << " " << 0 << " " << 1 << "\n";
        stlFile << "    outer loop\n";
        stlFile << "      vertex " << v1.x << " " << v1.y << " " << v1.z << "\n";
        stlFile << "      vertex " << v2.x << " " << v2.y << " " << v2.z << "\n";
        stlFile << "      vertex " << v3.x << " " << v3.y << " " << v3.z << "\n";
        stlFile << "    endloop\n";
        stlFile << "  endfacet\n";
    }

    stlFile << "endsolid circle\n";

    stlFile.close();

    std::cout << "circle.stl file has been generated." << std::endl;
}

int main()
{
    writeSTL();
    return 0;
}