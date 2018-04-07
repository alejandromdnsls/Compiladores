class String:

    string = None

    def setString(self):
        self.string = input("Cadena: ")

    @property
    def getString(self):
        return self.string

    def check_string(self, flag):
        if flag:
            while True:
                if self.string.isalpha():
                    break
                else:
                    self.string = input("Try again... Inserta una cadena: ")
        else:
            self.string = input("Ingresa una cadena que pertezca al alfabeto: ")

    """def stringto_list(self):
        aux = []
        for c in self.string:
            aux.append(c)
        self.string = []
        self.string = aux"""

    def match_sigma(self, sigma):
        flag = True
        for car_sigma in sigma:
            for car_string in self.string:
                if car_sigma == car_string:
                    flag = True
                    continue
                else:
                    flag = False
        if flag:
            return True
        else:
            return False
