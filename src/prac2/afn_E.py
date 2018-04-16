#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from STRING.String import *
from AFNE.AfnE import *

def main():
    file = File('0.txt')
    file.read()

    quintupla = Quintupla(file.getContent)

    file.close_file()

    print("Q -> {}".format(quintupla.getQ))
    print("Sigma -> {}".format(quintupla.getSigma))
    print("S -> {}".format(quintupla.getS))
    print("F -> {}".format(quintupla.getF))
    print("Delta -> {}".format(quintupla.getDelta))

    string = String()
    str_toval = input("Cadena: ")
    string.setString(str_toval)

    while True:
        if(string.match_sigma(quintupla.getSigma)):
            break
        else:
            str_toval = input("Ingresa una cadena que pertenezca al alfabeto: ")
            string.setString(str_toval)


if __name__ == '__main__':
    main()
