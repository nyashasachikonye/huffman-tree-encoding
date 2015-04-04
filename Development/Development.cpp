/*
 * File:   Development.cpp
 * Author: Sach
 *
 * Created on 03 April 2015, 6:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 *
 */

typedef bool(*fptr)(int, int); //any function matching the signature: bool fptr(int,int)

bool comp(int a, int b)
    {
    return a > b;
    }

int main(int argc, char** argv)
    {

    std::priority_queue<int, std::vector<int>, fptr > q(comp);
    q.push(5);
    q.push(1);
    q.push(6);
    q.push(3);
    printf("top val %d\n", q.top());
    q.pop();
    printf("top val %d\n", q.top());
    q.pop();
    printf("top val %d\n", q.top());
    q.pop();
    printf("top val %d\n", q.top());
    q.pop();
    return 0;
    }
