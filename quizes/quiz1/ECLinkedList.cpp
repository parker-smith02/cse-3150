#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
  /* your code here */
  int l = 0;
  struct ECLinkedListNode *cur = pHead;
  while (cur != NULL) {
    l++;
    cur = cur -> pNext;
  }
  return l;

}


void ECDeleteNode(struct ECLinkedListNode *pPre, struct ECLinkedListNode *pNodeToDel)
{
  if( pPre != NULL )
  {
    pPre->pNext = pNodeToDel->pNext;
  }
  if( pNodeToDel != NULL )
  {
    pNodeToDel->pNext = NULL;
  }
  free( pNodeToDel );
}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val)
{
  /* your code here */
  struct ECLinkedListNode *prev = NULL;
  struct ECLinkedListNode *cur = pHead;
  struct ECLinkedListNode *next = NULL;

  while (cur != NULL) {
    if (cur->value == val) {
      next = cur->pNext;
      if (cur == pHead) {
        pHead = cur->pNext;
      }
      ECDeleteNode(prev, cur);
      cur = next;
    } else {
      prev = cur;
      cur = cur->pNext;
    }
  }
  return pHead;
}
