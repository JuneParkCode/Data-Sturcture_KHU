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

    def add_edge(self, fromVertex, toVertex, weight):
        '''[2]'''


    def weight_is(self, fromVertex, toVertex):
        '''[3]'''


    def get_to_vertices(self, vertex, adjVertices):
        '''[4]'''



    def clear_marks(self):
        '''[5]'''


    def is_marked(self, vertex):
        '''[6]'''


    def mark_vertex(self, vertex):
        '''[7]'''


    def delete_edge(self, fromVertex, toVertex):
        '''[8]'''

