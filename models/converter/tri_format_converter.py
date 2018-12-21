#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import sys

simple_triangles = []
colored_triangles = []
defined_vertices = []
current_triangle_data = []

class Vertex:
    """ Contains the [x, y, z, nx, ny, nz] of a vertex """
    def __init__(self, vertex_data:list):
        self.vertex_data = vertex_data # [x, y, z, nx, ny, nz]

    def __str__(self):
        return " ".join(self.vertex_data)

    def __eq__(self, other):
        if isinstance(other, Vertex):
            return self.vertex_data == other.vertex_data
        return False


class Colors:
    """ Contains the front_colors and back_colors list [fr, fg, fb, br, bg, bb] """
    def __init__(self, colors_data:list):
        self.front_colors = colors_data[0:3] # [fr, fg, fb]
        self.back_colors = colors_data[3:6] # [br, bg, bb]

    def __str__(self):
        return " ".join(self.front_colors) + " " + " ".join(self.back_colors)


class SimpleTriangle:
    """ Contains three vertices. No colors. """
    def __init__(self, vertices_ids:list):
        self.vertices_ids = vertices_ids # [v1, v2, v3]

    def __str__(self):
        return " ".join(self.vertices_ids)


class ColoredTriangle(SimpleTriangle):
    """ Contains three vertices. Has colors. """
    def __init__(self, colors:Colors, vertices_ids:list):
        SimpleTriangle.__init__(self, vertices_ids)
        self.colors = colors

    def __str__(self):
        return " ".join(self.vertices_ids) + " " + self.colors.__str__()


def build_record():
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
        total_lines_count = sum(1 for line in f)

    with open(tri_file, 'r') as f: 
        count = 0
        for line in f:
            line = line.rstrip()
            if 'Triangle' in line:
                build_record()
                current_triangle_data.clear()
            else:
                current_triangle_data.append(line)
            count += 1
            sys.stdout.write("Processing: {f} (Parsed {n} / {total} lines)\r".format(
                f=tri_file, n=count, total=total_lines_count))
            sys.stdout.flush()
        # Write the last record.
        build_record()


def write_result(tri_file:str):
    with open(tri_file, 'w') as f:
        # Write metadata.
        f.write('Simple: ' + str(len(simple_triangles)) + '\n')
        f.write('Color: ' + str(len(colored_triangles)) + '\n')
        f.write('Vertices: ' + str(len(defined_vertices)) + '\n')

        # Write all simple triangles.
        count = 0
        for st in simple_triangles:
            f.write(str(count) + " " + st.__str__() + '\n')
            count += 1

        # Write all colored triangles.
        count = 0
        for ct in colored_triangles:
            f.write(str(count) + " " + ct.__str__() + '\n')
            count += 1

        # Write all defined vertices.
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
        current = 1
        while current < len(sys.argv):
            input_file = sys.argv[current]
            new_file = input_file.split('.TRI')[0] + '_new.tri'
            parse(input_file)
            write_result(new_file)
            
            simple_triangles.clear()
            colored_triangles.clear()
            defined_vertices.clear()
            current_triangle_data.clear()

            print("Converted file written to {f}\n".format(f=new_file))
            current += 1
