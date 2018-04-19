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

    states_ce = ""
    afd.C_E(quintupla.getS[0])
    print(afd.getC_E)

    afd.MOVER()
    print(afd.getMover)



if __name__ == '__main__':
    main()
