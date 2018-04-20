#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *
#from CONV.AFNE_AFD import *
from CONV.Convertir import *

def main():

    file = File('Thompson2.txt')
    file.read()
    file.close_file()

    #quintupla = Quintupla(file.getContent)

    afd = AFD(file.getContent)

    afd.convertir()
    afd.mostrar_tabla()

if __name__ == '__main__':
    main()
