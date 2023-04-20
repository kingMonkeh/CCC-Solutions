#pragma GCC optimize("O2")
#include <iostream>

struct node {
    node *left = NULL, *right = NULL;
    int rank = 1;
    int score;
};

struct tree {

    node* root = NULL;

    int add(int score){

        int rank = 1;

        if (root == NULL){
            root = new node;
            root->score = score;
            return 1;
        }

        else{
            node* currentNode = root;
            while (true){
                if (score < currentNode->score){
                    rank += currentNode->rank;
                    if (currentNode->left == NULL){
                        currentNode->left = new node;
                        currentNode->left->score = score;
                        return rank;
                    }
                    currentNode = currentNode->left;
                }
                    
                else{
                    currentNode->rank++;
                    if (currentNode->right == NULL){
                        currentNode->right = new node;
                        currentNode->right->score = score;
                        return rank;
                    }
                    currentNode = currentNode->right;
                }
            }
        }
        
    }
    

} Tree;



int main(){

    int t;
    scanf("%d", &t);

    double average = 0.0;
    
    for (int i = 0; i < t; i++){
        int score;
        scanf("%d", &score);
        average += Tree.add(score);
    }

    printf("%.2f", average / t);

    return 0;
    
}