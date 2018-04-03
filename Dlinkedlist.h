//
//  DLinkedList.h
//  HW2_MemoryManagement
//
//  Copyright © 2017년 2학기 System Programming. All rights reserved.
//
//  이름 : 성지웅
//  학번 : 2013043263
//  학과 : 컴퓨터공학과
//

#ifndef _DLinkedList_H_
#define _DLinkedList_H_

#include <stdio.h>
#include <stdbool.h>
#include "Block.h"
#include "Node.h"

typedef struct DLinkedList {
    int size;
    struct Node *header;
    struct Node *trailer;
} DLinkedList;

void setHeaderInfo(DLinkedList *dl, Block info);
void setTrailerInfo(DLinkedList *dl, Block info);
bool isEmpty(DLinkedList *dl);
Node *getFirst(DLinkedList *dl);
Node *getLast(DLinkedList *dl);
void addFirst(DLinkedList *dl, Node *newNode);
void addLast(DLinkedList *dl, Node *newNode);
Block *removeFirst(DLinkedList *dl);
Block *removeLast(DLinkedList *dl);
void addAfter(Node *node, Node *newNode);
void addBefore(Node *node, Node *newNode);
Block *removeNode(Node *node);

/*
 * set header information of dl
 */
void setHeaderInfo(DLinkedList *dl, Block info) {
    dl->header->item = info;
}

/*
 * set trailer information of dl
 */
void setTrailerInfo(DLinkedList *dl, Block info) {
    dl->trailer->item = info;
}

/*
 * if empty, return true;
 * if not empty, return false;
 * bool is from <stdbool.h>
 */
bool isEmpty(DLinkedList *dl) { // 비어있으면 true, 아니면 false
    // write your code..
    
    if(dl->size==0){
        return true;
    }
    else{
        return false;
    }
    
}

/*
 * return dl's size
 */
int getSize(DLinkedList *dl) {
    return dl->size;
}

/*
 * return dl's first Node
 */
Node *getFirst(DLinkedList *dl) {
    // write your code..
    return dl->header;
}

/*
 * return dl's last Node
 */
Node *getLast(DLinkedList *dl) {
    // write your code..
    return dl->trailer;
}

/*
 * add newNode to dl's first position
 */
void addFirst(DLinkedList *dl, Node *newNode) {
    // write your code..
  /*  if(dl->size==0){
        dl->header = newNode;
        dl->trailer = newNode;
    }
   */
    
    newNode->next= dl->header->next;
    dl->header->next->prev = newNode;
    
    
    dl->header->next= newNode;
    newNode->prev = dl->header;
    
    
    
  //  dl->size++;

}

/*
 * add newNode to dl's last position
 */
void addLast(DLinkedList *dl, Node *newNode) {
    // write your code..
    
    
    newNode->prev= dl->trailer->prev;
    dl->trailer->prev->next = newNode;
    
    dl->trailer->prev= newNode;
    newNode->next= dl->trailer;
        
        
    }
    
   // dl->size++;



/*
 * remove dl's first node
 */
Block *removeFirst(DLinkedList *dl) {
    if(dl->size==0){
        printf("error : no Node ");
    }
    
    else{
        dl->header= dl->header->next;
        
      //  dl->size--;
    }
    // write your code..
    return NULL;

}

/*
 * remove dl's last node
 */
Block *removeLast(DLinkedList *dl) {
    // write your code..
    if(dl->size==0){
        printf("error : no Node ");
    }
    else{
        
        dl->trailer= dl->trailer->prev;
        
      //  dl->size--;
    }

    return NULL;
}

/*
 * add newNode after the node
 */
void addAfter(Node *node, Node *newNode) {
    // write your code..
    newNode->next= node->next;
    node->next->prev = newNode;
    
    
    node->next= newNode;
    newNode->prev = node;
    
}

/*
 * add newNode before the node
 */
void addBefore(Node *node, Node *newNode) {
    // write your code..
    newNode->prev= node->prev;
    node->prev->next = newNode;
    
    node->prev= newNode;
    newNode->next= node;
}

/*
 * remove the node
 */
Block *removeNode(Node *node) {
    // write your code..
    node->prev->next=node->next;
    node->next->prev=node->prev;
    return NULL;
}


#endif
