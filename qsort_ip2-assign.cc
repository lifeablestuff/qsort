#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

/*
 * In-Place quicksort written by Robert Arkiletian 2024
 * created with inplace algorithm from video
https://www.youtube.com/watch?v=MZaf_9IZCrc
*/

int randInt(int low, int high){
    //old method random number requires srand(...) seeding
    //return  low + int( (high-low + 1.0)*rand() / (RAND_MAX+1.0));

    //newer C++11 random numbers requires #include <random>
    // use static for lines which should only be run once
    static random_device rd; //seed
    static mt19937 rng( rd() ); //rand num generator with seed arg
    uniform_int_distribution<int> dist(low, high); //specify range
    return dist(rng);
}

void printvec(const vector <int> &v){
    cout<<endl;
    for (uint x=0; x<v.size();x++)
    {
        cout<<v[x]<<" ";
    }
    cout<<endl;
}

void printvec(const vector <int> &v, int a, int b){
    cout<<endl;
    for (int x=a; x<=b;x++)
    {
        cout<<v[x]<<" ";
    }
    cout<<endl;
}

void swap(vector <int> &v, int x, int y){
    int temp(v[x]);
    v[x]=v[y];
    v[y]=temp;
}


void quicksort(vector <int> &v, int a, int b){
//comlete this function
    if (a>=b){
        return;
    }
    int piv = v[b];
    int i = a-1;
    int j;
    for (j=a;j<b;j++){
        if (v[j]<piv){
            i++;
            swap(v,i,j);
        }
    }
    swap(v,b,i+1);
    quicksort(v,a,i);
    quicksort(v,i+2,b);
}
        
void save_rand_vec(string fname, int siz, int start, int end){
    ofstream f;
    f.open(fname);
    for (long x=0 ; x< siz; x++)
        f<<randInt(start, end)<<'\n';
    f.close();
}

vector <int> read_vec(string fname){
    vector <int> v;
    int x;
    ifstream f;
    f.open(fname);
    while ( f >> x )
    {
        v.push_back(x);
    }
    return v;
}


int main(){
    vector <int> v={6,3,8,5,7,2,4,1};
    //vector <int> v;
    //save_rand_vec("randata", 12345678, 0, 87654321);
    //v=read_vec("randata");
    printvec(v);
    quicksort(v,0,v.size()-1);
    printvec(v);
    return 0;
}

