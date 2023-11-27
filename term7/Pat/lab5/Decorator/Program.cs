Warrior warrior = new Warrior();
Console.WriteLine(warrior);
Armed halberdiers = new Armed(warrior);
Console.WriteLine(halberdiers);

abstract class GameCharacter
{
    public string WarriorType = string.Empty;
    public int health;
    public int damage;

    public abstract override string ToString();
}

internal class Warrior : GameCharacter
{
    public Warrior()
    {
        WarriorType = "Warrior";
        health = 100;
        damage = 10;
    }
    public override string ToString()
    {
        return
            $$"""
            {{WarriorType}}
                health: {{health}}
                damage: {{damage}}
            """;
    }
}

abstract class Decorator : GameCharacter
{
    protected GameCharacter character;

    public Decorator(GameCharacter character)
    {
        this.character = character;
    }
}

internal class Armed : Decorator
{
    protected string weapon;
    protected int armore;
    public Armed(GameCharacter character) : base(character)
    {
        this.character = character;
        weapon = "Halberd";
        WarriorType = "Halberdiers";
        health = character.health;
        damage = character.damage + 100;
        armore = 50;
    }

    public override string ToString()
    {
        return
        $"""
        {WarriorType}
            health: {health}
            damage: {damage}
            weapon: {weapon}
            armore: {armore}
        """;
    }
}
