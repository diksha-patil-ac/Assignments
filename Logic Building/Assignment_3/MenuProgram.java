import java.util.Scanner;

class MenuProgram {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Grade Evaluation System");
            System.out.println("2. Leap Year Check");
            System.out.println("3. Day of the Week");
            System.out.println("4. Identify Default Values of Variables");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter your marks: ");
                    int marks = sc.nextInt();

                    if (marks >= 90)
                        System.out.println("Grade: A");
                    else if (marks >= 75)
                        System.out.println("Grade: B");
                    else if (marks >= 60)
                        System.out.println("Grade: C");
                    else if (marks >= 50)
                        System.out.println("Grade: D");
                    else
                        System.out.println("Grade: F");
                    break;

                case 2:
                    System.out.print("Enter a year: ");
                    int year = sc.nextInt();

                    if ((year % 400 == 0) ||
                        (year % 4 == 0 && year % 100 != 0))
                        System.out.println("Leap Year");
                    else
                        System.out.println("Not a Leap Year");
                    break;

                case 3:
                    System.out.print("Enter a number (1-7): ");
                    int day = sc.nextInt();

                    switch (day) {
                        case 1:
                            System.out.println("Monday");
                            break;
                        case 2:
                            System.out.println("Tuesday");
                            break;
                        case 3:
                            System.out.println("Wednesday");
                            break;
                        case 4:
                            System.out.println("Thursday");
                            break;
                        case 5:
                            System.out.println("Friday");
                            break;
                        case 6:
                            System.out.println("Saturday");
                            break;
                        case 7:
                            System.out.println("Sunday");
                            break;
                        default:
                            System.out.println("Invalid day");
                    }
                    break;

                case 4:
                    System.out.println("Default value of int: 0");
                    System.out.println("Default value of double: 0.0");
                    System.out.println("Default value of boolean: false");
                    System.out.println("Default value of char: \\u0000");
                    break;

                case 5:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice");
            }

        } while (choice != 5);

        sc.close();
    }
}