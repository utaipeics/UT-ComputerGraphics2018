#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys

simple_triangles = []
colored_triangles = []
defined_vertices = []
current_triangle_data = []

class Vertex:
    """ Contains the (x,y,z) and (nx, ny, nz) of a vertex """
    def __init__(self, vertex_data_list:list):
        self.vertex_data_list = vertex_data_list

    def __str__(self):
        return " ".join(self.vertex_data_list)

    def __eq__(self, other):
        if isinstance(other, Vertex):
            return self.vertex_data_list == other.vertex_data_list
        return False


class Colors:
    """ Contains the front_colors list [fr, fg, fb] and back_colors list [br, bg, bb] """
    def __init__(self, colors_data:list):
        self.front_colors = colors_data[0:3]
        self.back_colors = colors_data[3:6]

    def __str__(self):
        return " ".join(self.front_colors) + " " + " ".join(self.back_colors)


class SimpleTriangle:
    """ Contains three vertices. No colors. """
    def __init__(self, vertices_id_list:list):
        self.vertices_id_list = vertices_id_list

    def __str__(self):
        return " ".join(self.vertices_id_list)


class ColoredTriangle(SimpleTriangle):
    """ Contains three vertices. Has colors. """
    def __init__(self, colors:Colors, vertices_id_list:list):
        SimpleTriangle.__init__(self, vertices_id_list)
        self.colors = colors

    def __str__(self):
        return " ".join(self.vertices_id_list) + " " + self.colors.__str__()


def build():
    vertices_id = []

    if len(current_triangle_data) == 3: # simple triangle
        for i in range(0, 3):
            v = Vertex(current_triangle_data[i].split(' '))
            # If this vertex has already been defined,
            # we find its index in the list and append the index to vertices_id.
            if v in defined_vertices:
                vertices_id.append(str(defined_vertices.index(v)))
            # Otherwise, we append the new vertex to defined_vertices
            # and append its index (which is the last item in defined_vertices)
            # to vertices_id.
            else:
                defined_vertices.append(v)
                vertices_id.append(str(len(defined_vertices) - 1))

        # Create a simple triangle using vertices_id.
        simple_triangles.append(SimpleTriangle(vertices_id))

    elif len(current_triangle_data) == 4: # colored triangle
        colors = Colors(current_triangle_data[0].split(' '))

        for i in range(1, 4):
            v = Vertex(current_triangle_data[i].split(' '))

            # If this vertex has already been defined,
            # we find its index in the list and append the index to vertices_id.
            if v in defined_vertices:
                vertices_id.append(str(defined_vertices.index(v)))
            # Otherwise, we append the new vertex to defined_vertices
            # and append its index (which is the last item in defined_vertices)
            # to vertices_id.
            else:
                defined_vertices.append(v)
                vertices_id.append(str(len(defined_vertices) - 1))

        # Create a simple triangle using vertices_id.
        colored_triangles.append(ColoredTriangle(colors, vertices_id))


def parse(tri_file:str): 
    with open(tri_file, 'r') as f: 
        for line in f:
            line = line.rstrip()

            if line == 'Triangle':
                build()
                current_triangle_data.clear()
            else:
                current_triangle_data.append(line)

        # Write the last record.
        build()

    with open(tri_file.lower().split('.tri')[0] + '_new.tri', 'w') as f:
        f.write('Simple: ' + str(len(simple_triangles)) + '\n')
        f.write('Color: ' + str(len(colored_triangles)) + '\n')
        f.write('Vertices: ' + str(len(defined_vertices)) + '\n')

        count = 0
        for st in simple_triangles:
            f.write(str(count) + " " + st.__str__() + '\n')
            count += 1

        count = 0
        for ct in colored_triangles:
            f.write(str(count) + " " + ct.__str__() + '\n')
            count += 1

        count = 0
        for v in defined_vertices:
            f.write(str(count) + " " + v.__str__() + '\n')
            count += 1


def print_help():
    print("Usage: {0} <filename.tri>".format(sys.argv[0]))

def print_version():
    print("Tri Model Format Converter 1.0\n"
          "Copyright (C) 2018 Marco Wang\n"
          "\n"
          "This is free software, see the source for copying conditions.  There is NO\n"
          "warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE")


if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print_help()
    elif sys.argv[1] == '-v' or sys.argv[1] == '--version':
        print_version()
    else:
        parse(sys.argv[1])
