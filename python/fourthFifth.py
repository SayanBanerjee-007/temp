class Book:
    """
    A class to represent a book.

    Attributes:
    ----------
    title : str
        Title of the book.
    author : str
        Author of the book.
    published_year : int
        Year the book was published.
    """

    def __init__(self, title, author, published_year):
        self.title = title
        self.author = author
        self.published_year = published_year

    def get_summary(self):
        """Returns a summary of the book's information."""
        return f"'{self.title}' by {self.author}, published in {self.published_year}"

# Example usage
book1 = Book("To Kill a Mockingbird", "Harper Lee", 1960)
print(book1.get_summary())
print(Book.__doc__)



# EXTENDED =============================================================================================
class Book:
    """
    A class to represent a book.

    Attributes:
    ----------
    title : str
        Title of the book.
    author : str
        Author of the book.
    published_year : int
        Year the book was published.
    """

    def __init__(self, title, author, published_year):
        self.title = title
        self.author = author
        self.published_year = published_year

    def get_summary(self):
        """Returns a summary of the book's information."""
        return f"'{self.title}' by {self.author}, published in {self.published_year}"

    def __del__(self):
        print(f"Book '{self.title}' by {self.author} is being destroyed")


book1 = Book("To Kill a Mockingbird", "Harper Lee", 1960)
book2 = Book("1984", "George Orwell", 1949)

print(book1.get_summary())
print(book2.get_summary())

del book1
