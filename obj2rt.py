#!/usr/bin/env python3
import sys

lines = sys.stdin.readlines()
vertices = []
faces = []

for line in lines:
        line = line.split(" ")
        if line[0] == "v":
                x = float(line[1])
                z = float(line[2])
                y = float(line[3])
                vertices.append((x, y, z))
        if line[0] == "f":
                assert len(line) == 4
                a = int(line[1].split("/")[0]) - 1
                b = int(line[2].split("/")[0]) - 1
                c = int(line[3].split("/")[0]) - 1
                faces.append((a, b, c))

sys.stdout.write(f"C 0,0,0 1,0,0 90\n")
sys.stdout.write(f"A 0.1 255,255,255\n")
sys.stdout.write(f"sp -8,0,8 20.0 emitter 1.0 255,255,255 255,255,255\n")
for face in faces:
        a = ",".join(f"{v}" for v in vertices[face[0]])
        b = ",".join(f"{v}" for v in vertices[face[1]])
        c = ",".join(f"{v}" for v in vertices[face[2]])
        sys.stdout.write(f"tr {a} {b} {c} 191,191,191\n")
