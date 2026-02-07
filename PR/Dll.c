#include<stdio.h>
#include<stdlib.h>

typedef struct Mynode{
    int data;
    struct Mynode *prev, *next;
}*NODE;

NODE Create_Node(int data)
{
    NODE nn=malloc(sizeof(struct Mynode));
    if(nn==NULL)
    {
        printf("No Mem");
        exit(1);
    }
    nn->data=data;
    nn->prev=nn->next=NULL;
    return nn;
}
NODE Ins_Frnt(NODE H, int data)
{
    NODE nn=Create_Node(data);
    if(H==NULL)
    {
        return nn;
    }else{
        H->prev=nn;
        nn->next=H;
        H=H->prev;
        return H;
    }
}
NODE Ins_End(NODE H,int data)
{
    NODE nn=Create_Node(data);
    if(H==NULL)
    {
        return(Create_Node(data));
    }
    NODE curr=H;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=nn;
    curr->next->prev=curr;
    return H;
}
void Display(NODE H)
{
    NODE T=H;
    while(T!=NULL)
    {
        printf("%d->",T->data);
        T=T->next;
    }
    printf("NULL\n");
}
int main()
{
    NODE H=NULL;
    H=Ins_Frnt(H,45);
    H=Ins_Frnt(H,78);
    Display(H);
    H=Ins_End(H,90);
    Display(H);
    return 0;
}