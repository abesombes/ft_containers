/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/31 19:08:02 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#define BLACK 0
#define RED 1
#define DOUBLE_BLACK 2
#define newline std::cout<<endl;
#include <iostream>


/*
--------------------------------------------------
Rules That Every Red-Black Tree Follows: 
--------------------------------------------------

1. Every node has a colour either red or black.
2. The root of the tree is always black.
3. There are no two adjacent red nodes (A red node cannot have a red parent or red child).
4. Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
5. All leaf nodes are black nodes.
*/

namespace ft{


template <class Key, class T>    
class Node {

    public:
            Key data; // holds the key value
            T   value; // holds the mapped value
            Node *parent; // pointer to the parent
            Node *left; // pointer to left child
            Node *right; // pointer to right child
            int color; // RED (1) -> Red, BLACK (0) -> Black
            
            Node(Key data, T value): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(RED){};
            Node(Key data, T value, int color): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(color){}
            void setColor(int color) { this->color = color;}
            int getColor() { return (color);}
            Key &getData() { return (data); }
            void setData (Key &data) { this->data = data; }
            T &getValue() { return (value); }
            void setValue(T value) { this->value = value; }
            void printNode(char relative_pos)
            {
                std::cout << (relative_pos == 'r' ? "Right" : "Left") << " - " << this->getData() << " - " << this->getValue() << " - " << (this->getColor() ? "Red" : "Black") << std::endl; 
                if (left)
                    left->printNode('l');
                if (right)
                    right->printNode('r');    
            }
};

// We consider a BST as a linked list of Nodes.
template <class Key, class T>  
Node<Key, T>* BSTInsert(Node<Key, T>* root, Node<Key, T>* node)
{
    if (root == NULL)
        return (node);
    if (root->getData() > node->getData())
    {
        root->left = BSTInsert(root->left, node);
        root->left->parent = root;
    }
    else if (root->getData() < node->getData())
    {
        root->right = BSTInsert(root->right, node);
        root->right->parent = root;  
    }
    return root;
}

template <class Key, class T>  
class RBTree {
    
    private:
                Node<Key, T>* _root;

    protected:
                
    
    public:          
                RBTree(): _root(NULL){};
                RBTree(Key data){
                    _root = new Node<Key, T>(data);
                    _root->setColor(BLACK); 
                };
                
                Node<Key, T>* getRoot(){ return _root;};
                
                void setRoot(Node<Key, T> &node){ this->_root = node; };
                
                void swapNodeColor(Node<Key, T> &nodeA, Node<Key, T> &nodeB)
                {
                    int tmp_color = nodeA.color;
                    nodeA.setColor(nodeB->getColor);
                    nodeB.setColor(tmp_color);
                }

                void insertNode(Key data, T value)
                {
                    Node<Key, T>* newNode = new Node<Key, T>(data, value);
                    
                    this->_root = BSTInsert(this->_root, newNode); 
                }

                Node<Key, T>* getMaxValueNode(Node<Key, T> *root)
                {
                    if(root==NULL)
                        return NULL;
                    else if (root->right==NULL)
                        return root;
                    else
                        return getMaxValueNode(root->right);
                }

                Node<Key, T>* getMinValueNode(Node<Key, T>* node)
                {
                    Node<Key, T>* current = node;
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL)
                        current = current->left;
                
                    return current;
                }

                // Node<Key, T>*getNodeToDeletePosition(Node<Key, T>* root, Key key)
                // {
                //     if (root == NULL)
                //         return root;
                //     if (key < root->getData()) // means key should be in the left subtree
                //         return getNodeToDeletePosition(root->left, key);
                //     else if (key > root->getData())
                //         return getNodeToDeletePosition(root->right, key);
                //     // key == root->getData() => key is the root Node;
                //     // node has no child
                //     if (root->left==NULL and root->right==NULL)
                //         return NULL;
                
                //     // node with only one child or no child
                //     else if (root->left == NULL) {
                //         Node<Key, T>* temp = root->right;
                //         delete(root);
                //         return temp;
                //     }
                //     else if (root->right == NULL) {
                //         Node<Key, T>* temp = root->left;
                //         delete(root);
                //         return temp;
                //     }
            
                //     // node with two children: Get the inorder successor
                //     // (smallest in the right subtree)
                //     Node<Key, T>* temp = minValueNode(root->right);
            
                //     // Copy the inorder successor's content to this node
                //     root->data = temp->data;
            
                //     // Delete the inorder successor
                //     root->right = deleteNode(root->right, temp->key);

                // }

                // void deleteNode(Key data)
                // {
                //     Node<Key, T>* nodeToDelete = getNodeToDeletePosition(this->_root, data);
                //     if (!nodeToDelete->right)
                //     {
                //         nodeToDelete->right = new Node<Key, T>("NIL", BLACK);
                //         nodeToDelete->right->parent = nodeToDelete;
                //     }
                //     if (!nodeToDelete->left)
                //     {
                //         nodeToDelete->left = new Node<Key, T>("NIL", BLACK);
                //         nodeToDelete->left->parent = nodeToDelete;
                //     } 
                // }

                /* Given a binary search tree and a key, this function
                    deletes the key and returns the new root */
                Node<Key, T>* deleteNode(Node<Key, T>* root, int k)
                {
                    // Base case
                    if (root == NULL)
                        return root;
                
                    // Recursive calls for ancestors of
                    // node to be deleted
                    if (root->key > k) {
                        root->left = deleteNode(root->left, k);
                        return root;
                    }
                    else if (root->key < k) {
                        root->right = deleteNode(root->right, k);
                        return root;
                    }
                
                    // We reach here when root is the node
                    // to be deleted.
                
                    // If one of the children is empty
                    if (root->left == NULL) {
                        Node<Key, T>* temp = root->right;
                        delete root;
                        return temp;
                    }
                    else if (root->right == NULL) {
                        Node <Key, T>* temp = root->left;
                        delete root;
                        return temp;
                    }
                
                    // If both children exist
                    else {
                
                        Node<Key, T>* succParent = root;
                
                        // Find successor
                        Node<Key, T>* succ = root->right;
                        while (succ->left != NULL) {
                            succParent = succ;
                            succ = succ->left;
                        }
                
                        // Delete successor.  Since successor
                        // is always left child of its parent
                        // we can safely make successor's right
                        // right child as left of its parent.
                        // If there is no succ, then assign
                        // succ->right to succParent->right
                        if (succParent != root)
                            succParent->left = succ->right;
                        else
                            succParent->right = succ->right;
                
                        // Copy Successor Data to root
                        root->key = succ->key;
                
                        // Delete Successor and return root
                        delete succ;
                        return root;
                    }
                }

                void printRBT()
                {
                    if (this->_root)
                    {
                        std::cout << _root->getData() << " - " << _root->getValue() << " - " << (_root->getColor()? "Red" : "Black") << std::endl;
                        if (_root->left)
                            _root->left->printNode('l');
                        if (_root->right)
                            _root->right->printNode('r');
                    }
                }
};

}


#endif