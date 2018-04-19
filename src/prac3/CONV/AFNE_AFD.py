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

class AFD:
    c_e = []


    def __init__(self, content):
        self.quintupla = Quintupla(content)

    def start_state(self):
        for state in self.quintupla.getS:
            return state

    @property
    def getC_E(self):
        return self.c_e

    @property
    def getMover(self):
        return self.mover

    def inicializar_ce(self, states):
        for state in states:
            self.c_e.append(state)

    def C_E(self,state_now):
        statesE = []
        for line in self.quintupla.getDelta:
            if (state_now == line[0]) and (line[1] == Epsilon):
                statesE.append(line[2])
        for stateE in statesE:
            self.c_e.append(stateE)
            self.C_E(stateE)

    def MOVER(self, conjunto, simbolo):
        mover_states = []
        for state in conjunto:
            for line in self.quintupla.getDelta:
                if state == line[0] and simbolo == line[1]:
                    mover_states.append(line[2])
        return mover_states

    def IR_A(self, conjunto, simbolo):
        print(conjunto)
        print(simbolo)
        states = self.MOVER(conjunto, simbolo)
        self.c_e.clear()
        self.inicializar_ce(states)
        for state in states:
            self.C_E(state)
        return self.c_e
