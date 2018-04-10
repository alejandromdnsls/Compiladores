#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from AFN.Afn import *
from STRING.String import *
from TAD.Queue import *

# Constantes

def main():
    file = File('1.txt')
    file.read()

    quintupla = Quintupla(file.getContent)
    Q = quintupla.getQ
    sigma = quintupla.getSigma
    S = quintupla.getS
    F = quintupla.getF
    delta = quintupla.getDelta

    print("Q -> {}".format(Q))
    print("Sigma -> {}".format(sigma))
    print("S -> {}".format(S))
    print("F -> {}".format(F))
    print("Delta -> {}".format(delta))

    string = String()
    string.setString()
    string.check_string(True)

    while True:
        if(string.match_sigma(sigma)):
            break
        else:
            string.check_string(False)
            string.check_string(True)

    queue = Queue()

    print(queue.is_empty())

    queue.add('a')

    print(queue.length())

    file.close_file()

if __name__ == '__main__':
    main()
