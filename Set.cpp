//
// Created by MRV on 29.11.2021.
//

#include "Set.h"

Set::Set(int n) : n(n){
    members = new Member[n];
    match = new int[n];
    for (int i = 0; i < n; i++) {
        Subset* temp = new Subset(i);
        members[i].begin = temp->first;
        members[i].end = temp->first;
        match[i] = i;
    }
}

void Set::merge(int first, int second) {
    Subset::Node* cur = members[second].begin;
    while (cur){
        match[cur->get_info()] = first;
        cur = cur->get_next();
    }
    members[first].end->set_next(members[second].begin);
    members[first].end = members[second].end;
    members[second].begin = nullptr;
    members[second].end = nullptr;
    members[first].size += members[second].size;
    members[second].size = 0;
}

int Set::find(int i) {
    return match[i];
}

void Set::Union(int i, int j) {
    int first = find(i);
    int second = find(j);
    int size_first = members[first].size;
    int size_second = members[second].size;
    if (size_first > size_second) merge(first, second);
    else merge(second, first);

}
