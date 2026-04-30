import java.util.Scanner;
// public class Main {
//     public static void main(String[] args) {
//         System.out.println("Hello Java");
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         Scanner input = new Scanner(System.in);
//         System.out.println("Enter a number");//cout
//         int num = input.nextInt(); //cin
//         System.out.println("Number = " + num);//cout
//         input.close();
//     }
    
// }

// public class Main {

//     public static void main(String[] args) {
//         Scanner input = new Scanner(System.in);
//         System.out.print("Enter age: ");
//         int age = input.nextInt();
//         System.out.println("Your age is: " + age);
//     }
// }

// public class Main {

//     public static void main(String[] args) {
//         Scanner input = new Scanner(System.in);
//         System.out.println("What is your name?");
//         // String que = input.next();
//         // System.out.println("Your name is " + que);
//         String que = input.nextLine();
//         System.out.println("Your name is " + que);
//     }
// }

//                          add two numbers

// public class Main {

//     public static void main(String[] args) {
//         Scanner input = new Scanner(System.in);
//         System.out.println("Enter two numbers: ");
//         int num1 = input.nextInt();
//         int num2 = input.nextInt();
//         int sum = num1 + num2;
//         System.out.println("Sum: " + sum);
//         input.close();
//     }
// }

//assignment

import java.util.Scanner;

// Abstract class
abstract class Shape {
    abstract double area();
    abstract double perimeter();
}

// Circle class
class Circle extends Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    double area() {
        return Math.PI * radius * radius;
    }

    double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// Square class
class Square extends Shape {
    double side;

    Square(double side) {
        this.side = side;
    }

    double area() {
        return side * side;
    }

    double perimeter() {
        return 4 * side;
    }
}

// Triangle class
class Triangle extends Shape {
    double a, b, c;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    double area() {
        double s = (a + b + c) / 2; // semi-perimeter
        return Math.sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }

    double perimeter() {
        return a + b + c;
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Circle
        System.out.println("Enter radius of circle:");
        double r = sc.nextDouble();
        Circle c = new Circle(r);
        System.out.println("Circle Area: " + c.area());
        System.out.println("Circle Perimeter: " + c.perimeter());
        System.out.println();

        // Square
        System.out.println("Enter side of square:");
        double s = sc.nextDouble();
        Square sq = new Square(s);
        System.out.println("Square Area: " + sq.area());
        System.out.println("Square Perimeter: " + sq.perimeter());
        System.out.println();

        // Triangle
        System.out.println("Enter sides of triangle (a b c):");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c1 = sc.nextDouble();
        Triangle t = new Triangle(a, b, c1);
        System.out.println("Triangle Area: " + t.area());
        System.out.println("Triangle Perimeter: " + t.perimeter());

        sc.close();
    }
}