#include "ECListNode.h"
#include "ECList.h"

// Linked list 
ECList :: ECList() : pHead(NULL), numNodes(0)
{

}
  
// insert node with value val after a node
// if node is NULL, insert to the front
void ECList :: Insert(int val, ECListNode *pPre)
{
    ECListNode *pn = new ECListNode;
    pn->SetValue(val);
    if (pPre == NULL) {
        pn->SetNext(pHead);
        pHead = pn;
    } else {
        pn->SetNext(pPre->GetNext());
        pPre->SetNext(pn);
    }
    numNodes++;
}

// delete a node
void ECList :: Delete(ECListNode *pNode)
{
    ECListNode *pcurr = pHead;
    ECListNode *ppre = NULL;
    while (pcurr != NULL) {
        if (pcurr == pNode) {
            break;
        }
        pcurr = pcurr->GetNext();
    }
    if (pcurr == NULL) {
        return;
    }

    if (ppre == NULL) {

    } else {

    }
}

// get a node with value; if multiple nodes with the same value, return the first from head
ECListNode * ECList::GetNode(int val)
{
    ECListNode *pres;
    ECListNode *pcurr = pHead;
    while (pcurr != NULL) {
        if (pcurr->GetValue() == val) {
            pres = pcurr;
            break;
        }
        pcurr = pcurr->GetNext();
    }
    return pres;
}

// get the number of nodes in the list
int ECList:: GetSize() const
{
    return numNodes;
}

