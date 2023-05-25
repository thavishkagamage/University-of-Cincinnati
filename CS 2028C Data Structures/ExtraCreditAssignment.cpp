_author_ = "Thavishka Gamage"
_credits_ = "Worked independently"
_email_ = "gamagetd@mail.uc.edu" # Your email address

#include<iostream>
#include<stdlib.h>
using namespace std;

class node{
public:
string key;
node *left, *right;

bool operator <= (node n){
return key<=n.key;
}
bool operator >= (node n){
return key>=n.key;
}
bool operator == (node n){
return key==n.key;
}
bool operator < (node n){
return key<n.key;
}
};

class BST{
private:
node*root;

node* insert(node* Node , node*newNode)
{
if (Node == NULL) return newNode;

if (newNode->key < Node->key)
Node->left = insert(Node->left, newNode);
else if (newNode->key > Node->key)
Node->right = insert(Node->right, newNode);

return Node;
}

node*findmin(node*tree){
while(tree->left){
tree=tree->left;
}
return tree;
}

node*deletenode( node*tree, string key){
node*temp;
if(!tree)return NULL;
else if(tree->key<key)tree->right=deletenode(tree->right,key);
else if(tree->key>key)tree->left=deletenode(tree->left,key);
else if(tree->key==key){
if(!tree->left){
temp=tree->right;
delete(tree);
return temp;
}
if(!tree->right){
temp=tree->left;
delete(tree);
return temp;
}
temp=findmin(tree->right);
tree->key=temp->key;
deletenode(tree->right,temp->key);
}
else
cout<<"key not found\n";


return tree;
}

node* search(node* Node, string key)
{

if (Node == NULL || Node->key == key)
return Node;

if (Node->key < key)
return search(Node->right, key);

return search(Node->left, key);
}

int size(node*Node){
if(!Node)return 0;
return 1+size(Node->left)+size(Node->right);
}

void inorder(node*Node , string &arr){
if(!Node)return;
inorder(Node->left , arr );
arr+=Node->key+"\n";
inorder(Node->right , arr );
}

void DecOrder( node*Node , string &arr){
if(!Node)return;
DecOrder(Node->right , arr );
arr+=Node->key+"\n";
DecOrder(Node->left , arr );


}


public:
BST(){
root=NULL;
}

void Insert(string item)
{
node *temp = new node;
temp->key = item;
temp->left =NULL;
temp->right = NULL;
root= insert(root,temp);
}

void Remove(string item){
root= deletenode(root,item);
}

node*find(string item){
return search(root,item);
}
int Size(){
return size(root);
}
string GetAllAscending (){
string arr="";
inorder(root,arr);
return arr;
}
string GetAllDescending (){
string arr="";
DecOrder(root,arr);
return arr;
}

};


int main()
{
BST bst1;
string arr1[] = {"Star Wars", "Star Trek", "Space Balls", "Galaxy Quest"};
for(int i=0;i<4;i++){
bst1.Insert(arr1[i]);
}

cout<<bst1.Size()<<"\n";
cout<<bst1.GetAllAscending()<<"\n";
cout<<bst1.GetAllDescending()<<"\n";

BST bst2;
string arr2[] = {"Cars", "Monsters" , "Inc", "The Incredibles", "Wall-E"};
for(int i=0;i<4;i++){
bst2.Insert(arr2[i]);
}

cout<<bst2.Size()<<"\n";
cout<<bst2.GetAllAscending()<<"\n";
cout<<bst2.GetAllDescending()<<"\n";

BST bst3;
string arr3[] = {"Halloween", "A Nightmare On Elm Street", "Hocus Pocus", "Beetlejuice"};
for(int i=0;i<4;i++){
bst3.Insert(arr3[i]);
}

cout<<bst3.Size()<<"\n";
cout<<bst3.GetAllAscending()<<"\n";
cout<<bst3.GetAllDescending()<<"\n";

return 0;
}

//sample output