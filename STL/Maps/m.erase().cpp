#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int,string> m;

    for(int i=0; i<4; i++){
        string s;
        cout<<"Enter string:";
        cin>>s;
        m[i]=s;
    }
    m[5]="Rohan"; //4 key insert kori nai,taile key 3 er porer iterator direct 5 e jabe.4 is ignored completely
    m.insert({6,"sorup"});

    cout<<"Key value pairs of the map are:"<<endl;

    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    m.erase(2);
    m.erase(8); //deleting using key,ekhane non existing key use kora jabe,taile ager output tai pabo.kisui delete hobe na

    auto it=m.find(7); //deleting using iterator
    if(it!=m.end())  //Ei if condition use na korle error ashbe jodi iterator ta map e exist na kore,key diye korle ei issue nai
        m.erase(it);

    cout<<"\nafter deleting some elements :"<<endl;
    for(auto it=m.begin(); it!=m.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }


}
