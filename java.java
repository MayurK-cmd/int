5.
class Shape { 
    public void draw() { 
        System.out.println("Drawing a shape");
 } 
 
    public void erase() { 
        System.out.println("Erasing a shape"); 
    } 
} 
 
// Circle class (Subclass) 
class Circle extends Shape { 
    @Override 
    public void draw() { 
        System.out.println("Drawing a circle"); 
    } 
 
    @Override 
    public void erase() { 
        System.out.println("Erasing a circle"); 
    } 
} 
 
// Triangle class (Subclass) 
class Triangle extends Shape { 
    @Override 
    public void draw() { 
        System.out.println("Drawing a triangle"); 
    } 
 
    @Override 
    public void erase() { 
        System.out.println("Erasing a triangle"); 
    } 
} 
 
// Square class (Subclass) 
class Square extends Shape { 
    @Override 
    public void draw() { 
        System.out.println("Drawing a square"); 
    } 
 
    @Override 
    public void erase() { 
        System.out.println("Erasing a square"); 
    } 
} 
 
// Main class 
public class Main { 
    public static void main(String[] args) { 
       // Polymorphism: Creating objects of different subclasses using the reference of the 
superclass 
        Shape shape1 = new Circle(); 
        Shape shape2 = new Triangle(); 
        Shape shape3 = new Square(); 
 
        // Demonstrating polymorphic behavior 
        shape1.draw(); // Calls draw() method of Circle class 
        shape1.erase(); // Calls erase() method of Circle class 
 
        shape2.draw(); // Calls draw() method of Triangle class 
        shape2.erase(); // Calls erase() method of Triangle class 
 
        shape3.draw(); // Calls draw() method of Square class 
        shape3.erase(); // Calls erase() method of Square class 
    } 
}
-----------------------------------------------------------------------------------------------------------------
6.
// Abstract Shape class 
abstract class Shape { 
    // Abstract methods to calculate area and perimeter 
    abstract double calculateArea(); 
    abstract double calculatePerimeter(); 
} 
 
// Circle class extending Shape 
class Circle extends Shape { 
    private double radius; 
 
    // Constructor for Circle class 
    public Circle(double radius) { 
        this.radius = radius; 
    } 
 
    // Implementation of abstract method to calculate area for Circle 
    @Override 
    double calculateArea() { 
        return Math.PI * radius * radius; 
    } 
 
    // Implementation of abstract method to calculate perimeter (circumference) for Circle 
    @Override 
    double calculatePerimeter() { 
        return 2 * Math.PI * radius; 
    } 
} 
 
// Triangle class extending Shape 
class Triangle extends Shape { 
    private double side1; 
    private double side2; 
    private double side3; 
 
    // Constructor for Triangle class 
    public Triangle(double side1, double side2, double side3) { 
        this.side1 = side1; 
        this.side2 = side2; 
        this.side3 = side3; 
    } 
 
    // Implementation of abstract method to calculate area for Triangle using Heron's 
formula 
    @Override 
    double calculateArea() { 
    double s = (side1 + side2 + side3) / 2; 
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3)); 
    } 
 
    // Implementation of abstract method to calculate perimeter for Triangle 
    @Override 
    double calculatePerimeter() { 
        return side1 + side2 + side3; 
    } 
} 
 
// Main class 
public class Main { 
    public static void main(String[] args) { 
        // Creating Circle and Triangle objects 
        Circle circle = new Circle(5); 
        Triangle triangle = new Triangle(3, 4, 5); 
 
        // Calculating and displaying area and perimeter for Circle 
        System.out.println("Circle - Area: " + circle.calculateArea() + ", Perimeter: " + 
circle.calculatePerimeter()); 
 
        // Calculating and displaying area and perimeter for Triangle 
        System.out.println("Triangle - Area: " + triangle.calculateArea() + ", Perimeter: " + 
triangle.calculatePerimeter()); 
    } 
}
------------------------------------------------------------------------------------------------------------------------------
7.
// Resizable interface 
interface Resizable { 
    void resizeWidth(int width); 
    void resizeHeight(int height); 
} 
 
// Rectangle class implementing Resizable interface 
class Rectangle implements Resizable { 
    private int width; 
    private int height; 
 
    // Constructor 
    public Rectangle(int width, int height) { 
        this.width = width; 
        this.height = height; 
    } 
 
    // Implementation of resizeWidth method from Resizable interface 
    @Override 
    public void resizeWidth(int width) { 
        this.width = width; 
    } 
 
    // Implementation of resizeHeight method from Resizable interface 
    @Override 
    public void resizeHeight(int height) { 
        this.height = height; 
    } 
 
    // Method to display the dimensions of the rectangle 
    public void displayDimensions() { 
        System.out.println("Width: " + width + ", Height: " + height); 
    } 
} 
 
// Main class 
public class Main { 
    public static void main(String[] args) { 
        // Creating a Rectangle object 
        Rectangle rectangle = new Rectangle(10, 20); 
        System.out.println("Original Dimensions:"); 
        rectangle.displayDimensions(); // Output: Width: 10, Height: 20 
 
        // Resizing the rectangle 
        rectangle.resizeWidth(15); 
        rectangle.resizeHeight(25); 
        System.out.println("Dimensions after resizing:"); 
        rectangle.displayDimensions(); // Output: Width: 15, Height: 25
}
}
-----------------------------------------------------------------------------------------------------------------------