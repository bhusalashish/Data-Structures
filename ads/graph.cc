#include<iostream>
using namespace std;
#include<queue>

typedef struct graph{
	int d;
	struct graph *next;
}graphtype;

void insertdirected(graphtype* source[], int s, int d){
	// graphtype *p= new graphtype;
	graphtype *p = (graphtype*)malloc(sizeof(graphtype));
	if(!p) return;
	p->d = d;
	p->next = source[s];
	source[s] = p;
}

void insertundirected(graphtype* source[], int s, int d){
	// graphtype *p= new graphtype;
	graphtype *p = (graphtype*)malloc(sizeof(graphtype));
	if(!p) return;
	p->d = d;
	p->next = source[s];
	source[s] = p;

	graphtype *q = new graphtype;
	q->d = s;
	q->next = source[d];
	source[d] = q;
}

void display(graphtype* source[], int v){
	for(int i=0; i<v; ++i){
		cout<<i<<" is connected with:- ";
		graphtype *temp = source[i];
		while(temp){
			cout<<temp->d<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}

void bfs(graphtype* source[], int v, int start){
	queue <int> q;
	bool visited [v] = {};
	cout<<start<<endl;
	q.push(start);
	visited[start]=true;
	graphtype *temp=NULL;
	while(!q.empty()){
		temp = source[q.front()];
		while(temp){
			if(!visited[temp->d]){
				cout<<temp->d<<endl;
				visited[temp->d] = true;
				q.push(temp->d);
			}
			temp = temp->next;
		}
		q.pop();
	}
	
}

void dfs(graphtype* source[], bool visited[], int v){
	if(visited[v]==true) return;

	cout<<v<<endl;
	visited[v]=true;
	graphtype *temp = source[v];
	while(temp){
		dfs(source, visited, temp->d);
		temp = temp->next;
	}

}

int main(){
	int v,e;
	cin>>v>>e;
	graphtype *source[v] = {};
	int s, d;
	for(int i=0; i<e; ++i){
		cin>>s>>d;
		insertdirected(source, s, d);
	}
	display(source, v);
	cout<<"Bredth First Search:-\n";
	bfs(source,v, 0);

	bool visited[v] = {};
	cout<<"Depth First Search:-\n";
	dfs(source, visited, 0);

}