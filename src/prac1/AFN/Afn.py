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
    i = 0
    allPath = []

    def __init__(self, content):
        self.quintupla = Quintupla(content)

    def start_state(self):
            return self.quintupla.getS

    def final_state(self, state):
        return state in self.quintupla.getF

    def save_path(self, path):
        self.allPath.append(path)

    def recorrer(self, string, now_state, path):
        if len(string) == 0:
            simbolo = 0
            if(self.final_state(now_state)):
                self.save_path(path)
                self.i += 1
        else:
            simbolo = string[0]
        lista = []
        for line in self.quintupla.getDelta:
            if now_state == line[0] and simbolo == line[1]:
                lista.append(line[2])
        for state in lista:
            self.recorrer(string[1:], state, path=path+state)

        if self.i == 0:
            return False
        else:
            return True

    def ask_strVal(self, flag):
        if (flag):
            return True
        else:
            return False

    def imprimir_camino(self, path):
        path_str = 'q'+self.quintupla.getS[0]+'->'
        for path in self.allPath:
            i = 1
            for state in path:
                if i == len(path):
                    path_str=path_str+'q'+state
                else:
                    path_str=path_str+'q'+state+'->'
                i += 1
        print("Camino: {}".format(path_str))
