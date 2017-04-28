//
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

#include "file.h"

void List::insertNode(string name){
	Node* newNode = new Node(name);
	if(head && tail){
    	tail->next = newNode;
   	 	tail = newNode;
    	newNode->next = NULL;
  	}else{
    	newNode->next = head;
    	head = newNode;
    	tail = newNode;
  	}
}

void List::setData(string name, string info){
  Node* curr = head;
  while(curr != NULL){
    if(curr->fileName == name){
      curr->data = info;
      break;
    }else{
      curr = curr->next;
    }
  }
}

void List::setStartBlock(string name, int blockNum){
  Node* curr = head;
  while(curr != NULL){
    if(curr->fileName == name){
      curr->startBlockNum = blockNum;
      break;
    }else{
      curr = curr->next;
    }
  }
}

void List::deleteNode(string name){
  Node* curr = head;
  Node* prev = curr;
  if(curr->next == NULL){
    //only one node in list
  }else{
    while(curr != NULL){
      if(curr->fileName == name){
        prev->next = curr->next;
        delete curr;
        break;
      }else{
      prev = curr;
      curr = curr->next;
    }
   }
  }
}

void List::printAll(){
	Node* curr = head;
	while(curr != NULL){
		cout << "File Name: " << curr->fileName << endl;
    cout << "File Data: " << curr->data << endl;
    cout << "File Start Block: " << curr->startBlockNum << endl << endl; 
		curr = curr->next;
	}
}