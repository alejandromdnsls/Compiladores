#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Módulos personales
from FILE.File import *

# Constantes

# Clases
# ---------------------------------------------------------------------

# ---------------------------------------------------------------------

# Funciones
# ---------------------------------------------------------------------
def getQ(content):
    return content[0]
def getSigma(content):
    return content[1]
def getS(content):
    return content[2]
def getF(content):
    return content[3]
def getDelta(content):
    return content[4:len(content)+1]

# ---------------------------------------------------------------------

def main():
    file = File('1.txt')
    file.read()
    Q = getQ(file.getContent)
    sigma = getSigma(file.getContent)
    S = getS(file.getContent)
    F = getF(file.getContent)
    delta = getDelta(file.getContent)




    file.close_file()

if __name__ == '__main__':
    main()
