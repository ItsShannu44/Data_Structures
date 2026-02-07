#include<stdio.h>
#include<stdlib.h>

typedef struct Mynode{
    int data;
    struct Mynode* link;
}Mynode;

Mynode* Create_Node(int data)
{
    Mynode *nn=malloc(sizeof(struct Mynode));
    if(nn==NULL)
    {
        printf("NO MEM");
        exit(1);
    }
    nn->data=data;
    nn->link=NULL;
    return nn;
}
Mynode* Ins_Frnt(Mynode* H, int data){
    Mynode* nn=Create_Node(data);
    if(H==NULL)
    {
        nn->link=H;
        return nn;
    }
    nn->link=H;
    H=nn;
    return H;
}
Mynode* Ins_End(Mynode* H, int data){
    Mynode* nn=Create_Node(data);
    if(H==NULL)
    {
        nn->link=H;
        return H;
    }
    Mynode* T=H;
    while(T->link!=NULL)
    {
        T=T->link;
    }
    T->link=nn;
    printf("Inserted %d at end\n",T->data);
    return H;
}
Mynode* Dlt_Frnt(Mynode* H)
{
    if(H==NULL)
    {
        printf("\nList is Empty.\n");
        return H;
    }
    Mynode* T=H;
    H=H->link;
    printf("Deleted %d from frnt.\n",T->data);
    free(T);
    return H;
}
Mynode* Dlt_End(Mynode* H)
{
    if(H==NULL)
    {
        printf("List is Empty.\n");
        return H;
    }
    Mynode *curr=H; 
    Mynode *prev=NULL;
    while(curr->link!=NULL)
    {
        prev=curr;
        curr=curr->link;
    }
    prev->link=NULL;
    printf("Deleted %d from end.\n",curr->data);
    free(curr);
    return H;
}
void Display(Mynode *H)
{
    Mynode* T=H;
    while(T!=NULL)
    {
        printf("%d->",T->data);
        T=T->link;
    }
    printf("NULL\n");
}
int main()
{
    Mynode *H = NULL;
    H=Ins_Frnt(H,20);
    H=Ins_Frnt(H,30);
    H=Ins_Frnt(H,40);
    Display(H);
    H=Ins_End(H,50);
    Display(H);
    H=Dlt_Frnt(H);
    Display(H);
    H=Dlt_End(H);
    Display(H);
    return 0;
}