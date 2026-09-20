package SaveAndLoad;

class Manager extends Employee
{
    public Manager(String n, String a, int ag, boolean g, float salary)
    {
        super(n, a, ag, g, salary);
    }

    @Override
    public String getDesignation()
    {
        return "Manager";
    }
}