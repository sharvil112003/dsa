#include <bits/stdc++.h>
using namespace std;

#define V 5
#define Popsize 10

vector<int> ans;
int cost = INT_MAX;

struct path{
    vector<int> gnome;
    int fitness;
};

int rand_num(int s, int e){
    int range = e-s;
    return s + (rand() % range);
}

bool isRepeat(vector<int> arr, int x){
    for(int i: arr){
        if(i == x) return true;
    }
    return false;
}

bool comp(struct path p1, struct path p2){
    return p1.fitness < p2.fitness;
}

vector<int> mutate(vector<int> arr){
    int a = rand_num(1,V);
    int b = rand_num(1,V);
    while(a == b) b = rand_num(1,V);
    
    swap(arr[a],arr[b]);
    return arr;
}

vector<int> create(){
    vector<int> arr;
    arr.push_back(0);
    while(true){
        if(arr.size() == V){
            arr.push_back(0);
            break;
        }
        int x = rand_num(1,V);
        if(!isRepeat(arr,x)) arr.push_back(x);
    }
    
    return arr;
}

int find_fit(vector<int> arr){
    
    int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
                    { 2, 0, 4, 8, INT_MAX },
                    { INT_MAX, 4, 0, 3, 3 },
                    { 12, 8, 3, 0, 10 },
                    { 5, INT_MAX, 3, 10, 0 } };
                    
    int f = 0;
    for(int i=0;i<arr.size()-1;i++){
        if(map[arr[i]][arr[i+1]] == INT_MAX) return INT_MAX;
        f += map[arr[i]][arr[i+1]];
    }
    
    return f;
}

void print(vector<int> arr){
    for(int i: arr) cout<<i;
    cout<<"    ";
}

void tsp(int map[V][V]){
    
    vector<struct path> popul;
    struct path tempg;
    
    for(int i=0;i<Popsize;i++){
        tempg.gnome = create();
        tempg.fitness = find_fit(tempg.gnome);
        if(tempg.fitness < cost){
            cost = tempg.fitness;
            ans = tempg.gnome;
        }
        popul.push_back(tempg);
    }
    
    cout<<"Initial\n"<<"Gnome   Fitness\n";
    for(int i=0;i<Popsize;i++){
        print(popul[i].gnome);
        cout<<popul[i].fitness<<endl;
    }
    
    int generation = 1;
    while(generation <= 5){
        sort(popul.begin(),popul.end(),comp);
        vector<struct path> new_popul;
        
        for(int i=0;i<Popsize;i++){
            struct path new_gnome;
            new_gnome.gnome = mutate(popul[i].gnome);
            new_gnome.fitness = find_fit(new_gnome.gnome);
            if(new_gnome.fitness < cost){
                cost = new_gnome.fitness;
                ans = new_gnome.gnome;
            }
            new_popul.push_back(new_gnome);
        }
        
        cout<<"\n\nGeneration: "<<generation<<endl;
        popul = new_popul;
        for(int i=0;i<Popsize;i++){
            print(popul[i].gnome);
            cout<<popul[i].fitness<<endl;
        }
        generation++;
    }
    
}

int main()
{
    int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },
                    { 2, 0, 4, 8, INT_MAX },
                    { INT_MAX, 4, 0, 3, 3 },
                    { 12, 8, 3, 0, 10 },
                    { 5, INT_MAX, 3, 10, 0 } };
    
    
    tsp(map);
    
    cout<<"\nPath : ";
    for(int i:ans){
        cout<<i;
    }
    cout<<"\nCost: "<<cost;
    return 0;
}

//Time: n^2 
//space : Popsize * V
