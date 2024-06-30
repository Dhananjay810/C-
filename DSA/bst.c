#include<stdio.h>
#include<stdlib.h>

struct bst{
    struct bst*left;
    struct bst*right;
    struct bst*root;
    int data;
};

struct bst*begin(int info){
    struct bst*newnode=malloc(sizeof(struct bst));
    newnode->data=info;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct bst*ins(struct bst*root,int info){

    if(root==NULL) return begin(info);

    if(info<root->data){
        root=root->left;
        ins(root,info);
    }

    else if(info>root->data){
        root=root->right;
        ins(root,info);
    }
    return root;
}

int search(struct bst*root,int val){
    if(root==NULL) {
        return 0;
    }

    if(root->data==val){
        return 1;
    }
    else if(val<root->data){
        root=root->left;
        search(root,val);
    }
    else if(val>root->data){
        root=root->right;
        search(root,val);
    }
}

int main(){
    struct bst*root=NULL;
    int y=100;
    while(y>0){
        int n;
        printf("enter cammand : ");
        scanf("%d",&n);
        if(n==1){
            int info;
            printf("enter value : ");
            scanf("%d",&info);
            root=ins(root,info);
        }
        else if(n==2){
            int val;
            printf("enter value : ");
            scanf("%d",val);
            printf("%d\n",search(root,val));
        }
    }

}