#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from AFN.Afn import *
from STRING.String import *


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
    str_toval = input("Cadena: ")
    string.setString(str_toval)

    while True:
        if(string.match_sigma(sigma)):
            break
        else:
            str_toval = input("Ingresa una cadena que pertenezca al alfabeto: ")
            string.setString(str_toval)

    afn = Afn(file.getContent)

    camino = ""

    flag = afn.recorrer(string.getString, afn.start_state()[0], camino)

    if afn.ask_strVal(flag):
        print("Cadena válida en: ")
        afn.imprimir_camino(camino)
    else:
        print("Cadena no válida")

    file.close_file()

if __name__ == '__main__':
    main()
