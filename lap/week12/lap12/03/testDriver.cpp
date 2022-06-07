#include "GraphType.h"

using namespace std;

int main(void)
{
    GraphType<char *> graph;

    graph.AddVertex("Dog");
    graph.AddVertex("Cat");
    graph.AddVertex("Animal");
    graph.AddVertex("Vertebrate");
    graph.AddVertex("Oyster");
    graph.AddVertex("Shellfish");
    graph.AddVertex("Invertebrate");
    graph.AddVertex("Crab");
    graph.AddVertex("Poodle");
    graph.AddVertex("Monkey");
    graph.AddVertex("Banana");
    graph.AddVertex("Dalmatian");
    graph.AddVertex("Dachshund");

    graph.AddEdge("Vertebrate", "Animal", 10);
    graph.AddEdge("Invertebrate", "Animal", 20);
    graph.AddEdge("Dog", "Vertebrate", 40);
    graph.AddEdge("Cat", "Vertebrate", 50);
    graph.AddEdge("Monkey", "Vertebrate", 50);
    graph.AddEdge("Shellfish", "Invertebrate", 60);
    graph.AddEdge("Crab", "Shellfish", 70);
    graph.AddEdge("Oyster", "Invertebrate", 80);
    graph.AddEdge("Poodle", "Dog", 90);
    graph.AddEdge("Dalmatian", "Dog", 100);
    graph.AddEdge("Dachshund", "Dog", 110);

    graph.DepthFirstSearch("Dalmatian", "Animal");
}