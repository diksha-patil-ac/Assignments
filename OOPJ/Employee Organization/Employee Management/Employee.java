
public class Employee 
{
	protected String name;
	protected String address;
	protected int age;
	protected boolean gender;
	protected float basicsalary;
	
	public Employee(String name,String address,int age,boolean gender,float basicsalary){
	
		setName(name);
		setAddress(address);
		setAge(age);
		setGender(gender);
		setBasicsalary(basicsalary);
	}

	public String getName() 
	{
		return name;
	}

	public void setName(String name) 
	{
		if(name!=" ")
		this.name = name;
		else
			System.out.println("enter valid name");
	}

	public String getAddress() 
	{
		return address;
	}

	public void setAddress(String address) 
	{
		if(address!=" ")
		this.address = address;
		else
			System.out.println("enter valid address");
	}

	public int getAge() 
	{
		return age;
	}

	public void setAge(int age) 
	{
		if(age>1 && age<80)
		this.age = age;
		else
			System.out.println("enter valid age");
	}

	public boolean isGender() 
	{
		return gender;
	}

	public void setGender(boolean gender) 
	{
		this.gender = gender;
	}

	public float getBasicsalary() 
	{
		return basicsalary;
	}

	public void setBasicsalary(float basicsalary) 
	{
		if(basicsalary>10000 && basicsalary<1000000)
		this.basicsalary = basicsalary;
		else
			System.out.println("enter valid salary");
	}
	
	public void display() 
	{
		System.out.println("name : "+name);
		System.out.println("adress : "+address);
		System.out.println("age : "+age);
		System.out.println("gender : "+gender);
		System.out.println("basic salary : "+basicsalary);
	}
}