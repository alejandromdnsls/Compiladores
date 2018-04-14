class String:

    string = None

    def setString(self, string):
        self.string = string

    @property
    def getString(self):
        return self.string

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
