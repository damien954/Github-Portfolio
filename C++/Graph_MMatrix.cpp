#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
 
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
}; 
struct AdjList
{
    struct AdjListNode *head;
};
class Graph
{
    private:
        int V;
        struct AdjList* array;
    public:
        Graph(int V)
        {
            this->V = V;
            array = new AdjList [V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        } 
        AdjListNode* newAdjListNode(int dest)
        {
            AdjListNode* newNode = new AdjListNode;
            newNode->dest = dest;
            newNode->next = NULL;
            return newNode;
        } 
        void addEdge(int src, int dest)
        {
            AdjListNode* newNode = newAdjListNode(dest);
            newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
        }
        void printGraph(ostream &stream)
        {
            int v;
            int dest;
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
			"Tampa","Tucson","Tulsa","Washington","West Plam Beach"

};
            for (v = 0; v < V; ++v)
            {
                AdjListNode* pCrawl = array[v].head;
                int count=0;
                stream<<loc[v]<<" ";
                while (pCrawl)
                {
                	dest=pCrawl->dest;
                    stream<<"-> "<<loc[dest];
                    count++;
                    if(count%10==0)
                    {
                    	stream<<endl;
					}
                    pCrawl = pCrawl->next;
                }
                stream<<endl<<endl;
            }
        }
};


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
	int size=64;
	int r_size=size;
	int c_size=size;
	Graph American(size),Delta(size),United(size),United2(size);
	
	int M[r_size][c_size];
		for(int r=0; r<r_size;r++)
		{
			for(int c=0; c<c_size; c++)
			{
				Ain>>M[r][c];
			}
	
		}
	
		for(int c=0; c<c_size; c++)
		{
			int r=12;
			if(M[r][c]==1)
			{
				American.addEdge(r,c);
			}
		}
	American.printGraph(Aout);
	for(int r=0; r<r_size;r++)
	{
		for(int c=0; c<c_size; c++)
		{
			Din>>M[r][c];
	
		
		}
	
	}
    	for(int c=0; c<c_size; c++)
		{
			int r=50;
			if(M[r][c]==1)
			{
				Delta.addEdge(r,c);
			}
		}
    Delta.printGraph(Dout);
    for(int r=0; r<r_size;r++)
	{
		for(int c=0; c<c_size; c++)
		{
			Uin>>M[r][c];
	
		
		}
	
	}
    	for(int c=0; c<c_size; c++)
		{
			
			if(M[9][c]==1||M[13][c]==1)
			{
				United.addEdge(9,c);
				United2.addEdge(13,c);
			}
		}
    United.printGraph(Uout);
    United2.printGraph(Uout);
 
    return 0;
}

