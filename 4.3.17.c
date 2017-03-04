#include<stdio.h>
#include<limits.h>
#include<malloc.h>
typedef struct tNode
{
    struct tNode* left;
    struct tNode* right;
    int val;
}tNode;
void getMxMn(tNode* root, int* mn, int* mx)
{
    if(root!=NULL)
    {
        getMxMn(root->left,mn,mx);
        getMxMn(root->right,mn,mx);
        if(*mx<root->val)
        {
            *mx=root->val;
        }
        if(*mn>root->val)
        {
            *mn=root->val;
        }
    }

}
tNode* createNode( int data)
{
    tNode* temp=malloc(sizeof(tNode));
    temp->val=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
tNode* createTree(tNode** hptr)
{
    int data;
    printf("Enter the value of the node\n");
    scanf("%d",&data);
    //tNode* ret;
    *hptr = createNode(data);
    printf("To enter a node enter the requirement in binary format ");
    int l,r;
    scanf("%d %d",&l,&r);
    if(l==1)
    {
        (*hptr)->left=createTree(&((*hptr)->left));
        //printf("%d\n",(*hptr)->left->val);
    }
    if(r==1)
    {
        (*hptr)->right=createTree(&((*hptr)->right));
        //printf("%d\n",(*hptr)->right->val);
    }
    return *hptr;
}
void inOrderTraversal(tNode* root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\n",root->val);
        inOrderTraversal(root->right);
    }
}

int getNumberOfPath(tNode* root)
{
    int ret=0;
    if(root==NULL)
    {
        ret=0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        ret=1;
    }
    else
    {
        ret=getNumberOfPath(root->left)+getNumberOfPath(root->right);
    }
    return ret;

}
int main()
{
    tNode* root;
    root=createTree(&root);
    int mx,mn;
    mx=INT_MIN;
    mn=INT_MAX;
    inOrderTraversal(root);
    printf("\n");
    getMxMn(root,&mn,&mx);
    printf("%d %d",mn,mx);
    return 0;
}


