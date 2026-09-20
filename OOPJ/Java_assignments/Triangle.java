
class Triangle {
    int side1, side2, side3;

    Triangle(int side1, int side2, int side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    void area() {
        double s = (side1 + side2 + side3) / 2.0;

        double area = Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));

        System.out.println("Area = " + area);
    }

    void perimeter() {
        int perimeter = side1 + side2 + side3;

        System.out.println("Perimeter = " + perimeter);
    }

    public static void main(String[] args) {

        Triangle t = new Triangle(3, 4, 5);

        t.area();
        t.perimeter();
    }
}