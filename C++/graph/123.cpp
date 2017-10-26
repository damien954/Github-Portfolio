#include <iostream>
#include <cmath>
#include <string>
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
	void addEdge(int v, int w, int weight); // adds an edge
    void printAllPaths(int s, int d,ostream &stream);
    int findShortestPath(int s, int d);
    int printShortestPath(int parent[], int s, int d);
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
void Graph::addEdge(int v, int w, int weight)
{
        adj[v].push_back(w); // Add w to v’s list.
}
 
// To print the shortest path stored in parent[]
int Graph::printShortestPath(int parent[], int s, int d)
{
    static int level = 0;
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
 
 
    // If we reached root of shortest path tree
    if (parent[s] == -1)
    {
        cout << "Shortest Path between " << loc[ s ]<< " to "
             << loc[ d ]<< " is "  <<loc[ s ]<< "-> ";
        return level;
    }cout<<endl;
 
    printShortestPath(parent, parent[s], d);
 
    level++;
    if (s < V)
        cout << loc[s]<< "-> ";
 
    return level;
}
 
// This function mainly does BFS and prints the
// shortest path from src to dest. It is assumed
// that weight of every edge is 1
int Graph::findShortestPath(int src, int dest)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];
 
    // Initialize parent[] and visited[]
    for (int i = 0; i < 2*V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[src] = true;
    queue.push_back(src);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int s = queue.front();
 
        if (s == dest)
            return printShortestPath(parent, s, dest);
 
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i] = s;
            }
        }
    }
}

void read(ifstream &stream,Graph g, int size)
{
	int M[size][size];
	for(int r=0; r<size;r++)
	{
		for(int c=0; c<size; c++)
		{
			stream>>M[r][c];
		    if(M[r][c]!=0)
		    {
		    	g.addEdge(r,c);
				g.addEdge(r,c,100);
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
void cheapest(Graph g,string a[],int s,int d)
{
	cout << "\nCheapest flight from " << a[s]
         << " to " << a[d] << " is "
         << g.findShortestPath(s, d)*100<<endl;
}
void starter( int &s)
{
	cin>>s;
}
void ender( int &d)
{
	cin>>d;
}

int main()
{
	while (1)
    {
    int size=64;
	int menuChoice;
	int start;
	int destination;
	ifstream in;
	in.open("all.dat");
	Graph g(size);
	read(in,g,size);
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
 

	
	cout <<"[1]Albany [2]Albuquerque [3]Atlanta [4]Austin [5]Baltimore [6]Boston "
	       "[7]Birmingham [8]Burbank [9]Charlotte"<<endl<<endl; 
    cout <<"[10]Chicago [11]Cincinnati [12]Columbus [13]Dallas [14]Denver [15]Detroit "
           "[16]Eugene [17]Ft. Lauderdale [18]Ft. Myers"<<endl<<endl;
    cout <<"[19]Grand Rapids [20]Hartford [21]Houston [22]Indianapolis[23]JACKSON HOLE "
	       "[24]Kansas City [25]Las Vegas [26]Los Angeles"<<endl;
	cout <<"[27]Madison [28]Memphis [29]Miami [30]Milwaukee [31]Minneapolis [32]Monterey "
	       "[33]Nashville [34]New Orleans [35]New York"<<endl<<endl; 
	cout <<"[36]Newark [37]Oakland [38]Oklahoma City [39]Omaha [40]Ontario"
	       "[41]Orange County [42]Orlando [43]Pasco [44]Philadelphia"<<endl<<endl;
	cout <<"[45]Phoenix [46]Portland [47]Raleigh [48]Redmond [49]Reno [50]Sacramento "
	       "[51]Salt Lake City [52]San Antonio"<<endl<<endl; 
	cout <<"[53]San Diego [54]San Francisco [55]San Jose [56]Santa Barbara [57]Settle [58]Spokane"
	       "[59]St. Louis [60]Tampa [61]Tucson"<<endl<<endl; 
	cout <<"[62]Tulsa [63]Washington [64]West Palm Beach\n\n\n\n"<<endl;
	cout << "1. Enter start city\n";
	cout << "2. Enter destination\n";
	cout <<	"3. Find shortest route\n";
	cout <<	"4. Find cheapest route\n";
	cout <<	"5. Find ALL available route\n";
	cout <<	"6. Exit Program.";


	cin >> menuChoice;


	switch (menuChoice)
	{
	case 1:
			
			cout<<"enter the start city: ";
			starter(start);
			  break;
	case 2: 
			cout<<"enter the destination city: ";
			ender(destination); 
			  break;
	case 3: 
	  		cout << "\nCheapest flight from " << loc[start]
         << " to " << loc[destination] << " is "
         << g.findShortestPath(start, destination)*100<<endl;
			  break;
	case 4:
	       cheapest(g,loc,start-1,destination-1); 
			  break;
	case 5:
	      
	       display(g,cout,size);
			  break;
	case 9: 
			cout<<start;
			  break;
	default:  cout << "Invalid Input.";
	}
}
			return 0;
}
