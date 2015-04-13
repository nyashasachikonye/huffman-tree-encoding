/**
 INSTRUCTIONS:
 In this session you get to play around with concepts you learnt about earlier this week:
        1. use smart pointers to construct an acyclic directional sparce graph.
        2. use catch.hpp to unit test your code through some very simple examples

 NOTE:
 I've clearly marked lines in the code that should be commented or uncommented for each of the 3 tasks.
 You DON'T have to write any code for the first 3 tasks: instead peruse each separate case carefully to
 ensure that you see the differences between the 3 implementations.

 TASK 1
        1. In the first implementation we used raw pointers without appropriate destructors to simulate
         a memory leak. Ensure the lines marked with "<-----------------ENABLE ONLY FOR TASK 1..." is uncommented.
        2. Compile the program with g++ -o tut tut.cpp --std=c++11 and run using ./solution
        3. You should see that the program is leaking memory. Now scroll down to the test cases and look
         at what was done: I've instantiated an automatic Graph variable inside an inner scope. As soon
         as that scope closes Graph (along with all its resources) should be destroyed according to the RAII paradigm.
         Since we didn't implement the destructor the Graph object is leaking memory!
 TASK 2
         Using shared pointers partially fixes the problem for everything but the cyclic case. Go disable the lines
         that are not used in task 2 and enable the appropriate lines.
                Q1. Why can't you use unique pointers here?
 TASK 3
         Now disable the lines not being used in this task. Enable the lines for task 3. You should see all the test
         cases pass.
                Q2. Peruse the changes we've made for the Node class. What have we done differently here? Why was it necessary
                 (explain this in terms of the lifetime of the managed Node objects).

         Type in your answers on vula

 Optional Challenge (after reading more on catch.hpp):
         Implement a copy constructor for the GRAPH class. Remember a copy constructor takes a reference (why?). What type of
         reference should this be (tip: we're not modifying the object we're attempting to copy)? Try and write some test cases
         for this!
         NOTE: Don't just copy accross the pointers. Allocate new Nodes with duplicate data (ie. make a deep copy)
 */
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#define CATCH_CONFIG_MAIN //So that catch will define a main method
#include "catch.hpp"
#include "counter.h"

class Graph; //forward declare so that we can befriend this class

class Node : public sjp::counter<Node>
    {
    friend class Graph; //why do we need to do this
private:
    std::string datum;
    std::size_t my_index;
    std::vector<Node *> neighbours; //<--------------------------------------ENABLE ONLY FOR TASK 1
    //std::vector<std::shared_ptr<Node>> neighbours; //<---------------------ENABLE ONLY FOR TASK 2
    //std::vector<std::weak_ptr<Node>> neighbours; //<-----------------------ENABLE ONLY FOR TASK 3

    Node(std::string val, std::size_t index) : datum(val), my_index(index) { } //only the graph may construct nodes
public:

    std::size_t get_index()
        {
        return my_index;
        }

    std::string get_value()
        {
        return datum;
        }

    virtual ~Node() { }
    };

class Graph
    {
private:
    std::vector<Node *> nodes; //<---------------------------------------------ENABLE ONLY FOR TASK 1
    //std::vector<std::shared_ptr<Node>> nodes; //<----------------------------ENABLE ONLY FOR TASKS 2 & 3
public:

    Graph() { }

    std::size_t add_node(std::string value)
        {
        Node * new_node = new Node(value, nodes.size()); //<---------------------------------ENABLE ONLY FOR TASK 1
        //std::shared_ptr<Node> new_node(new Node(value,nodes.size())); //<-----------------ENABLE ONLY FOR TASKS 2 & 3
        nodes.push_back(new_node);
        return nodes.size() - 1; //id to the new node
        }

    void connect(std::size_t from, std::size_t to)
        {
        if (from >= nodes.size())
            throw std::runtime_error("Invalid from index");
        if (to >= nodes.size())
            throw std::runtime_error("Invalid to index");
        nodes[from]->neighbours.push_back(nodes[to]);
        }

    bool is_connected(std::size_t from, std::size_t to)
        {
        if (from >= nodes.size())
            throw std::runtime_error("Invalid from index");
        if (to >= nodes.size())
            throw std::runtime_error("Invalid to index");
        for (auto neigh = nodes[from]->neighbours.begin(); neigh != nodes[from]->neighbours.end(); ++neigh)
            {
            if ((*neigh)->get_index() == to) return true; //<-----------------------------------ENABLE ONLY FOR TASKS 1 & 2
            //if ((*neigh).lock()->get_index() == to) return true; //<---------------------------------ENABLE ONLY FOR TASK 3
            }
        return false; //not found
        }

    void print()
        {
        using namespace std;
        for (auto i = nodes.begin(); i != nodes.end(); ++i)
            {
            cout << (*i)->get_value() << " has the following connections: " << endl;
            for (auto neigh = (*i)->neighbours.begin(); neigh != (*i)->neighbours.end(); ++neigh)
                {
                cout << "\t" << (*neigh)->get_value() << endl; //<-----------------------------ENABLE ONLY FOR TASKS 1 & 2
                //cout << "\t" << (*neigh).lock()->get_value() << endl; //<--------------------ENABLE ONLY FOR TASK 3
                }
            }
        }
    //if implemented using raw pointers this object will leak memory because we haven't implemented the destructor correctly
    //Remember: an automatic variable is destroyed when the scope "{ }" it was declared in closes (ie. as soon as "}" is encountered)
    //--- the RAII paradigm. However, an automatic variable is responsible to clean up any dynamically allocated resources (memory,
    //file pointers, etc.)

    virtual ~Graph() { }
    };
