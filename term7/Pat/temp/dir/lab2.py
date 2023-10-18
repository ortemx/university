# a = 5
# from lab1 import b
from pprint import pprint
import sys
sys.path.append(sys.path[0]+"..\\..")
from lab1 import b


pprint(sys.path)
print(b)