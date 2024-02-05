Task 1. Working with a shopping cart

What should be done:
Implement a simple and secure online shopping cart model.

At the beginning of the program, you fill out the database of the store itself through the standard console.
Each element of this database consists of two components - article number and number of pieces.
The shopping cart must support the following operations: adding a product with a specified quantity - add, removing a product with a specified quantity - remove.
Both operations accept a product SKU as a string and a quantity as an integer.
When entering arguments to operations, they must be validated.
The article must be in the store database, the quantity must not exceed the quantity of the available product in the warehouse (if deleted, in the cart).

Recommendations
You can use std::map as a container for the database and the basket itself.
If the user entered incorrect information, then it is better to throw std::invalid_argument, in other cases - runtime_error.
