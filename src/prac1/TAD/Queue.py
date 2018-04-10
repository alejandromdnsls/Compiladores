class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def add(self, item):
        self.items.insert(0, item)

    def avanzar(self):
        self.items.pop()

    def length(self):
        return len(self.items)
