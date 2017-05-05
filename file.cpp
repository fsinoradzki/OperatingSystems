//
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

#include "file.h"

void List::insertNode(string name){
	Node* newNode = new Node(name);
	if(head && tail){
    	tail->next = newNode;
   	 	tail = newNode;
      newNode->startBlockNum = 0;
      newNode->blocksUsed = 0;
    	newNode->next = NULL;
  	}else{
      newNode->startBlockNum = 0;
      newNode->blocksUsed = 0;
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

void List::setDiskBlocks(string name, int blockNum, int blockSize){
  Node* curr = head;
  while(curr != NULL){
    if(curr->fileName == name){
      curr->blocksUsed = ceil(curr->data.length() / blockSize) + 1; //+1 due to 0 index
      curr->startBlockNum = blockNum;
      // curr->endBlockNum = blockNum + (curr->blocksUsed - 1);
      break;
    }else{
      curr = curr->next;
    }
  }
}

int List::getStartBlock(string name){
	Node* curr = head;
	int start;
	while(curr != NULL){
		if(curr->fileName == name){
			start = curr->startBlockNum;
			break;
		}else{
			curr = curr->next;
		}
	}
	return start;
}
int List::getBlocksUsed(string name){
	Node* curr = head;
	int used;
	while(curr != NULL){
		if(curr->fileName == name){
			used = curr->blocksUsed;
			break;
		}else{
			curr = curr->next;
		}
	}
	return used;
}

void List::deleteNode(string name){
  Node* curr = head;
  Node* prev = curr;
  int c = 0;
  int delStart = 0;
  int delUsed = 0;
  if(curr->next == NULL){
    //only one node in list
    delete curr;
  }else{
    while(curr != NULL){
      if(name == curr->fileName){
        delStart = curr->startBlockNum;
        delUsed = curr->blocksUsed;
      	if(c == 0){ //if first node in the list is being deleted
      		head = curr->next;
      		delete curr;
      	}else{
      		prev->next = curr->next;
        	delete curr;
      	}
        break;
      }else{
      	prev = curr;
      	curr = curr->next;
      	c++;
      }
    }
  }

  Node* curr2 = head;
  int d = 0;
  while(curr2!=NULL){    
    if(d>=c){
      if(curr2->startBlockNum!=0)
        curr2->startBlockNum -= delUsed;
    } 
    curr2 = curr2->next;
    d++;
  }

}

int List::getStats(int fileNumber){
	Node* curr = head;
	for(int i = 0; i < fileNumber; i++){
		curr = curr->next;
	}
	cout << setw(8) << curr->fileName << setw(8) << curr->blocksUsed << endl;

	return curr->blocksUsed;
}

void List::printFileData(string name){
	Node* curr = head;
	while(curr != NULL){
		if(name == curr->fileName){
			cout << curr->data << endl;
			break;
		}else{
			curr = curr->next;
		}
	}
}

void List::printAll(){
	Node* curr = head;
	while(curr != NULL){
		cout << "File Name: " << curr->fileName << endl;
   	 	cout << "File Data: " << curr->data << endl;
    	cout << "Disk Start Block: " << curr->startBlockNum << endl;
    	// cout << "Disk End Block: " << curr->endBlockNum << endl;
    	cout << "Disk Blocks Used: " << curr->blocksUsed << endl << endl; 
		curr = curr->next;
	}
}