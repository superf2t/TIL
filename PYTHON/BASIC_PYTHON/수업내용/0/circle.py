## circle
if 1:
    import math
    
    class Circle:
        
        def __init__(self, radius=1):
            self.__radius = radius
            self.__diameter = 2 * radius
            self.__area = radius**2 * math.pi

        @property
        def radius(self):
            return self.__radius
           
        @radius.setter
        def radius(self, radius):
            if radius < 0 : raise ValueError("Radius cannot be negative")
            self.__radius = radius
            self.__diameter = 2 * radius
            self.__area = radius**2 * math.pi

        @property
        def diameter(self):
            return self.__diameter
           
        @diameter.setter
        def diameter(self, diameter):
            if diameter < 0 : raise ValueError("Radius cannot be negative")
            self.__diameter = diameter
            self.__radius = diameter/2
            self.__area = self.__radius**2 * math.pi

        @property
        def area(self):
            return self.__area

        @area.setter
        def area(self, diameter):
            raise AttributeError

        def __repr__(self):
            return f'Circle({self.__radius})'

        def printCircle(self):
            print(self.__radius, self.__diameter, self.__area)
