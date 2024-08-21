#include <iostream>
#include <fstream>

int main() {
    // Open a file in write mode
    std::ofstream stlFile("cube.stl");

    // Check if the file is opened successfully
    if (!stlFile) {
        std::cerr << "Unable to open file";
        return 1; // Return an error code
    }

    // Write the STL content
    stlFile << "solid cube\n";
    
    stlFile << "  facet normal 0 0 -1\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 1 0 0\n"
            << "      vertex 1 1 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 0 -1\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 1 1 0\n"
            << "      vertex 0 1 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal -1 0 0\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 0 1 0\n"
            << "      vertex 0 1 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal -1 0 0\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 0 1 1\n"
            << "      vertex 0 0 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 -1 0\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 0 0 1\n"
            << "      vertex 1 0 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 -1 0\n"
            << "    outer loop\n"
            << "      vertex 0 0 0\n"
            << "      vertex 1 0 1\n"
            << "      vertex 1 0 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 0 1\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 0 1 1\n"
            << "      vertex 0 0 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 0 1\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 0 0 1\n"
            << "      vertex 1 0 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 1 0 0\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 1 0 0\n"
            << "      vertex 1 0 1\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 1 0 0\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 1 1 0\n"
            << "      vertex 1 0 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 1 0\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 0 1 0\n"
            << "      vertex 1 1 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "  facet normal 0 1 0\n"
            << "    outer loop\n"
            << "      vertex 1 1 1\n"
            << "      vertex 0 1 1\n"
            << "      vertex 0 1 0\n"
            << "    endloop\n"
            << "  endfacet\n";

    stlFile << "endsolid\n";

    // Close the file
    stlFile.close();

    std::cout << "cube.stl file has been generated." << std::endl;

    return 0;
}
