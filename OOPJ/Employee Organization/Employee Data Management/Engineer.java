package SaveAndLoad;

class Engineer extends Employee
{
    public Engineer(String n, String a, int ag, boolean g, float salary)
    {
        super(n, a, ag, g, salary);
    }

    @Override
    public String getDesignation()
    {
        return "Engineer";
    }
}