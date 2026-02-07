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
NODE Del_Frnt(NODE H)
{
    if(H==NULL)
    {
        printf("Empty list.");
        return NULL;
    }
    printf("%d deleted from frnt.\n",H->data);
    H=H->next;
    free(H->prev);
    H->prev=NULL;
    return H;
}
NODE Del_End(NODE H)
{
    if(H==NULL)
    {
        printf("Empty List");
        return H;
    }
    NODE curr=H;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    printf("%d Deleted from End\n",curr->next->data);
    free(curr->next);
    curr->next=NULL;
    return H;
    
}
NODE Sort(NODE H)
{
    NODE i,j;
    int temp;
    if(H==NULL)
    {
        return H;
    }
    for(i=H;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!= NULL;j=j->next)
        {
            if(j->data < i->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
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
    H=Ins_Frnt(H,5);
    H=Ins_Frnt(H,120);
    H=Ins_Frnt(H,30);
    Display(H);
    H=Ins_End(H,90);
    Display(H);
    H=Del_Frnt(H);
    H=Del_End(H);
    Display(H);
    H=Sort(H);
    Display(H);
    return 0;
}