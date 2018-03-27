# ADT
class BaseQueue:
    def enqueue(self, data):
        """데이터 넣기"""
        raise NotImplementedError
    
    def dequeue(self):
        """데이터 꺼내기"""
        raise NotImplementedError
    
    def peek(self):
        """맨 앞의 데이터 보기"""
        raise NotImplementedError
    
    def is_empty(self):
        """
        데이터 유무 검사
        있으면 False, 없으면 True
        """
        raise NotImplementedError
    
    def display(self):
        """모든 데이터를 보여줌"""
        raise NotImplementedError


class ArrayQueue(BaseQueue):
    def __init__(self):
        self.items = []
        self.size = 0
        self.front = 0
        self.rear = 0
    
    def enqueue(self, data):
        self.items.append(data)
        self.size += 1
        self.rear += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception('Queue is empty!')
    
        data = self.items[self.front]
        self.front += 1
        self.size -= 1
        
        return data

    def peek(self):
        if self.is_empty():
            raise Exception('Queue is empty!')
        
        return self.items[self.front]
    
    def is_empty(self):
        return self.size == 0
    
    def show_all(self):
        for index in range(self.front, self.rear):
            print(self.items[index])
