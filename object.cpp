
#include <object.h>

//object class

object::object()
{

}

object::object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i):name(name_i),description(description_i),display_char(display_char_i)
{
    char_color.copy(char_color_i);
    background_color.copy(background_color_i);
}

object::object(const object & source) 
{
    copy_object(source);
}

object::~object()
{

}


virtual char object::get_display_char()const
{
    return display_char;
}

virtual color object::get_char_color()const
{
    return char_color;
}

virtual color object::get_background_color()const
{
    return background_color;
}

virtual string object::get_name()
{
    return name;
}

virtual string object::get_description()
{
    return description;

}


virtual bool object::copy_object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i)
{
    name = name_i;
    description = description_i;
    display_char = display_char_i;
    char_color.copy(char_color_i);
    background_color.copy(background_color_i);

    return true;
}


virtual bool object::copy_object(const object & source)
{
    name = source.name;
    description = source.description;
    display_char = source.display_char;
    char_color.copy(source.char_color);
    background_color.copy(source.background_color);
    return true;
}



//not sure how we are passing color yet. It could be a struct with the appropriate ints I think the display class can answer how color should be passed
virtual bool interact(const object & check_interaction)
{
    //incomplete
    return true;
}




hero::hero()
{
    inventory = new object[Inventory_size];

}

hero::hero(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const oject* inventory):object(name_i, description_i, display_char_i, char_color_i, background_color_i), energy(energy_i),wiffle(wiffle_i)
{
    inventory = new object[Inventory_size];
    if(inventory)
    {
        for(int i =0; i<Inventory_size; ++i)
        {
            inventory[i] = new object(inventory_i[i]);
        }
    }
}

hero::hero(const object& source):object(source),energy(source.energy),wiffle(source.wiffle)
{

    inventory = new object[Inventory_size];
    for(int i =0; i<Inventory_size; ++i)
    {
        inventory[i] = new object(source.inventory[i]);
    }
}

~hero::hero()
{
    for(int i =0; i<Inventory_size; ++i)
    {
        inventory[i];
    }
    delete inventory;
}

virtual char hero::get_display_char()const
{
    return display_char;
}


virtual color hero::get_char_color()const
{
    return char_color;
}


virtual color hero::get_background_color()const; 
{
    return background_color;
}

virtual string hero::get_name()
{
    return name;
}

virtual string hero::get_description()
{
    return description;

}

virtual bool hero::copy_object(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const oject* inventory)
{ 
    object::copy_object(name_i, description_i, display_char_i, bacground_color_i);
    energy = energy_i;
    wiffle = wiffle_i;
    if(inventory)
    {
        for(int i =0; i<Inventory_size; ++i)
        {
            inventory[i] = new object(inventory_i[i]);
        }
    }
    return true;
}

virtual bool hero::copy_object(const object & source);
{
    object::copy_object(source);
    for(int i =0; i<Inventory_size; ++i)
    {
        inventory[i] = new object(source.inventory[i]);
    }
    energy = source.energy;
    wiffle = wiffle.energy;

    return true;
}


virtual bool hero::interact(const object & check_interaction);
{

    //incomplete
    return true;
}

&string[] hero::get_inventory_list()const;
{
    string inventory_items[Inventory_size];
    for(int i =0;i<Inventory_size;++i)
    {
        if(inventory[i])
        {
            inventory_items[i] = inventory[i].get_name();
        }

    }

    return inventory_items;
}

object* hero::get_inventory_items();
{
    return inventory;

}

bool hero::add_to_inventory(object*& inventory_item);
{
    int i = 0;
    while(i < Inventory_size && inventory[i])
    {
        ++i;
    }
    if(i<Inventory_size)
    {
        inventory[i] = inventory_item;
        inventory_item = NULL;
    }
    return i<Inventory_size; 
}

