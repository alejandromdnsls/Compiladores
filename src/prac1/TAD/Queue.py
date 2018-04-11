class Queue:
    def __init__(self):
        self.items = []

    @property
    def getItems(self):
        return self.items

    def is_empty(self):
        return self.items == []

    def insert(self, item):
        self.items.insert(0, item)

    def remove(self):
        self.items.pop()

    def length(self):
        return len(self.items)

    @property
    def getFirst(self):
        return self.items[0]
