//
// Created by MRV on 29.11.2021.
//

#ifndef AADP_29_11_2021_SET_H
#define AADP_29_11_2021_SET_H

class Set {
    class Subset {
    public:
        Subset(int i){
            first = new Node(i);
        }
        class Node {
            int info;
            Node *next;
        public:
            Node(int info) : info(info), next(nullptr) {}

            Node(int info, Node *next) : info(info), next(next) {}

            int get_info() const {
                return info;
            }

            void set_info(int info) {
                Node::info = info;
            }

            Node *get_next() const {
                return next;
            }

            void set_next(Node *next) {
                Node::next = next;
            }
        };
        Node *first;
    };
    class Member{
    public:
        Subset::Node* begin;
        Subset::Node* end;
        int size;
    };
    
    Member* members;
    int n;
    int* match;
private:
    void merge(int first, int second);

public:
    Set(int n);
    int find(int i);
    void Union(int i, int j);

};

#endif //AADP_29_11_2021_SET_H
