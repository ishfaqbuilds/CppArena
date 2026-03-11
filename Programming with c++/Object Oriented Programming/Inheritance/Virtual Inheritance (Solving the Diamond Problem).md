## Virtual Inheritance (Solving the Diamond Problem)

The Diamond Problem: Occurs when a class inherits from two classes that both inherit from the same base class.  Without virtual inheritance, the base class is duplicated, leading to ambiguity.

Example of the Problem:
```cpp
class A 
{ 
public: 
	int x; 
};
class B : public A {};
class C : public A {};
class D : public B, public C {}; // D has two copies of A
```

Solution: Virtual Inheritance:
- Declare base classes as virtual in intermediate classes.
- This ensures only **one shared copy** of the base class exists.
Fixed Example:
```cpp
class A 
{ 
public: 
	int x; 
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {}; // Only one A now
```

Key Point: Virtual inheritance is used to avoid ambiguity in multiple inheritance.

