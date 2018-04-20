from CONV.AFNE_AFD import *
from CONV.AFNE import *

class AFD:

    allC_E = []
    tabla_info = []
    sinonimos = []

    def __init__(self, content):
        self.algoritmo = Algoritmo(content)
        self.quintupla = Quintupla(content)

    def convertir(self):

        self.algoritmo.inicializar_ce(self.algoritmo.getInicial)
        self.algoritmo.c_e(self.algoritmo.getInicial)
        self.allC_E.append(self.algoritmo.getAlcanzables)

        len_sigma = len(self.quintupla.getSigma)

        for alcanzables_e in self.allC_E:
            i = 0
            finish = False
            for simbolo in self.quintupla.getSigma:
                aux = []
                self.algoritmo.ir_a(alcanzables_e, simbolo)
                copia_allCE = self.allC_E
                for line in copia_allCE:
                    if line == self.algoritmo.getAlcanzables:
                        i += 1
                    if i == len_sigma:
                        finish = True
                if(len(self.algoritmo.getAlcanzables) == 0):
                    pass
                else:
                    self.allC_E.append(self.algoritmo.getAlcanzables)
                aux.append(alcanzables_e)
                aux.append(simbolo)
                aux.append(self.algoritmo.getAlcanzables)
                self.tabla_info.append(aux)
            if(finish):
                break

    def asignar_sinon(self):
        aux = []
        for alcanzables_e in self.allC_E:
            if not alcanzables_e in aux:
                aux.append(alcanzables_e)

        self.allC_E = aux
        i = 0
        for alcanzables_e in aux:
            tupla = (chr(65+i), alcanzables_e)
            self.sinonimos.append(tupla)
            i += 1
        self.sinonimos.append(("Ø", []))

    def vincular_tabla(self):
        renglones = []
        for alcanzables_e in self.allC_E:
            renglon = []
            renglon.append(alcanzables_e)
            for simbolo in self.quintupla.getSigma:
                for line in self.tabla_info:
                    if line[0] == alcanzables_e and line[1] == simbolo:
                        renglon.append(line[2])
            renglones.append(renglon)
        return renglones

    def isInicial(self, letra):
        flag = False
        for sinonimo in self.sinonimos:
            if letra == sinonimo[0]:
                for inicial in self.quintupla.getS:
                    if inicial in sinonimo[1]:
                        flag = True
        return flag
    """
    def isFinal(self, letra):
        flag = False
        for sinonimo in self.sinonimos:
            if letra == sinonimo[0]:
                for final in self.quintupla.getF:
                    if final in sinonimo[1]:
                        flag ="""

    def mostrar_tabla(self):
        self.asignar_sinon()
        renglones = self.vincular_tabla()
        tabla = []

        for renglon in self.tabla_info:
            print(renglon)
        for renglon in renglones:
            aux = []
            for elemento in renglon:
                for sinonimo in self.sinonimos:
                    if sinonimo[1] == elemento:
                        aux.append(sinonimo[0])
            tabla.append(aux)

        for renglon in tabla:
            print(tabla)

        renglon = "Δ"
        for simbolo in self.quintupla.getSigma:
            renglon = renglon + "\t" + str(simbolo)
        print(renglon)

        renglon = ""
        for fila in tabla:
            for elemento in fila:
                #print(self.isInicial(elemento))
                renglon =  renglon + str(elemento) + "\t"
            print(renglon)
            renglon = ""

        print("\n")
        for sinonimo in self.sinonimos:
            print("{} -> {}".format(sinonimo[0], sinonimo[1]))
            #print(sinonimo[1])
