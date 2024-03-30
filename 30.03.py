class Employee: # родительский класс
 
    def __init__(self, name):
        self.__name = name # для Employee НЕ доступны закрытые атрибуты типа __name
 
    @property
    def name(self):
        return self.__name # обратиться к приватному атрибуту self.__name
 
    def work(self):
        print(f"{self.name} работает")
 
 
class Student: # родительский класс
 
    def __init__(self, name):
        self.__name = name # для Employee НЕ доступны закрытые атрибуты типа __name
 
    @property
    def name(self):
        return self.__name # обратиться к приватному атрибуту self.__name
 
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