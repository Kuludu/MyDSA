#ifndef MyGraph_H_
#define MyGraph_H_

namespace MyGraphNamespace {
    template<class T>
    struct Edge {
        T value;
        Edge<T> *next_edge;
    };
    
    template<class T>
    struct Vertex {
        T value;
        int id;
        Vertex<T> *next_vertex;
    };
    
    template<class T>
    class MyGraph {
    public:
        void create_vertex(int, T);
    private:
        Vertex<T> *vertex_head;
        Edge<T> *edge_head;
    };

    template<class T>
    void MyGraph<T>::create_vertex(int id, T value) {
        Vertex<T> *current = this->vertex_head;
        while (vertex_head != 0) {
            current = current->next_vertex;
        }

        current = new Vertex<T>;
        current->id = id;
        current->value = value;
    }
}

#endif