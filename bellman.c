#include<stdio.h>

int bellman(int graph[10][10],int edge[10][2],int E,int V) {
  
  int dist[V],parent[V],src;
  int flag=1,i,j;
  
  for(i=0;i<V;i++) {
    dist[i]=1000;
    parent[i]=-1;
  }

  printf("Enter the source\n");
  scanf("%d",&src);
  dist[src-1]=0;
   
  for(i=0;i<V-1;i++) {      // for every vertex times
     for(j=0;j<E;j++) {     // relax every edge
        int s,d;
        s=edge[j][0];
        d=edge[j][1];
        if(dist[s]+graph[s][d]<dist[d]) {
          dist[d]=dist[s]+graph[s][d];
          parent[d]=s;
        }  
     }
  }
  
  for(j=0;j<E;j++){   // once more relax edery edge to find presense negative cycle
    int s,d;
    s=edge[j][0];
    d=edge[j][1];
    if(dist[s]+graph[s][d]<dist[d])
      flag=0;
  } 
  
  if(flag) {
    for(i=0;i<V;i++)
      printf("Vertex %d->cost=%d parent=%d\n",i+1,dist[i],parent[i]+1);
  }
  return flag;
}


int main() {
  int edge[10][2],graph[10][10],V,k=0,i,j; // k=> count edges
  
  printf("Enter the no of vertices\n");
  scanf("%d",&V);
  
  int weight;
  for(i=0;i<V;i++) {
    for(j=0;j<V;j++) {
      printf("\nEnter graph[%d][%d] weight: \t",i,j);
        scanf("%d",&weight);
        graph[i][j]=weight;
        if(weight!=0) {
          edge[k][0]=i;
          edge[k++][1]=j;    // k++ to increment edge number
        }
     }
   }
  if(bellman(graph,edge,k,V))
    printf("No negative edge cycle\n");
  else
    printf("Negative edge cycle exists\n");
  
  return 0;
}