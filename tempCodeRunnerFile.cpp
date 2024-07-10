#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int q;
    cin>>q;
    map<string,int> m;
    string x;
    int y;
    int z;

    while(q!=0)
    {
        cin>>z;
        switch(z)
        {
            case 1: 
                cin>>x;
                cin>>y;
                m.insert(make_pair(x,y));
                break;
            case 2: 
                    cin>>x;
                    m.erase(x);
                    break;
            case 3: 
                    cin>>x;
                    if(m.find(x)!=m.end())
                        cout<<m[x]<<endl;
                    else 
                        cout<<0<<endl;
                    
        }
        q--;    
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
