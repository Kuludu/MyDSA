#include "Graph.hpp"
#include <iostream>
using namespace MyGraphNamespace;
using std::cout;
using std::endl;

int main() {
    cout << "An example of MyGraph class." << endl;

    MyGraph<int> *graph = new MyGraph<int>;
    graph->create_vertex(1, 1);

    return 0;
}