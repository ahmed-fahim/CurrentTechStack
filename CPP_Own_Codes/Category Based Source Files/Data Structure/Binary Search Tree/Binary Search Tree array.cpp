#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define BNULL -9999999

struct node{
    int value = -9999999;
};

class BinTree{
    node vertices[MAX];
    int root = 1;
public:
    BinTree(int rootvalue)
    {
        vertices[root].value = rootvalue;
    }

    int left(int i){return 2*i;}
    int right(int i){return 2*i + 1;}

    void setvalue(int key)
    {
        setvalue(root, key);
    }
    void setvalue(int index, int key)
    {
        if(vertices[index].value == key)
        {
            cout<<"ALREADY IN TREE\n";
            return;
        }
        else if(key < vertices[index].value)
        {
            if(vertices[left(index)].value == BNULL)
            {
                vertices[left(index)].value = key;
                return;
            }
            else{
                setvalue(left(index), key);
            }
        }
        else if(key > vertices[index].value)
        {
            if(vertices[right(index)].value == BNULL)
            {
                vertices[right(index)].value = key;
                return;
            }
            else{
                setvalue(right(index), key);
            }
        }
    }

    void Find(int key)
    {
            int iterate = root;
            int flag = 0;
            while(vertices[iterate].value != BNULL && iterate < MAX )
            {
                if(vertices[iterate].value == key)
                {
                    flag = 1;
                    cout<<"FOUND "<<key<<endl;
                    return;
                }
                else if(key < vertices[iterate].value )
                {
                    iterate = left(iterate);
                }
                else{
                    iterate = right(iterate);
                }
            }
            if(flag == 0) cout<<key<<" NOT FOUND\n";
    }
    void inorder()
    {
        inorder(root);
        cout<<endl;
    }
    void inorder(int index)
    {
        if(vertices[left(index)].value != BNULL) inorder(left(index));
        cout<<vertices[index].value<<" ";
        if(vertices[right(index)].value != BNULL) inorder(right(index));
    }
    void preorder()
    {
        preorder(root);
        cout<<endl;
    }
    void preorder(int index)
    {
         cout<<vertices[index].value<<" ";
        if(vertices[left(index)].value != BNULL) preorder(left(index));
        if(vertices[right(index)].value != BNULL) preorder(right(index));
    }
    void postorder()
    {
        postorder(root);
        cout<<endl;
    }
    void postorder(int index)
    {
        if(vertices[left(index)].value != BNULL) postorder(left(index));
        if(vertices[right(index)].value != BNULL) postorder(right(index));
        cout<<vertices[index].value<<" ";
    }
};

int main()
{
    BinTree a(2);
    a.setvalue(1);
    a.setvalue(3);
    a.Find(9);
    a.inorder();
    a.preorder();
    a.postorder();
}
