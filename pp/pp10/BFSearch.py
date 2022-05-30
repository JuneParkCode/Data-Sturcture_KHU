from GraphType import *

def breadth_first_search(graph, startVertex, endVertex):
    queue = QueType()
    vertexQ = QueType()
    found = False

    
    '''[10]'''
    vertex = startVertex
    graph.clear_marks()
    while not found :
        print(vertex)
        found = vertex is endVertex
        if (found) :
            return
        fIdx = graph.vertices.index(vertex)
        graph.mark_vertex(vertex)
        for i in range (0, graph.numVertices):
            if graph.edges[fIdx][i] is not 0 :
                queue.enqueue(graph.vertices[i])
        if (queue.is_empty()):
            return
        vertex = queue.dequeue()
        