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

    def match_sigma(self, sigma):
        flag = True
        for car_string in self.string:
            for car_sigma in sigma:
                if car_string == car_sigma:
                    flag = True
                    break
                else:
                    flag = False
            if not flag:
                break
        if flag:
            return True
        else:
            return False
