#include <bits/stdc++.h>
using namespace std;

template <typename T> struct node{
    T value;
    node *parent, *left, *right;
};

template <typename Tp> class BinTree
{
    node <Tp> *root;

public:
    BinTree(Tp rootvalue)
    {
        root = new node<Tp>;
        root->value = rootvalue;
        root->parent = root->left = root->right = NULL;
    }

    inline node<Tp>* getroot()
    {
        return root;
    }

    inline void setvalue(node<Tp> *temp, Tp key)
    {
        if(temp->value == key) return;

        else if(key < temp->value)
        {
            if(temp->left != NULL)
            {
                setvalue(temp->left, key);
                return;
            }
            else{
                node <Tp> *newleft = new node<Tp>;
                newleft->value = key;
                newleft->left = newleft->right = NULL;
                newleft->parent = temp;
                temp->left = newleft;
                return;
            }
        }
        else if(key > temp->value)
        {
            if(temp->right != NULL)
            {
                setvalue(temp->right, key);
                return;
            }
            else{
                node <Tp> *newright = new node<Tp>;
                newright->value = key;
                newright->left = newright->right = NULL;
                newright->parent = temp;
                temp->right = newright;
                return;
            }
        }
    }
    inline void setvalue(Tp key)
    {
        setvalue(root, key);
    }
    void Search(Tp key)
    {
        node<Tp>* temp = root;

        while(temp != NULL)
        {
            if(temp->value == key)
            {
                if(temp == root)
                {
                    cout<<key<<" is found in the ROOT\n";
                    return;
                }
                else if(temp->parent->left == temp)
                {
                    cout<<key<<" is found as the LEFT child of "<<temp->parent->value<<endl;
                    return;
                }
                else if(temp->parent->right == temp)
                {
                    cout<<key<<" is found as the RIGHT child of "<<temp->parent->value<<endl;
                    return;
                }
            }
            else if( key < temp->value)
            {
                temp = temp->left;
            }
            else if(key > temp->value)
            {
                temp = temp->right;
            }
        }
        cout<<key<<" is not in the TREE\n";
        return;
    }

    inline void inorder(node<Tp>* temp)
    {
        if(temp->left != NULL) inorder(temp->left);

        cout<<temp->value<<" ";

        if(temp->right != NULL) inorder(temp->right);

        return;
    }

    inline void preorder(node<Tp> *temp)
    {
        cout<<temp->value<<" ";

        if(temp->left != NULL) preorder(temp->left);

        if(temp->right != NULL) preorder(temp->right);

        return;
    }

    inline void postorder(node<Tp> *temp)
    {
        if(temp->left != NULL) postorder(temp->left);

        if(temp->right != NULL) postorder(temp->right);

        cout<<temp->value<<" ";
        return;
    }

    inline Tp minimum()
    {
        node<Tp>* temp = root;

        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp->value;
    }

    inline Tp maximum()
    {
        node<Tp>* temp = root;

        while(temp->right != NULL)
        {
            temp = temp->right;
        }

        return temp->value;
    }
    inline Tp prenode_inorder(Tp key)
    {
        node<Tp>* pointer = root;

        while(1)
        {
            if(pointer->value == key) break;
            else if(key < pointer->value)
            {
                pointer=pointer->left;
            }
            else if(key > pointer->value)
            {
                pointer = pointer->right;
            }
        }
        if(pointer->left != NULL)
        {
            pointer = pointer->left;
        }
        else
        {
            printf("NO PRENODE FOUND\n");
            return '\0';
        }
        while(1)
        {
            if(pointer -> right != NULL)
            {
                pointer = pointer->right;
            }
            else break;
        }
        return pointer->value;
    }
    inline Tp nextnode_inorder(Tp key)
    {
        node<Tp>* pointer = root;

        while(1)
        {
            if(pointer->value == key) break;
            else if(key < pointer->value)
            {
                pointer=pointer->left;
            }
            else if(key > pointer->value)
            {
                pointer = pointer->right;
            }
        }
        if(pointer->right != NULL)
        {
            pointer = pointer->right;
        }
        else
        {
            printf("NO PRENODE FOUND\n");
            return '\0';
        }
        while(1)
        {
            if(pointer -> left != NULL)
            {
                pointer = pointer->left;
            }
            else break;
        }
        return pointer->value;
    }

    inline Tp nextnode_preorder(Tp key)
    {
        node<Tp>* pointer = root;

        while(1)
        {
            if(pointer->value == key) break;
            else if(key < pointer->value)
            {
                pointer=pointer->left;
            }
            else if(key > pointer->value)
            {
                pointer = pointer->right;
            }
        }
        if(pointer->left != NULL)
        {
            return pointer->left->value;
        }
        else if(pointer->parent->right != NULL && pointer->parent->right != pointer)
        {
            return pointer->right->value;
        }
        else {
            printf("NO NEXTNODE in PREORDER FOUND\n");
            return NULL;
        }
    }
    inline Tp nextnode_postorder(Tp key)
    {
        node<Tp>* pointer = root;
        while(1)
        {
            if(pointer->value == key) break;
            else if(key < pointer->value)
            {
                pointer=pointer->left;
            }
            else if(key > pointer->value)
            {
                pointer = pointer->right;
            }
        }
        if(pointer == root)
        {
            cout<<"NO NEXTNODE FOUND IN POSTORDER\n";
            return NULL;
        }
        else if(pointer == pointer->parent->left)
        {
            if(pointer->parent->right != NULL)
            {
                node<Tp> *current = pointer->parent->right;
                while(1)
                {
                    if(current->left != NULL) current=current->left;
                    else if(current->right != NULL) current = current->right;
                    else break;
                }
                return current->value;
            }
            else{
                return pointer->parent->value;
            }
        }
        else{
            return pointer->parent->value;
        }
    }
    void inorder_stack()
    {
        node<Tp> *current = root;
        stack<node<Tp> *> serial;
        bool flag = 1;
        while(flag)
        {
            if(current != NULL)
            {
                    serial.push(current);
                    current = current->left;
            }
            else if(current == NULL && serial.empty() == false)
            {
                current = serial.top();
                serial.pop();
                cout<<current->value<<" ";
                current = current->right;
            }
            else{
                flag = 0;
            }
        }
        cout<<endl;
    }
    void postorder_stack()
    {
        stack<node<Tp> *> s1,s2;
        s1.push(root);

        while(s1.empty() == false)
        {
            s2.push(s1.top());
            node<Tp> *temp;
            temp = s1.top();
            s1.pop();
            if(temp->left != NULL) s1.push(temp->left);
            if(temp->right != NULL)s1.push(temp->right);
        }
        while(s2.empty() == false)
        {
            cout<<s2.top()->value<< " ";
            s2.pop();
        }
        cout<<endl;
    }
};
int main()
{

}
