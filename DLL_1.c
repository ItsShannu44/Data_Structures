#include<stdio.h>
#include<stdlib.h>

typedef struct MyNode{
    int data;
    struct MyNode*llink, *rlink;
}*NODE;

NODE create_node(int data)
{
    NODE nn=malloc(sizeof(struct MyNode));
    if(nn==NULL)
    {
        printf("NO MEM!!");
        exit(0);
    }
    nn->data=data;
    nn->llink=nn->rlink=NULL;
    return nn;
}

NODE ins_frnt(NODE H, int data)
{
    NODE nn=create_node(data);
    if(H==NULL)
    {
        return nn;
    }else{
        H->llink=nn;
        nn->rlink=H;
        H=H->llink;
        return H;
    }
}
NODE ins_rear(NODE H, int data)
{
    if(H==NULL)
        return(create_node(data));
    NODE curr=H;
    while(curr->rlink!=NULL)
        curr=curr->rlink;
    curr->rlink=create_node(data);
    curr->rlink->llink=curr;
    return H;
}

NODE del_frnt(NODE H)
{
    if(H==NULL)
    {
        printf("Empty list");
        return H;
    }
    if(H->rlink==NULL)
    {
        free(H);
        return NULL;
    }else{
        H=H->rlink;
        free(H->llink);
        H->llink=NULL;
    }
}

NODE del_rear(NODE H)
{
    NODE curr=H;
    while(curr->rlink->rlink!=NULL)
    {
        curr=curr->rlink;
    }
    free(curr->rlink);
    curr->rlink=NULL;
    return H;
}

void display(NODE H)
{
    NODE curr=H;
    while(curr!=NULL)
    {
        printf("%d->",curr->data);
        curr=curr->rlink;
    }
    printf("NULL");
    printf("\n");
}
void reverseDisplay(NODE H)
{
    NODE curr = H;
    if (curr == NULL)
        return;

    while (curr->rlink != NULL)
        curr = curr->rlink;

    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->llink;
    }
    printf("NULL\n");
}

NODE sort_dll(NODE H)
{
    NODE i, j;
    int temp;

    if (H == NULL)
        return H;

    for (i = H; i->rlink != NULL; i = i->rlink)
    {
        for (j = i->rlink; j != NULL; j = j->rlink)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return H;
}

int main()
{
    NODE H=NULL;
    H=ins_frnt(H,10);
    H=ins_frnt(H,20);
    H=ins_frnt(H,6);
    display(H);
    H=ins_rear(H,12);
    H=ins_rear(H,14);
    display(H);
    H=del_frnt(H);
    display(H);
    H=del_rear(H);
    display(H);
    H=sort_dll(H);
    display(H);
    reverseDisplay(H);
    return 0;
}