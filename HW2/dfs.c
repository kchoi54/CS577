#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRAPH 10
#define MAX_SIZE 50
#define MAX_NAME 5

struct Graph
{
    int adj[MAX_SIZE][MAX_SIZE];
    char node_name[MAX_SIZE][MAX_NAME];
    int size;
};

int main() 
{
    int numGraph, i, j, k;
    int name_i, name_j, buffer_ind, temp; //temp vars
    char buffer[MAX_SIZE][MAX_SIZE];
    char name_buffer[MAX_NAME];
    struct Graph graph[MAX_GRAPH];


    //# of instance
    scanf("%d", &numGraph);

    for(i=0; i<numGraph; i++)
    {
        //# of nodes
        scanf("%d", &graph[i].size);

        //flush \n
        fgets(buffer[0],2,stdin);

        //read line
        for(j=0; j<graph[i].size; j++)
        { 
            fgets(buffer[j], MAX_SIZE, stdin); 

            for(buffer_ind=0; buffer[j][buffer_ind]!= ' ' && buffer[j][buffer_ind]!= '\n'; buffer_ind++) //extract node_name
            { 
                graph[i].node_name[j][buffer_ind+1] = buffer[j][buffer_ind]; 
            }
            buffer[j][0] = (char) buffer_ind+1; //temp store end index of node name
            graph[i].node_name[j][0] = (char) buffer_ind; //name length
        }

        for(j=0; j<graph[i].size; j++)
        {
            name_i = 0;
            buffer_ind = (int) buffer[j][0];
            while(buffer[j][buffer_ind] != '\n' && buffer[j][buffer_ind] != 0)
            {
                for(temp = 0; buffer[j][buffer_ind+temp]!= ' ' && buffer[j][buffer_ind+temp]!= '\n'; temp++) //extract adj node name
                { name_buffer[temp+1] = buffer[j][buffer_ind+temp]; }
                
                name_buffer[0] = (char) temp; //name length
                buffer_ind += temp+1; //next adj node

                for(temp=0; temp < MAX_SIZE; temp++)
                {
                    if(name_buffer[0] == graph[i].node_name[name_i+temp][0]) //if size is same
                    {
                        name_j = 1;
                        printf("%s\n", &name_buffer[1]);
                        while(name_buffer[name_j] == graph[i].node_name[name_i+temp][name_j] && name_j++ < name_buffer[0]);
                        
                        if() //if size match add link to adj matrx
                    }
                }
            }
        }

        // //print
        // for(i=0; i < numGraph; i++) 
        // {
        //     for(j=0; j<graph[i].size; j++)
        //     { printf("%s\n", &graph[i].node_name[j][1]); }
        //     printf("\n");
        // }
    }

    return 0;
}