from queue import PriorityQueue
from dataclasses import dataclass, field
from typing import Any

@dataclass(order=True)
class Node:
    value:int = 0
    next = None

    def __init__(self, val):
        self.value = val

    def __str__(self):
        return f'{self.value=} and {self.next=}'

class List:
    head:Node = None

    def __init__(self):
        self.head = None
    
    def __str__(self):
        temp:Node = self.head
        arr = []
        while temp is not None:
            arr.append(temp.value)
            temp = temp.next
        return ' '.join(map(str, arr))
    
    def insert(self, val:int):
        newNode = Node(val=val)
        newNode.next = self.head
        self.head = newNode


if __name__ == '__main__':
    pq = PriorityQueue()
    l1 = List()
    l2 = List()
    l3 = List()
    l4 = List()

    final = List()

    l1.insert(6)
    l1.insert(4)
    l1.insert(2)

    l2.insert(5)
    l2.insert(1)

    l3.insert(7)
    l3.insert(3)
    l3.insert(1)
    l3.insert(1)

    l4.insert(8)

    # initialise PQ with heads
    pq.put((l1.head.value, l1.head))
    pq.put((l2.head.value, l2.head))
    pq.put((l3.head.value, l3.head))
    pq.put((l4.head.value, l4.head))

    while not pq.empty():
        item = pq.get()
        final.insert(item[0])
        if item[1].next is not None:
            pq.put((item[1].next.value, item[1].next))
    
    print(final)