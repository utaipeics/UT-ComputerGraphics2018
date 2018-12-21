#!/usr/bin/env python3

import sys

if __name__ == '__main__':
    current = 1
    while current < len(sys.argv):
        f_new = open(sys.argv[current] + "final.tri", 'w')

        with open(sys.argv[current], 'r') as f:
            for line in f:
                f_new.write(line.replace('\n', '\r\n'))

        f_new.close()
        current += 1