//<-------------------------------------TAKE A LOOK AT THESE SIMPLE TEST CASES FOR TASK 1 --------------------------------------------->

TEST_CASE("INSERTION", "This tests simple insertion")
    {
    {
        Node::alive = 0;
        std::cout << "SIMPLE INSERTION TEST" << std::endl;
        Graph g;
        std::size_t a = g.add_node("a");
        std::size_t b = g.add_node("b");
        REQUIRE(Node::alive == 2);
    }
    REQUIRE(Node::alive == 0);
    }

TEST_CASE("ACYCLIC CONNECTION", "This tests a simple acyclic case")
    {
    {
        Node::alive = 0;
        std::cout << "ACYCLIC DIRECTIONAL GRAPH" << std::endl;
        std::cout << "a -> b --\\/" << std::endl;
        std::cout << "  -> c -->d" << std::endl;
        Graph g;
        std::size_t a = g.add_node("a");
        std::size_t b = g.add_node("b");
        std::size_t c = g.add_node("c");
        std::size_t d = g.add_node("d");
        REQUIRE_THROWS(g.connect(3, 4));
        REQUIRE_THROWS(g.connect(4, 3));
        REQUIRE_THROWS(g.is_connected(3, 4));
        REQUIRE_THROWS(g.is_connected(4, 3));
        g.connect(a, b);
        g.connect(a, c);
        g.connect(c, d);
        g.connect(b, d);
        REQUIRE(g.is_connected(a, b));
        REQUIRE_FALSE(g.is_connected(b, a));
        REQUIRE_FALSE(g.is_connected(b, c));
        REQUIRE(g.is_connected(b, d));
        REQUIRE(g.is_connected(a, c));
        REQUIRE_FALSE(g.is_connected(c, a));
        REQUIRE_FALSE(g.is_connected(c, b));
        REQUIRE(g.is_connected(c, d));
        REQUIRE_FALSE(g.is_connected(d, c));
        REQUIRE_FALSE(g.is_connected(d, a));
        REQUIRE_FALSE(g.is_connected(d, b));
        g.print();
        REQUIRE(Node::alive == 4);
    }
    REQUIRE(Node::alive == 0);

    }

TEST_CASE("CYCLIC CONNECTION", "This tests the cyclic connection case")
    {
    {
        Node::alive = 0;
        std::cout << "CYCLIC DIRECTIONAL GRAPH" << std::endl;
        std::cout << "a ---> b" << std::endl;
        std::cout << "^  |-> c ---|" << std::endl;
        std::cout << "|          \\/" << std::endl;
        std::cout << "------------d" << std::endl;
        Graph g;
        std::size_t a = g.add_node("a");
        std::size_t b = g.add_node("b");
        std::size_t c = g.add_node("c");
        std::size_t d = g.add_node("d");
        REQUIRE_THROWS(g.connect(3, 4));
        REQUIRE_THROWS(g.connect(4, 3));
        REQUIRE_THROWS(g.is_connected(3, 4));
        REQUIRE_THROWS(g.is_connected(4, 3));
        g.connect(a, b);
        g.connect(a, c);
        g.connect(c, d);
        g.connect(d, a);
        REQUIRE(g.is_connected(a, b));
        REQUIRE_FALSE(g.is_connected(b, a));
        REQUIRE_FALSE(g.is_connected(b, c));
        REQUIRE_FALSE(g.is_connected(b, d));
        REQUIRE(g.is_connected(a, c));
        REQUIRE_FALSE(g.is_connected(c, a));
        REQUIRE_FALSE(g.is_connected(c, b));
        REQUIRE(g.is_connected(c, d));
        REQUIRE_FALSE(g.is_connected(d, c));
        REQUIRE(g.is_connected(d, a));
        REQUIRE_FALSE(g.is_connected(d, b));
        g.print();
        REQUIRE(Node::alive == 4);
    }
    REQUIRE(Node::alive == 0);

    }
