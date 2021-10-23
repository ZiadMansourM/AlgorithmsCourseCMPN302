#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
    float x, y, z;
};

ostream& operator<<(ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    vector<Vertex> vertices;
    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 4, 5, 6 });

    for (int i=0; i<vertices.size(); i++)
        cout << vertices[i] << endl;

    for (const Vertex& v: vertices)
        cout << v << endl;
    return 0;
}