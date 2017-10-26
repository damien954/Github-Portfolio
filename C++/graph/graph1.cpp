#include<iostream>
#include <list>
#include <fstream>
using namespace std;
 

class Graph
{
    int V;  
    list<int> *adj; 
    void printAllPathsUtil(int , int , bool [], int [], int &, ostream &);
public:
    Graph(int V);  
    void addEdge(int u, int v);
    void printAllPaths(int s, int d,ostream &stream);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}

void Graph::printAllPaths(int s, int d,ostream &stream)
{
    bool *visited = new bool[V];
    int *path = new int[V];
    int path_index = 0; 
    
    for (int i = 0; i < V; i++)
        visited[i] = false;  
    printAllPathsUtil(s, d, visited, path, path_index, stream);
}
 

void Graph::printAllPathsUtil(int u, int d, bool visited[],int path[], int &path_index, ostream &stream)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    string loc[]={"Albany","Albuquerque","Atlanta","Austin",
			"Baltimore","Boston","Brimingham","Burbank","Charlotte","Chicago",
			"Cincinatti","Colombus","Dallas","Denver","Detroit","Eugene",
			"Ft.Lauderdale","Ft.Myers","Grand Rapids","Hartford","Houston",
			"Indianapolis","JACKSON HOLE","Kansas City","Las Vegas","Los Angeles",
			"Madison","Memphis","Miami","Milwaukea","Minneapolis","Monterey","Nashville",
			"New Orleans","New York","Newark","Oakland","Oklahoma City","Omaha","Ontario",
			"Orange County","Orlando","Pasco","Philadelphia","Phonenix","Portland","Raleigh",
			"Redmond","Reno","Sacramento","Salt Lake City","San Antonio","San Diego",
			"San Francisco","San Jose","Santa Barbara","Settle","spokane","St.Louis",
			"Tampa","Tucson","Tulsa","Washington","West Plam Beach"};
 
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            stream << loc[path[i]]<< "-> ";
        stream << endl;
    }
    else 
    {
       
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index,stream);
    }
 

    path_index--;
    visited[u] = false;
}
void read(ifstream &stream,Graph g, int size)
{

	int M[size][size];
	for(int r=0; r<size;r++)
	{
			for(int c=0; c<size; c++)
			{
				stream>>M[r][c];
				if(M[r][c]==1)
				{
					g.addEdge(c,r);
				}
			}
	
	}
	
}
void display(Graph g,ostream &stream, int size)
{
	for(int s=0; s<size; s++)
  	{
  		
  		for(int d=0; d<size; d++)
  		{
  		
  			g.printAllPaths(s,d,stream);  		
	  	}
  	}
}
int main()
{
	ifstream Ain,Din,Uin;
	Ain.open("American.txt");
	Din.open("Delta.txt");
	Uin.open("United.txt");
	ofstream Aout,Dout,Uout;
	Aout.open("American_Output.txt");
	Dout.open("Delta_Output.txt");
	Uout.open("United_Output.txt");
	
	ifstream inF;
	Ain.open("data.txt");
	ofstream outF;
	outF.open("data_Output.txt");

	int size=64;
	int r_size=size;
	int c_size=size;
	int s,d;
	Graph American(size),Delta(size),United(size);
	
	read(Ain,American,size);
	display(American,Aout,size);
	
	read(Din,Delta,size);
	display(Delta,Dout,size);
	
	read(Uin,United,size);
	display(United,Uout,size);
	
	
   
 
    return 0;
}
