#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from AFN.Afn import *
# Constantes

# Clases
# ---------------------------------------------------------------------

# ---------------------------------------------------------------------

# Funciones
# ---------------------------------------------------------------------

# ---------------------------------------------------------------------

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


    file.close_file()

if __name__ == '__main__':
    main()
