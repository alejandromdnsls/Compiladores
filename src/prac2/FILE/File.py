class File:
    content = None
    
    def __init__(self, dir):
        self.file = open(dir, 'r')

    @property
    def getContent(self):
        return self.content

    def read(self):
        i = 0
        self.content = self.file.read().split()
        for line in self.content:
            self.content[i] = line.split(',')
            i += 1

    def close_file(self):
        self.file.close()
