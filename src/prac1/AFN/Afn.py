class Quintupla:
    def __init__(self, content):
        self.content = content

    @property
    def getQ(self):
        return self.content[0]

    @property
    def getSigma(self):
        return self.content[1]

    @property
    def getS(self):
        return self.content[2]

    @property
    def getF(self):
        return self.content[3]

    @property
    def getDelta(self):
        return self.content[4:]

class Afn:
    #queue = Queue()
    i = 0

    def __init__(self, content):
        self.quintupla = Quintupla(content)

    def start_state(self):
            return self.quintupla.getS

    def final_state(self, state):
        return state in self.quintupla.getF

    def imprimir_camino(self, camino):
        lista = []
        lista.append(self.start_state()[0])
        for state in camino:
            lista.append(state)
        print("Camino: {}".format(lista))

    def recorrer(self, string, now_state, camino):
        if len(string) == 0:
            simbolo = 0
            if(self.final_state(now_state)):
                self.imprimir_camino(camino)
                self.i += 1
        else:
            simbolo = string[0]

        lista = []
        for line in self.quintupla.getDelta:
            if now_state == line[0] and simbolo == line[1]:
                lista.append(line[2])
        for item in lista:
            self.recorrer(string[1:], item, camino=camino+item)

        if self.i == 0:
            return False
        else:
            return True
