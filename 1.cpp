#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

const int maxVertices = 1000;
const int maxTexCoords = 1000;
const int maxNormals = 1000;
const int maxFaces = 1000;

class Vertex {
public:
    float x, y, z;
};

class TextureCoord {
public:
    float u, v;
};

class Normal {
public:
    float nx, ny, nz;
};

class Face {
public:
    int vertexIndices[3];
    int textureIndices[3];
    int normalIndices[3];
};

std::array<Vertex, maxVertices> vertices;
std::array<TextureCoord, maxTexCoords> texCoords;
std::array<Normal, maxNormals> normals;
std::array<Face, maxFaces> faces;

int vertexCount = 0;
int texCoordCount = 0;
int normalCount = 0;
int faceCount = 0;

int main() {
    std::ifstream objFile("your_file.obj");
    if (!objFile) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::string prefix;
    while (objFile >> prefix) {
        if (prefix == "v") {
            if (vertexCount < maxVertices) {
                objFile >> vertices[vertexCount].x >> vertices[vertexCount].y >> vertices[vertexCount].z;
                vertexCount++;
            }
        } else if (prefix == "vt") {
            if (texCoordCount < maxTexCoords) {
                objFile >> texCoords[texCoordCount].u >> texCoords[texCoordCount].v;
                texCoordCount++;
            }
        } else if (prefix == "vn") {
            if (normalCount < maxNormals) {
                objFile >> normals[normalCount].nx >> normals[normalCount].ny >> normals[normalCount].nz;
                normalCount++;
            }
        } else if (prefix == "f") {
            if (faceCount < maxFaces) {
                for (int i = 0; i < 3; i++) {
                    objFile >> faces[faceCount].vertexIndices[i] >> faces[faceCount].textureIndices[i] >> faces[faceCount].normalIndices[i];
                }
                faceCount++;
            }
        }
        // Прочитать остаток строки, чтобы перейти к следующей строке
        std::getline(objFile, line);
    }

    // Теперь у вас есть данные о вершинах (v), текстурных координатах (vt), нормалях (vn)
    // и полигонах (f) в соответствующих массивах.

    // Используйте эти данные для рендеринга или другой обработки.

    return 0;
}
