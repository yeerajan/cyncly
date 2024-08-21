#include <iostream>
#include <fstream>
#include <cmath>

const double PI = 3.141592653589793;
const double height = 5.00;
const double radius = 1.00;

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

int main()
{
    // Parameters for the sphere
    double radius = 1.0;
    int N = 25; // Number of latitude segments
    int M = 25; // Number of longitude segments

    // Open the STL file
    std::ofstream stlFile("cylinder.stl");

    if (!stlFile)
    {
        std::cerr << "Unable to open file";
        return 1;
    }

    stlFile << "solid cylinder\n";

    for (int i = 0; i < N; ++i)
    {
        double theta1 = 2 * PI * i / N;
        double theta2 = 2 * PI * (i + 1) / N;

        for (int j = 0; j < M; ++j)
        {
            double height1 = height * j / M;
            double height2 = height * (j + 1) / M;

            // Calculate the vertices of the first triangle
            Vertex v1 = {radius * std::cos(theta1),
                         radius * std::sin(theta1),
                         height1};

            Vertex v2 = {radius * std::cos(theta2),
                         radius * std::sin(theta2),
                         height1};

            Vertex v3 = {radius * std::cos(theta2),
                         radius * std::sin(theta2),
                         height2};
            // Calculate the vertices of the second triangle
            Vertex v4 = {radius * std::cos(theta1),
                         radius * std::sin(theta1),
                         height2};

            // Write the two triangles
            writeFacet(stlFile, v1, v2, v3);
            writeFacet(stlFile, v1, v3, v4);
        }
    }
    stlFile << "endsolid sphere\n";

    stlFile.close();

    std::cout << "cylinder.stl file has been generated." << std::endl;

    return 0;
}
