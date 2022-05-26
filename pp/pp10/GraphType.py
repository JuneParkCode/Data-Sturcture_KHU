from QueType import *
from StackType import *

NULL_EDGE = 0

def index_is(vertices, vertex):
    index = 0

    while index < len(vertices) and vertex != vertices[index]:
        index += 1

    if not index < len(vertices):
        return -1
    else:
        return index

class GraphType:
    def __init__(self, maxV=50):
        self.numVertices = 0
        self.maxVertices = maxV
        self.vertices = [None] * maxV
        self.edges = [[NULL_EDGE] * maxV for _ in range(maxV)]
        self.marks = [None] * maxV

    def add_vertex(self, vertex):
        '''[1]'''
        if (self.maxVertices <= self.numVertices) :
            return 
        self.vertices[self.numVertices] = vertex
        self.numVertices += 1

    def add_edge(self, fromVertex, toVertex, weight):
        '''[2]'''
        if (fromVertex not in self.vertices or toVertex not in self.vertices) :
            return
        fIdx = self.vertices.index(fromVertex)
        tIdx = self.vertices.index(toVertex)
        self.edges[fIdx][tIdx] = weight

    def weight_is(self, fromVertex, toVertex):
        '''[3]'''
        if (fromVertex not in self.vertices or toVertex not in self.vertices) :
            return
        fIdx = self.vertices.index(fromVertex)
        tIdx = self.vertices.index(toVertex)
        return self.edges[fIdx][tIdx]

    def get_to_vertices(self, vertex, adjVertices):
        '''[4]'''
        if (vertex not in self.vertices) :
            return
        tIdx = self.vertices.index(vertex)
        if (tIdx == -1) :
            return
        idx = 0 
        while (idx < self.numVertices) :
            if (self.edges[idx][tIdx] is not 0) :
                adjVertices.append(self.vertices[idx])
            idx += 1

    def clear_marks(self):
        '''[5]'''
        for mark in self.marks :
            mark = None

    def is_marked(self, vertex):
        '''[6]'''
        if (vertex not in self.vertices) :
            return
        tIdx = self.vertices.index(vertex)
        return (self.marks[tIdx] != None)

    def mark_vertex(self, vertex):
        '''[7]'''
        if (vertex not in self.vertices) :
            return
        tIdx = self.vertices.index(vertex)
        self.marks[tIdx] != True

    def delete_edge(self, fromVertex, toVertex):
        '''[8]'''
        if (fromVertex not in self.vertices or toVertex not in self.vertices) :
            return
        fIdx = self.vertices.index(fromVertex)
        tIdx = self.vertices.index(toVertex)
        self.edges[fIdx][tIdx] = None