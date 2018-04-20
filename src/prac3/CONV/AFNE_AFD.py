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

class Algoritmo:
    alcanzables_e = []
    
    def __init__(self, content):
        self.quintupla = Quintupla(content)

    @property
    def getInicial(self):
        for inicial in self.quintupla.getS:
            return inicial

    @property
    def getAlcanzables(self):
        return self.alcanzables_e

    def inicializar_ce(self, state):
        self.alcanzables_e.append(state)

    def c_e(self,now_state):
        statesE = []
        for line in self.quintupla.getDelta:
            if (now_state == line[0]) and (line[1] == Epsilon):
                statesE.append(line[2])
        for stateE in statesE:
            self.alcanzables_e.append(stateE)
            self.c_e(stateE)

    def mover(self, conjunto, simbolo):
        mover_states = []
        for state in conjunto:
            for line in self.quintupla.getDelta:
                if state == line[0] and simbolo == line[1]:
                    mover_states.append(line[2])
        return mover_states

    def ir_a(self, conjunto, simbolo):
        states = self.mover(conjunto, simbolo)
        self.alcanzables_e  = []
        for state in states:
            self.inicializar_ce(state)
            self.c_e(state)
