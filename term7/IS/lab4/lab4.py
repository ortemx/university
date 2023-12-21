'''
SIDNEY METRO
'''
from math import inf
import sys

stations = [
    "North Starthfield",
    "Starthfield",
    "Lidcombe",
    "Auburn",
    "Parramatta",
    "Harris Park",
    "Guilford",
    "Fairfield",
    "Canley Vale",
    "Cabramatta",
    "Liverpool",
    "Carramar",
    "Leightinfield",
    "Sefton",
    "Berala",
    "Regent Park",
    "Birrong"    
]

edges = {
    0 : [
        {1 : 11}
    ],
    1 : [
        {0 : 11},
        {2 : 6.6}
    ],
    2 : [
        {1 : 6.6},
        {3 : 2.4},
        {14 : 1.8}
    ],
    3 : [
        {2 : 2.4},
        {5 : 6.3}
    ],
    4 : [
        {5 : 1.8}
    ],
    5 : [
        {3 : 6.3},
        {4 : 1.8},
        {6 : 4.9}
    ],
    6 : [
        {5 : 4.9},
        {7 : 3.9}
    ],
    7 : [
        {6 : 3.9},
        {8 : 2.5}
    ],
    8 : [
        {7 : 2.5},
        {9 : 2.1}
    ],
    9 : [
        {8 : 2.1},
        {10 : 4.8},
        {11 : 5.5}
    ],
    10 : [
        {9 : 4.8}        
    ],
    11 : [
        {9 : 5.5},
        {12 : 4}
    ],
    12 : [
        {11 : 4},
        {13 : 2.5}
    ],
    13 : [
        {12 : 2.5},
        {15 : 1.2},
        {16 : 1.7}
    ],
    14 : [
        {2 : 1.8},
        {15 : 1.8}        
    ],
    15 : [
        {13 : 1.2},
        {14 : 1.8},
        {16 : 1.1}
    ],
    16 : [
        {13 : 1.7},
        {15 : 1.1}
    ]
}

