import java.util.Scanner;

class CheckArray {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] arr = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the number to search: ");
        int number = sc.nextInt();

        boolean found = false;

        for (int i = 0; i < 5; i++) {
            if (arr[i] == number) {
                found = true;
                break;
            }
        }

        if (found) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}