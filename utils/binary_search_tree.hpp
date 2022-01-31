/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 10:41:17 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/31 11:49:34 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>

namespace ft{

// BASIC BINARY SEARCH TREE CONSTRUCTOR

// class BST 
// {
//     int data;
//     BST *left, *right;

// public:
//     // Default constructor.
//     BST();

//     // Parameterized constructor.
//     BST(int);

//     // Insert function.
//     BST* Insert(BST*, int);

//     // Inorder traversal.
//     void Inorder(BST*);
// };
// // Default Constructor definition.
// BST ::BST()
//     : data(0)
//     , left(NULL)
//     , right(NULL)
// {
// }

// // Parameterized Constructor definition.
// BST ::BST(int value)
// {
//     data = value;
//     left = right = NULL;
// }

// // Insert function definition.
// BST* BST ::Insert(BST* root, int value)
// {
//     if (!root) 
//     {
//         // Insert the first node, if root is NULL.
//         return new BST(value);
//     }

//     // Insert data.
//     if (value > root->data) 
//     {
//         // Insert right node data, if the 'value'
//         // to be inserted is greater than 'root' node data.

//         // Process right nodes.
//         root->right = Insert(root->right, value);
//     }
//     else 
//     {
//         // Insert left node data, if the 'value'
//         // to be inserted is greater than 'root' node data.

//         // Process left nodes.
//         root->left = Insert(root->left, value);
//     }

//     // Return 'root' node, after insertion.
//     return root;
// }

// // Inorder traversal function.
// // This gives data in sorted order.
// void BST ::Inorder(BST* root)
// {
//     if (!root) {
//         return;
//     }
//     Inorder(root->left);
//     std::cout << root->data << std::endl;
//     Inorder(root->right);
// }











    // class Node
    // {
    //     public:
    //             // int key;
    //             int data;
    //             Node *left;
    //             Node *right;
    //             int height;
    // };

    // bool isEmpty(Node *tree) { return (tree == NULL); };

    // bool isLeaf(Node *node) { return (node->left == NULL && node->right == NULL); };

    // int size( Node *tree) { 
    //     if (!isEmpty(tree)) 
    //         return (1 + size(tree->left) + size(tree->right)); 
    //     else return 0;
    // }

    // Node *newNode(int data)
    // {
    //     Node *node = new Node();
    //     node->data = data;
    //     node->left = NULL;
    //     node->right = NULL;
    //     node->height = 1;
    //     return (node);
    // }

    // int height (Node *tree)
    // {
    //     if (tree == NULL)
    //         return 0;
    //     return (tree->height);
    // }

    // void print_BST(Node *tree)
    // {
    //     if (!isEmpty(tree))
    //     {
    //         std::cout << "\t\t";
    //         std::cout << tree->data << std::endl;
    //         print_BST(tree->left);
    //         std::cout << "\t";
    //         print_BST(tree->right);
    //     }
    // }
    
    // void insert (Node *tree, int data)
    // {
    //     if (isEmpty(tree))
    //     {
    //         Node *new_node = new Node;
    //         if (tree->data > data)
    //             tree->left = new_node;
    //         else if (tree->data <= data)
    //             tree->left = new_node;
    //         new_node->data = data;
    //         new_node->left = NULL;
    //         new_node->right =  NULL;
    //     }
    //     else
    //     {
    //         if (data < tree->data)
    //             insert (tree->left, data);
    //         else insert (tree->right, data);    
    //     }
    // }
    
}

#endif