#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} *NODE;


NODE create_node(int data)
{
    NODE nn = malloc(sizeof(struct node));
    if (nn == NULL)
        return NULL;

    nn->data = data;
    nn->link = nn;   
    return nn;
}

NODE go_last(NODE HEADER)
{
    NODE t = HEADER;
    while (t->link != HEADER)
        t = t->link;
    return t;
}

NODE insert_front(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
        return HEADER;

    if (HEADER == NULL)
        return new_node;

    go_last(HEADER)->link = new_node;
    new_node->link = HEADER;
    HEADER = new_node;

    return HEADER;
}

NODE insert_end(NODE HEADER, int data)
{
    NODE new_node = create_node(data);
    if (new_node == NULL)
        return HEADER;

    if (HEADER == NULL)
        return new_node;

    go_last(HEADER)->link = new_node;
    new_node->link = HEADER;

    return HEADER;
}

NODE delete_front(NODE HEADER)
{
    NODE Temp = HEADER;

    if (HEADER == NULL)
    {
        printf("\nEmpty List !!");
        return HEADER;
    }

    if (HEADER->link == HEADER)
    {
        free(HEADER);
        return NULL;
    }

    go_last(HEADER)->link = HEADER->link;
    HEADER = HEADER->link;
    printf("\nDelete %d", Temp->data);
    free(Temp);

    return HEADER;
}

NODE delete_end(NODE HEADER)
{
    NODE Temp = HEADER;

    if (HEADER == NULL)
    {
        printf("\nEmpty List !!");
        return HEADER;
    }

    if (HEADER->link == HEADER)
    {
        printf("\nDelete %d", HEADER->data);
        free(HEADER);
        return NULL;
    }

    while (Temp->link->link != HEADER)
        Temp = Temp->link;

    printf("\nDelete %d", Temp->link->data);
    free(Temp->link);
    Temp->link = HEADER;

    return HEADER;
}

void display(NODE HEADER)
{
    NODE t;

    if (HEADER == NULL)
    {
        printf("\nList Empty");
        return;
    }

    t = HEADER;
    printf("\nCircular List: ");
    do
    {
        printf("%d ", t->data);
        t = t->link;
    } while (t != HEADER);
}

int main()
{
    NODE HEADER = NULL;

    HEADER = insert_front(HEADER, 10);
    HEADER = insert_front(HEADER, 20);
    HEADER = insert_end(HEADER, 30);
    display(HEADER);

    HEADER = delete_front(HEADER);
    display(HEADER);

    HEADER = delete_end(HEADER);
    display(HEADER);

    return 0;
}
