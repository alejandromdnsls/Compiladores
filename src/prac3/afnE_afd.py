#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
from CONV.AFNE_AFD import *

def main():

    file = File('si2.txt')
    file.read()
    file.close_file()

    afd = AFD(file.getContent)

    quintupla = Quintupla(file.getContent)

    afd.inicializar_ce(quintupla.getS[0])

    afd.c_e(quintupla.getS[0])

    aux = afd.ir_a(afd.getC_E, quintupla.getSigma[1])

    print(aux)



if __name__ == '__main__':
    main()
