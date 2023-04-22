#include<iostream>
#include<iomanip>
#define v 4
#define INF 999999
using namespace std;
void print(int dist[v][v]){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]>=(INF%10)){
                cout<<"INF       ";
            }
            else{
                cout<<dist[i][j]<<"         ";
            }
        }
        cout<<"\n";
    }

}
void floydWarshall(int graph[v][v]){
    int dist[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }

    }
    print(dist);
}
int main(){
    cout<<"Input"<<endl;
    int graph[v][v]={{0,   5,  INF, 10},
                    {INF, 0,   3, INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0}
                    };
    print(graph);

    cout<<"All pair Shortest path is "<<endl;
    floydWarshall(graph);
    return 0;
}