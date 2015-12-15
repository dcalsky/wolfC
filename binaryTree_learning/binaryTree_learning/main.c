#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct BTree{
    DataType data;
    struct BTree *Tleft;
    struct BTree *Tright;
} *BTree;

BTree CreateTree(); //建树
BTree insert(BTree root, DataType data);//插入节点
void InBTree(BTree root); //中序遍历
void PreBTree(BTree root); //先序遍历
void PostBTree(BTree root);//后序遍历
BTree findPostion(BTree root, int deleteNode, int *flags);//寻找合适的插入点
BTree delNode(BTree root, BTree parent, int flags); //删除树节点

int main(){
    BTree root = NULL;
    int flags = 0;
    int deleteNode = 0;
    BTree parent = NULL;//所删除节点的父节点
    char choiceAgain = 'Y';
    root = CreateTree();
    printf("\n中序遍历: ");
    InBTree(root);
    printf("\n前序遍历: ");
    PreBTree(root);
    printf("\n后序遍历: ");
    PostBTree(root);
    printf("\n");
    
    do{
        printf("需要删掉的节点: ");
        scanf("%d", &deleteNode);
        parent = findPostion(root, deleteNode, &flags);
        root = delNode(root, parent, flags);
        printf("删除后的结果: ");
        printf("\n中序遍历: ");
        InBTree(root);
        printf("\n前序遍历: ");
        PreBTree(root);
        printf("\n后序遍历: ");
        PostBTree(root);
        choiceAgain = 'N';
        printf("\nDelete Again(Y) or N?: ");
        getchar();
        scanf("%c", &choiceAgain);
    }while(choiceAgain == 'Y' || choiceAgain == 'y');
    
    printf("\nDone!\n");
    return 0;
}

BTree CreateTree(){
    BTree root = NULL;
    DataType temp = 0;
    printf("请输入节点,以0结尾:\n");
    scanf("%d", &temp);
    while(temp != 0){
        root = insert(root, temp);
        scanf("%d", &temp);
    }
    
    return root;
}

BTree insert(BTree root, DataType data){
    BTree ptr = root;
    BTree tempNode;
    BTree newNode = (BTree)malloc(sizeof(struct BTree));
    newNode->data = data ;
    newNode->Tleft = NULL;
    newNode->Tright = NULL;
        
    if(ptr == NULL){
        return newNode;
    }else{
        while(ptr != NULL){
            tempNode = ptr;
            if(ptr->data >= data){
                ptr = ptr->Tleft;
            }else{
                ptr = ptr->Tright;
            }
        }
        
        if(tempNode->data >= data){
            tempNode->Tleft =  newNode;
        }else{
            tempNode->Tright =  newNode;
        }
    }
    return root;
}

BTree findPostion(BTree root, int deleteNode, int *flags){
    BTree parentNode = root;
    BTree temp = root;
    *flags = 0;
    
    while(temp != NULL){
        if(temp->data == deleteNode){
            return parentNode;
        }else{
            parentNode = temp;
            if(temp->data > deleteNode){
                temp = temp->Tleft;
                *flags = -1;
            }else{
                temp = temp->Tright;
                *flags = 1;
            }
        }
    }
    
    return NULL;
}

BTree delNode(BTree root, BTree parent, int flags){
    BTree deleteNode = NULL;
    
    if(parent == NULL){
        printf("未找到删除的节点!\n");
        return root;
    }
    
    switch(flags){
        case -1:
            deleteNode = parent->Tleft;
            break;
        case 0:
            deleteNode = parent;
            break;
        case 1:
            deleteNode = parent->Tright;
            break;
        default:
            printf("ERROR!\n");
            exit(1);
    }
    
    if(deleteNode->Tleft == NULL && deleteNode->Tright == NULL){
        if(parent->Tleft == deleteNode){
            parent->Tleft = NULL;
        }else if(parent->Tright == deleteNode){
            parent->Tright = NULL;
        }else{
            parent = NULL;
        }
        free(deleteNode);
    }else if(deleteNode->Tleft == NULL && deleteNode->Tright != NULL){
        if(deleteNode->data == root->data){
            root = deleteNode->Tright;
        }else{
            if(parent->Tleft->data == deleteNode->data){
                parent->Tleft = deleteNode->Tright;
            }else{
                parent->Tright = deleteNode->Tright;
            }
        }
        free(deleteNode);
    }else if(deleteNode->Tleft != NULL && deleteNode->Tright == NULL){
        if(deleteNode->data == root->data){
            root = deleteNode->Tleft;
        }else{
            if(parent->Tleft->data == deleteNode->data){
                parent->Tleft = deleteNode->Tleft;
            }else{
                parent->Tright = deleteNode->Tleft;
            }
        }
        free(deleteNode);
    }else{
        BTree temp = deleteNode->Tleft;
        BTree tempParent = deleteNode;
        while(temp->Tright != NULL){
            tempParent = temp;
            temp = temp->Tright;
        }
        
        deleteNode->data = temp->data;
        if(tempParent->Tleft == temp){
            tempParent->Tleft = temp->Tleft;	
        }else{
            tempParent->Tright = temp->Tleft;
        }
        
        printf("temp = %d\n", temp->data);
        free(temp);
    } 
    
    return root; 	
} 

void InBTree(BTree root){
    if(root != NULL){
        InBTree(root->Tleft); 
        printf("%d ", root->data); 
        InBTree(root->Tright);
    }
}

void PreBTree(BTree root){
    if(root != NULL){
        printf("%d ", root->data); 
        PreBTree(root->Tleft); 
        PreBTree(root->Tright);
    }
} 

void PostBTree(BTree root){
    if(root != NULL){
        PostBTree(root->Tleft); 
        PostBTree(root->Tright);
        printf("%d ", root->data);
    }
}