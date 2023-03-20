#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

void removeDuplicate(Node* &pHead) {
    if (!pHead) return; // empty list
    Node* pCurr = pHead;
    while (pCurr) {
        Node* pPrev = pCurr;
        Node* pNext = pCurr->next;
        while (pNext) {
            if (pCurr->data == pNext->data) {
                pPrev->next = pNext->next;
                delete pNext;
                pNext = pPrev->next;
            }
            else {
                pPrev = pNext;
                pNext = pNext->next;
            }
        }
        pCurr = pCurr->next;
    }
}

int main() {
    // create a linked list with duplicates
    Node* pHead = new Node(1);
    pHead->next = new Node(2);
    pHead->next->next = new Node(1);
    pHead->next->next->next = new Node(1);
    pHead->next->next->next->next = new Node(2);
    pHead->next->next->next->next->next = new Node(1);

    // print the original list
    Node* pCurr = pHead;
    while (pCurr) {
        std::cout << pCurr->data << " ";
        pCurr = pCurr->next;
    }
    std::cout << std::endl;

    // remove duplicates
    removeDuplicate(pHead);

    // print the updated list
    pCurr = pHead;
    while (pCurr) {
        std::cout << pCurr->data << " ";
        pCurr = pCurr->next;
    }
    std::cout << std::endl;

    // clean up
    while (pHead) {
        Node* pTemp = pHead;
        pHead = pHead->next;
        delete pTemp;
    }

    return 0;
}