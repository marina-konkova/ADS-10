// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    bool isRoot = false;
    char value;
    std::vector<Node*> indicator;
};

class Tree {
 private:
    Node* root;
    std::vector<std::vector<char>> ps;
    void insert(Node* root, const std::vector<char>& vec) {
        for (char c : vec) {
            Node* tmp = new Node;
            tmp->value = c;
            root->indicator.push_back(tmp);
            std::vector<char> remainingChars(vec);
            remainingChars.erase(std::find(remainingChars.begin(), \
                remainingChars.end(), c));
            insert(tmp, remainingChars);
        }
    }
    void findPerms(Node* root, std::vector<char> vec) {
        if (!root->isRoot)
            vec.push_back(root->value);
        if (root->indicator.empty()) {
            ps.push_back(vec);
        } else {
            for (Node* child : root->indicator) {
                findPerms(child, vec);
            }
        }
    }

 public:
    explicit Tree(const std::vector<char>& vec) {
        root = new Node;
        root->isRoot = true;
        insert(root, vec);
        std::vector<char> current;
        findPerms(root, current);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return ps;
    }
};
#endif  // INCLUDE_TREE_H_
