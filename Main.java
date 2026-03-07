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

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int sum = num1 + num2;
        System.out.println("Sum: " + sum);
        input.close();
    }
}