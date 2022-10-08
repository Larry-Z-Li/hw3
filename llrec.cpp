#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void pivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if(head == NULL)
    {
        smaller->next = NULL;
        larger->next = NULL;
        return;
    }
    if(head->val <= pivot)
    {
        if(smaller == NULL)
        {
            smaller = head;
            pivotHelper(head->next, smaller, larger, pivot);
        }
        else
        {
            smaller->next = head;
            pivotHelper(head->next,smaller->next, larger, pivot);
        }
    }
    else
    {
        if(larger == NULL)
        {
            larger = head;
            pivotHelper(head->next, smaller, larger, pivot);
        }
        else
        {
            larger->next = head;
            pivotHelper(head->next,smaller, larger->next, pivot);
        }
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = NULL;
    larger = NULL;
    if(head == NULL)
        return;
    else
        pivotHelper(head, smaller, larger, pivot);
    head = NULL;
    return;
}
