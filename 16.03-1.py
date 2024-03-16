'''
Вагина Полина Алексеевна, 16.03.2024
'''

class Geom:
    name = 'Geom'
 
    def set_coords(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
 
 
# дочерний класс
class Line(Geom):
    name = 'Geom' # переопределение
    
    def draw(self):
        print("Рисование линии")
 
 
# дочерний класс
class Rect(Geom):
    def draw(self):
        print("Рисование прямоугольника")
        
g = Geom()
g.set_coords(1, 2, 2, 4)
l = Line()
r = Rect()
print(l.name) # Line
print(r.name) # Geom 
l.draw() # Рисование линии
r.draw() # Рисование прямоугольника