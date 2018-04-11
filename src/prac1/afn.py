#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from AFN.Afn import *
from STRING.String import *


def main():
    file = File('4.txt')
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
    #string.check_string(True)

    while True:
        if(string.match_sigma(sigma)):
            break
        """
        else:
            string.check_string(False)
            string.check_string(True)"""

    afn = Afn(file.getContent)

    camino = ""

    flag = afn.recorrer(string.getString, afn.start_state()[0], camino)

    if flag == False:
        print("No valido")
    else:
        print("Valido")


    file.close_file()

if __name__ == '__main__':
    main()
