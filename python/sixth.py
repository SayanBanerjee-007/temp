class Animal:
    def __init__(self, name, species, age):
        self.name = name
        self.species = species
        self.age = age

    def __str__(self):
        return f"{self.name} ({self.species}), Age: {self.age}"

class Zoo:
    def __init__(self):
        self.animals = []

    def add_animal(self, animal):
        if type(animal) is list:
            self.animals.extend(animal)
        else:
            self.animals.append(animal)

    def display_animals(self):
        if not self.animals:
            print("The zoo has no animals.")
        else:
            print("Animals in the zoo:")
            for animal in self.animals:
                print(animal)

lion = Animal("Leo", "Lion", 5)
elephant = Animal("Ellie", "Elephant", 10)
giraffe = Animal("Gina", "Giraffe", 7)

my_zoo = Zoo()

my_zoo.add_animal(lion)
my_zoo.add_animal([elephant, giraffe])

my_zoo.display_animals()
