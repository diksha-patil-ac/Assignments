package SaveAndLoad;

import java.io.Serializable;

abstract class Employee implements Serializable
{
    protected String name;
    protected String address;
    protected int age;
    protected boolean gender;
    protected float basicSalary;

    public Employee() 
    {
    	
    }
    
    public Employee(String n, String a, int ag, boolean g, float salary)
    {
        name = n;
        address = a;
        age = ag;
        gender = g;
        basicSalary = salary;
    }

    public String getName()
    {
        return name;
    }

    public String getAddress()
    {
        return address;
    }

    public int getAge()
    {
        return age;
    }

    public boolean isGender()
    {
        return gender;
    }

    public float getBasicSalary()
    {
        return basicSalary;
    }

    public abstract String getDesignation();

    public void display()
    {
        System.out.println("Name         : " + name);
        System.out.println("Address      : " + address);
        System.out.println("Age          : " + age);
        System.out.println("Gender       : " + gender);
        System.out.println("Basic Salary : " + basicSalary);
        System.out.println("Designation  : " + getDesignation());
    }
}