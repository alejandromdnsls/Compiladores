class Node:
    def __init__(self, date):
        self.date = date
        self.next = None

    @property
    def getDate(self):
        return self.date

    @property
    def getNext(self):
        return self.next

    def setDate(self, date):
        self.date = date

    def setNext(self, next):
        self.next = next

class List:
    def __init__(self):
        self.head = None

    def isempty(self):
        return self.head == None

    def add(self, item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head = temp

    def length(self):
        now = self.head
        i = 0
        while now != None:
            i += 1
            now = now.getNext
        return i
