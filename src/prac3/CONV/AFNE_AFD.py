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
    mover = []


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

    def C_E(self,state_now):
        statesE = []
        for line in self.quintupla.getDelta:
            if (state_now == line[0]) and (line[1] == Epsilon):
                statesE.append(line[2])
        for stateE in statesE:
            self.c_e.append(stateE)
            self.C_E(stateE)

    def MOVER(self):
        for car in self.quintupla.getSigma:
            for state in self.c_e:
                for line in self.quintupla.getDelta:
                    if state == line[0] and car == line[1]:
                        self.mover.append(line[2])


    def ir_a(self):
        pass
