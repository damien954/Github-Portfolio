#include <iostream>
#include <string>

using namespace std;

const int NULL_EDGE = 0;

template <class VertexType>
class Graph
{
      public:
             Graph();
             Graph(int maxV);
             ~Graph();
             void addVertex(VertexType);
             void addEdge(VertexType, VertexType, int);
             int getWeight(VertexType, VertexType);
             int getNumVertices();
             VertexType getVertex(int);
             
      private:
              int numVertices;
              int maxVertices;
              VertexType* vertices;
              int edges[50][50];
              };

template<class VertexType>           
Graph <VertexType>::Graph()
{
      numVertices = 0;
      maxVertices - 50;
      vertices = new VertexType[50];
      }
      
template<class VertexType>
int indexIs(VertexType* vertices, VertexType vertex)
{
    int i = 0;
    while (vertex != vertices[i]){i++; cout<<vertex<<","<<vertices[i]<<endl;}

    return i;
}
      
template<class VertexType>
Graph<VertexType>::Graph(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    }
      
template<class VertexType>
Graph<VertexType>::~Graph()
{
    delete [] vertices;
}

template<class VertexType>
void Graph<VertexType>::addVertex(VertexType vertex)
{
     vertices[numVertices] = vertex;
     for (int i = 0; i < numVertices; i++)
     {
         edges[numVertices][i] = NULL_EDGE;
         edges[i][numVertices] = NULL_EDGE;
     }
     numVertices++;
}

template<class VertexType>
void Graph<VertexType>::addEdge(VertexType fromVertex, VertexType toVertex, int weight)
{
     char row;
     char column;
     row = indexIs(vertices, fromVertex);
     column = indexIs(vertices, toVertex);
     edges[row][column] = weight;
}

template<class VertexType>
int Graph<VertexType>::getWeight(VertexType fromVertex, VertexType toVertex)
{
     int row;
     int column;
     row = indexIs(vertices, fromVertex);
     column = indexIs(vertices, toVertex);
     return edges[row][column];
}

template<class VertexType>
int Graph<VertexType>::getNumVertices()
{
     return numVertices;
}

template<class VertexType>
VertexType Graph<VertexType>::getVertex(int i)
{
     return vertices[i];
};

int main() {
    Graph<string> g;
    g.addVertex("Austin");
    g.addVertex("Dallas");
    g.addVertex("Denver");
    g.addVertex("Chicago");
    g.addVertex("Washington");
    g.addVertex("Atlanta");
    g.addVertex("Houston");
    g.addEdge("Austin", "Dallas", 200);
    g.addEdge("Dallas", "Austin", 200);
    g.addEdge("Austin", "Houston", 160);
    g.addEdge("Houston", "Austin", 160);
    g.addEdge("Dallas", "Denver", 780);
    g.addEdge("Denver", "Dallas", 780);
    g.addEdge("Dallas", "Chicago", 900);
    g.addEdge("Chicago", "Dallas", 900);
    g.addEdge("Dallas", "DC", 1300);
    g.addEdge("DC", "Dallas", 1300);
    g.addEdge("Denver", "Chicago", 1000);
    g.addEdge("Chicago", "Denver", 1000);
    g.addEdge("Denver", "Atlanta", 1400);
    g.addEdge("Atlanta", "Denver", 1400);
    g.addEdge("Atlanta", "Houston", 800);
    g.addEdge("Houston", "Atlanta", 800);
    cout << "From/To";
    int i;
    cout << "\t" << g.getVertex(0) << "\t" <<
    g.getVertex(7) << endl;
    string city;
    city = g.getVertex(0);
    cout << city << "\t" <<
    g.getWeight(city,g.getVertex(0)) << "\t" <<
    g.getWeight(city,g.getVertex(7)) << endl;
    city = g.getVertex(1);
    cout << city << "\t" <<
    g.getWeight(city,g.getVertex(0)) << "\t" <<
    g.getWeight(city,g.getVertex(1)) << endl;
  
    system("pause");
    return 0;
}

