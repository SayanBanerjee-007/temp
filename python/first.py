import math

class Point3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def distance_to(self, other):
        return math.sqrt(
            (self.x - other.x) ** 2 +
            (self.y - other.y) ** 2 +
            (self.z - other.z) ** 2
        )

# Example usage
point1 = Point3D(1, 2, 3)
point2 = Point3D(4, 5, 6)

distance = point1.distance_to(point2)
print(f"The Euclidean distance between the points is: {distance:.2f}")
