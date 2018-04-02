class Node:
    def __init__(self, data=None):
        # private member
        self._data = data
        self._prev = None
        self._next = None

    @property
    def data(self):
        return self._data
    
    @data.setter
    def data(self, data):
        self._data = data

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, n):
        self._next = n

    @property
    def prev(self):
        return self._prev

    @prev.setter
    def prev(self, p):
        self._prev = p


# ADT
class BaseDeque:
    def push(self, data):
        raise NotImplementedError

    def push_left(self, data):
        raise NotImplementedError

    def pop(self):
        raise NotImplementedError

    def pop_left(self):
        raise NotImplementedError

    def remove(self, data):
        raise NotImplementedError

    def clear(self):
        raise NotImplementedError

    def is_empty(self):
        raise NotImplementedError
    
    def show_all(self):
        raise NotImplementedError


class LinkedDeque(BaseDeque):
    def __init__(self):
        self.size = self.head = self.tail = 0

    def push(self, data):
        new_node = Node(data)

        if self.is_empty():
            self.head = new_node
        else:
            self.tail.next = new_node

        self.tail = new_node
        
        self.size += 1


    def push_left(self, data):
        new_node = Node(data)

        if self.is_empty():
            self.tail = new_node
        else:
            new_node.next = self.head

        self.head = new_node
        
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Exception('Deque is empty!')
        
        data = self.tail.data
        self.tail.prev.next = None
        return data

    def pop_left(self):
        if self.is_empty():
            raise Exception('Deque is empty!')
        
        data = self.head.data
        self.head.next.prev = None
        return data

    def remove(self, data):
        if self.is_empty():
            raise Exception('Deque is empty!')

        current = self.head
        while current.data == data:
            current = current.next
        
        current.prev.next = current.next
        current.next.prev = current.prev
        del current

    def clear(self):
        if self.is_empty():
            raise Exception('Deque is empty!')

        current = self.head
        next_node = current.next
        del current
        while next_node:
            current = next_node
            next_node = next_node.next
            del current

    def is_empty(self):
        return self.size == 0

    def show_all(self):
        current = Node(None)
        current.next = self.head

        while current.next:
            current = current.next
            print(current.data)
