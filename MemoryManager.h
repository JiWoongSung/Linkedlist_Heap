//
//  MemoryManager.c
//  HW2_MemoryManagement
//
//  Copyright © 2017년 2학기 System Programming. All rights reserved.
//
//  이름 : 성지웅
//  학번 : 2013043263
//  학과 : 컴퓨터공학과
//

#ifndef _MemoryManager_H_
#define _MemoryManager_H_

#include <stdio.h>
#include "Dlinkedlist.h"

Block *m_alloc(int size2);
void m_free(Block block);
void getHeap(DLinkedList *heap);
void mergeAfter(Node *newNode);
void mergerBefore(Node *newNode);

DLinkedList *g_heap;

Block *m_alloc(int size2) {  //메모리를 할당 받고 힙에서 가져오게 코딩해야함 ; 힙에있는 공간이 줄어들어야함,빼와야함
    
    Block *block = (Block*) malloc(sizeof(size2));
    
    Node *tmp = g_heap->header->next;
    while(tmp!=g_heap->trailer){
        if(size2<= tmp->item.size){
         
            if(tmp->item.start==0){ //힙에 블락이 하나일때 
                block->start =0;
                block->size = size2;
                block->end = size2-1;
                tmp->item.start= tmp->item.start+size2;
                tmp->item.size = tmp->item.size-size2;
                if(tmp->item.size==0){
                    removeNode(tmp);
                }
              
            }
            
            else{ //힙에 블락이 여러개일때 
                block->start = tmp->item.start;
                block->size = size2;
                block->end = block->start+block->size-1;
                tmp->item.start= tmp->item.start+size2;
                tmp->item.size = tmp->item.size-size2;
                if(tmp->item.size==0){
                    removeNode(tmp);
                }
                
            }
            
            g_heap->size = g_heap->size -size2;
            

            

            
            
            break;
        }
        
        else{
            tmp=tmp->next;
            
        }
        
        
    }
    
    
    
   
    return block;
    // write your code..
    
    
}

void m_free(Block block) { //end주소를 비교하여 찾아감 여기서 블락은 heap에 반환할 블락임
    
    Node *tmp = g_heap->header->next;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->item= block;
    
    while(tmp!=g_heap->trailer){
        if(newNode->item.end < tmp->item.end){
            addBefore(tmp,newNode);    // 새노드를 넣어줌
            
            g_heap->size = g_heap->size +newNode->item.size;  // 힙사이즈를 늘려줌
            
           if(newNode->item.end==newNode->next->item.start-1){
                mergeAfter(newNode);
            }
            
            
            if(newNode->item.start==newNode->prev->item.end+1){
                mergerBefore(newNode);
            }
            
            break;
        
        }
        else{
            tmp=tmp->next;
        }
        
    }
    
    
    
    
    
    
    
    // write your code..
    
    
}

void mergeAfter(Node *newNode){
    
    Node *mergeNode = (Node*) malloc(sizeof(Node));
    mergeNode->item.size= newNode->item.size + newNode->next->item.size;
    mergeNode->item.start= newNode->item.start;
    mergeNode->item.end= newNode->next->item.end;
    
    newNode->next->next->prev=mergeNode;
    mergeNode->next=newNode->next->next;
    
    newNode->prev->next=mergeNode;
    mergeNode->prev=newNode->prev;
    
    
    
    
    
    
}

void mergerBefore(Node *newNode){
    
    Node *mergeNode = (Node*) malloc(sizeof(Node));
    mergeNode->item.size= newNode->item.size + newNode->prev->item.size;
    mergeNode->item.start= newNode->prev->item.start;
    mergeNode->item.end= newNode->item.end;
    
    newNode->prev->prev->next=mergeNode;
    mergeNode->prev=newNode->prev->prev;
    
    newNode->next->prev=mergeNode;
    mergeNode->next=newNode->next;



    
    
}



/*
 * Do not modify this function !
 */
void getHeap(DLinkedList *heap) {
    Node *tmpNode = heap->header->next;
    printf("size: %d\n", heap->size); // 현재 힙의 사이즈 출력
    printf("Header] <-> ");
    
    while(tmpNode != heap->trailer) { // tmp노드가 trailer를 가르키지 않을때까지
        printf("[%d<-(%d)->%d] <-> ",
        tmpNode->item.start, tmpNode->item.size, tmpNode->item.end);
        tmpNode = tmpNode->next;
    }
    
    printf("[Trailer\n");
}

#endif
