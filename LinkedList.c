#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node {
	int value;
	struct Node *next;
};

	
/*struct Node* createNode(int  value, struct Node *next){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	
	node->value = value;

	if(next){
		node->next= next;
	}

	return node;
}*/


void insertFront(int value ,struct Node *root){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));

	node->value = value;
	node->next = NULL;
	
	if(!root->value){
		root->value = node->value;
		
	}else{
	 	if(!root->next){
	 		root->next = node;
	 	}else{
	 		struct Node *actual;
	 		actual = root;
	 		while(actual){
	 			if(!actual->next){
	 				actual->next = node;
	 				break;
	 			}else{
	 				actual = actual->next;
	 			}
	 		}
	 	}
	}
};




int removeFront(struct Node *root){

	int value;


	if(!root->next){
		value = root->value;
		root->value = NULL;
	}else{
		struct Node *current;
		struct Node *currentBack;
		currentBack = root;
		current = root->next;

		
		while(current){
			if(!current->next){
				currentBack->next = NULL;
				value = current->value;
				free(current);
				return value;
			}else{
				currentBack = current;
				current = current->next;

			}
		}
	}

	return value;
}


void insertBack(int value,struct Node *root){

	if(!root->value){
		root->value = value;
	}
	else{	
		struct Node *node = (struct Node*) malloc(sizeof(struct Node));

		node->value = root->value;
		root->value = value;
		
		node->next = root->next;
		root->next = node;
	}
}



int removeBack(struct Node *root){
	int value;
	if(!root->next){
		value = root->value;
		root->value = NULL;
		return value;
	}else{
		value = root->value;
		*root = *root->next;
		return value;
	}
}





		





bool hasNext(struct Node *node){
	if(node->next != NULL){
		return true;
	}else return false;
}





void main(){
	struct Node *root = (struct Node*) malloc(sizeof(struct Node));
	root -> next = NULL;



	insertFront(2020,root);
	insertFront(2021,root);
	insertFront(3002,root);
	insertFront(2134,root);
	removeBack(root);
	removeBack(root);
	



	struct Node *iterator = root;
	while(iterator){
		printf("%d, ",iterator->value);
		iterator = iterator->next;
	}


	free(root);

}
