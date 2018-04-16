Epsilon = "E"
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

class AfnE:
    i = 0
    allPath = []

    def __init__(self, content):
        self.quintupla = Quintupla(content)

    def start_state(self):
        return self.quintupla.getS

    def final_state(self, state):
        return state in self.quintupla.getF

    def save_path(self, path):
        aux = path.split(",")
        self.allPath.append(aux)

    def recorrer(self, string, now_state, path):
        if len(string) == 0:
            if(self.final_state(now_state)):
                self.save_path(path)
                self.i += 1
            simbolo = 0
            #else:
                #simbolo = Epsilon
        else:
            simbolo = string[0]
        lista = []
        lista_aux = []
        for line in self.quintupla.getDelta:
            if now_state == line[0] and simbolo == line[1]:
                lista.append(line[2])
            if now_state == line[0] and Epsilon == line [1]:
                lista_aux.append(line[2])
        for state in lista:
            self.recorrer(string[1:], state, path=path+state+',')
        for state in lista_aux:
            self.recorrer(string, state, path=path+state+',')

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
        path_str = self.quintupla.getS[0]
        for path in self.allPath:
            path.pop()
            path.insert(0, path_str)
            print(path)

            """"i = 1
            for state in path:
                if i == len(path):
                    path_str=path_str+'q'+state
                else:
                    path_str=path_str+'q'+state+'->'
                i += 1"""

        #print("Camino: {}".format(path_str))
