#include <iostream>
#include <vector>
using namespace std;

struct W{
    int value;
    W* left = nullptr;
    W* right = nullptr;

    W(int v) : value{v} {}
};

void insert(W* x, int n){
    if(n >= x->value){
        if(x->right == nullptr){
            x->right = new W(n);
        } else{
            insert(x->right, n);
        }
    } else{
        if(x->left == nullptr){
            x->left = new W(n);
        } else{
            insert(x->left, n);
        }
    }
    
}

int main(){
    W* x = new W(5);

    insert(x, 2);
    insert(x, 3);
    insert(x, 8);
    insert(x, 7);
    insert(x, 4);
    insert(x, 1);

    cout << prefix_iterating(x) << '\n';
    return 0;
}