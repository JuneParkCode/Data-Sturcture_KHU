from GraphType import *

def depth_first_search(graph, startVertex, endVertex):
    stack = StackType()
    vertexQ = QueType()
    found = False

    '''[9]'''
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
            if graph.edges[fIdx][i] != 0 :
                stack.push(graph.vertices[i])
        if (stack.is_empty()):
            return
        vertex = stack.top()
        stack.pop()

        