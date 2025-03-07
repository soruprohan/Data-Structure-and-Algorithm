#include <bits/stdc++.h>
using namespace std;

int mdsq(int key){
    key *= key;
    vector<int> digits;
    while(key){
        digits.push_back(key%10);
        key /= 10;
    }
    int n = digits.size();
    if(n<3)
        return key;
    int mid = n/2;
    int ans = digits[mid + 1] * 100 + digits[mid] * 10 + digits[mid - 1];
    return ans;
}

struct node{
    int key;
    int cnt;
    node *next, *prev;
    node(int key){
        this->key = key;
        cnt = 1;
        next = prev = NULL;
    }
};

class hashtable{
    node **table;
    public:
    hashtable(){
        table = new node*[1000];
        for(int i = 0; i < 1000; i++)
            table[i] = NULL;
    }
    void insert(int key){
        int index = mdsq(key);
        if(table[index] == NULL){
            table[index] = new node(key);
        }
        else{
            node *tmp = table[index];
            while(tmp->next != NULL){
                if(tmp->key == key){
                    tmp->cnt++;
                    return;
                }
                tmp = tmp->next;
            }
            if(tmp->key == key){
                tmp->cnt++;
                return;
            }
            tmp->next = new node(key);
            tmp->next->prev = tmp;
        }
    }
    void del(int key){
        int index = mdsq(key);
        if(table[index] == NULL){
            return;
        }
        node *tmp = table[index];
        while(tmp != NULL){
            if(tmp->key == key){
                if(tmp->cnt > 1){
                    tmp->cnt--;
                    return;
                }
                if(tmp->prev == NULL){
                    table[index] = tmp->next;
                }
                else{
                    tmp->prev->next = tmp->next;
                }
                if(tmp->next != NULL){
                    tmp->next->prev = tmp->prev;
                }
                delete tmp;
                return;
            }
            tmp = tmp->next;
        }
    }
    int showcount(int key){
        int index = mdsq(key);
        if(table[index] == NULL){
            return 0;
        }
        node *tmp = table[index];
        while(tmp != NULL){
            if(tmp->key == key){
                return tmp->cnt;
            }
            tmp = tmp->next;
        }
        return 0;
    }
};

int main() {

    hashtable hsh;
    hsh.insert(5);
    hsh.insert(121);
    hsh.insert(2212);
    hsh.insert(121);
    cout << hsh.showcount(121) << endl;
    hsh.del(121);
    cout << hsh.showcount(121) << endl;

    return 0;
}