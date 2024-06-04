class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def calculate_area(self):
        return self.length * self.width

rectangle = Rectangle(5, 3)
area = rectangle.calculate_area()
print(f"The area of the rectangle is: {area}")

# EXTENDED =============================================================================================
class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def calculate_area(self):
        return self.length * self.width

    def display_info(self):
        area = self.calculate_area()
        print(f"Rectangle length: {self.length}, width: {self.width}, area: {area}")

# Example usage
rectangle = Rectangle(5, 3)
rectangle.display_info()
