from itertools import product
import os

os.chdir("/home/kaustav/Desktop/competitive-programming/")
# os.chdir("/home/kaustav/Desktop/competitive-programming/InterviewBit/Contests/CodeDriftAugust")
files = os.listdir('.')

""" 
i/p: nA.cpp nB.cpp nC.cpp
o/p: n1.cpp n2.cpp n3.cpp
"""

print(files)

for file in files:
    filename, file_extension = os.path.splitext(file)

    print(filename, file_extension)

    if file_extension != ".cpp":
        continue

    mylist = list(filename)
    print("debug => ", ord(mylist[-1]) - 64)
    mylist[-1] = str(ord(mylist[-1]) - 64)
    newFilename = ''.join(mylist)
    os.rename(file, newFilename + file_extension)


print(files)
