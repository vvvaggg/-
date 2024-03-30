class Employee: # родительский класс
 
    def __init__(self, name):
     '''для Employee НЕ доступны закрытые атрибуты типа __name'''
        self.__name = name 
 
    @property
    def name(self):
     """обратиться к приватному атрибуту self.__name"""
        return self.__name 
 
    def work(self):
        print(f"{self.name} работает")
 
 
class Student: # родительский класс
 
    def __init__(self, name):
     """для Employee НЕ доступны закрытые атрибуты типа __name"""
        self.__name = name 
 
    @property
    def name(self):
     """обратиться к приватному атрибуту self.__name"""
        return self.__name 
 
    def study(self):
        print(f"{self.name} учится")
 
 
class WorkingStudent(Employee, Student): # дочерний класс
    pass
 
 
tom = WorkingStudent("Том")
tom.work()      # Том учится
tom.study()     # Том работает
toma = WorkingStudent("Тамара")
toma.study()     # Тамара учится
toma.work()     # Тамара работает

print(WorkingStudent.mro()) # очередность применения функционала базовых классов
