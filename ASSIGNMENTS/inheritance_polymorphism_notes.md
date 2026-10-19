# Take-Home: Chained Inheritance and Polymorphism

## 1. Chained (Multilevel) Inheritance

The program uses a university-student example with three classes:

```text
Person
  |
  v
Student
  |
  v
EngineeringStudent
```

- **Person** stores the student's name and age.
- **Student** inherits from Person and adds a registration number.
- **EngineeringStudent** inherits from Student and adds the course.
- An `EngineeringStudent` object can call `displayPerson()` and `displayStudent()` even though those functions were defined in its parent classes.

### Hand-drawn illustration to reproduce

Draw three boxes vertically and connect them using arrows:

```text
+----------------------+
|        Person        |
|----------------------|
| name                 |
| age                  |
| displayPerson()      |
+----------------------+
           |
           | inherits
           v
+----------------------+
|       Student        |
|----------------------|
| registrationNumber   |
| displayStudent()     |
+----------------------+
           |
           | inherits
           v
+----------------------+
| EngineeringStudent   |
|----------------------|
| course               |
| displayEngineering-  |
| Student()            |
+----------------------+
```

This shows a chain: `Person -> Student -> EngineeringStudent`.

## 2. Polymorphism

The program uses a payment example. `Payment` is the parent class and contains the virtual function `processPayment()`. `MobileMoney` and `BankCard` override that same function.

A `Payment*` pointer is first made to point to a `MobileMoney` object and later to a `BankCard` object. The same call:

```cpp
payment->processPayment();
```

produces different behaviour depending on the object being pointed to. This is **runtime polymorphism**.

### Hand-drawn illustration to reproduce

```text
                 +----------------------+
                 |       Payment        |
                 |----------------------|
                 | virtual              |
                 | processPayment()     |
                 +----------------------+
                    /                \
                   /                  \
                  v                    v
+----------------------+      +----------------------+
|     MobileMoney      |      |       BankCard       |
|----------------------|      |----------------------|
| processPayment()     |      | processPayment()     |
| "Mobile Money"       |      | "Bank Card"          |
+----------------------+      +----------------------+

        Payment* payment
              |
              +----> MobileMoney  -> Mobile Money behaviour
              |
              +----> BankCard     -> Bank Card behaviour
```

The drawings above are guides. Redraw them by hand in your assignment as requested.
