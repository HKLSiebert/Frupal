
#include <object.h>

//object class

object::object():
{

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

virtual bool object::import_object(/*unknown args*/)
{
    //incomplete

    return true;
}


virtual bool object::copy_object(const object & source)
{
    //incomplete
    return treu;
}



//not sure how we are passing color yet. It could be a struct with the appropriate ints I think the display class can answer how color should be passed
virtual bool interact(const object & check_interaction)
{
    //incomplete
    return true;
}




hero::hero();//constructor
 hero::hero(const hero& source);
        ~hero::hero();
        virtual char hero::get_display_char()const;
        virtual color hero::get_char_color()const;
        virtual color hero::get_background_color()const; 
        virtual bool hero::hero::import_object(/*unknown args*/);
        virtual bool hero::copy_object(const object & source);
        virtual bool hero::interact(const object & check_interaction);
        string[] hero::get_inventory_list()const;
        object* hero::get_inventory_items();

  
grovnic::grovnic():energy_cost(0), inventory(NULL)
{}

grovnic::grovnic(grovnic &toCopy):object(toCopy), energy_cost(toCopy.energy_cost)
{
  if (toCopy.inventory)
    inventory = new object(toCopy.inventory);
}

grovnic::grovnik(string name, color bgColor, int cost, color displayColor, char displayChar):object(/*TODO*/), energy_cost(cost), inventory(NULL)
{}

grovnic::grovnic(string name, color bgColor, int cost):object(/*TODO*/), energy_cost(cost), inventory(NULL)
{}

grovnic::~grovnic()
{
  if (inventory)
  {
    delete inventory;
    inventory = NULL;
  }
}

virtual char grovnic::get_display_char()const
{
  if(inventory)
    return inventory.get_display_char();
  return NULL;
}

virtual color grovnic::get_char_color()const
{
  if(inventory)
    return inventory.get_char_color();
  return NULL;
}

virtual color grovnic::get_background_color()const
{
  return bg;
}

virtual bool grovnic::copy_object(const object & source)
{
  if (source)
    return (*this).copy_object

}

//Takes an object and adds it to the grovnic's inventory
virtual bool grovnic::import_object(/**/)
{
}

virtual bool grovnic::interact(const object & check_interaction)
{
  //Needs to potentially remove the grocnik item as well as lower hero stats
}


item::item()
{}

item::item(item &toCopy):object(toCopy)
{}

item::item(string name, color itemColor, char displayChar:object(/*TODO*/)
{}

item::~item()
{}

virtual char item::get_display_char()const
{}

virtual color item::get_char_color()const
{}

virtual color item::get_background_color()const
{}

virtual bool item::copy_object(const object & source)
{

}

virtual bool item::import_object(/*unknown args*/)
{
  return true;
}

//The only thing interacting with items should be the hero, which will pick it up
virtual bool item::interact(const object & check_interaction)
{

  return check_interaction.import_object(*this);

}

tool::tool():effectiveAgainst(NULL), multiplier(1)
{}

tool::tool(item &toCopy):item(toCopy), effectiveAgainst(toCopy.effectiveAgainst), multiplier(toCopy.multiplier)
{}

tool::~tool()
{
  delete effectiveAgainst;
  effectiveAgainst = NULL;
}

//All toolds will be a lowercase t 
virtual char tool::get_display_char()const
{
  return t;
}

virtual color tool::get_char_color()const
{

}

virtual color tool::get_background_color()const
{

}

virtual bool tool::copy_object(const object & source)
{

}

virtual bool tool::import_object(/*unknown args*/)
{
  return true;
}

//The only thing interacting with the hero should be the HEro, which will pick it up. 
virtual bool tool::interact(const object & check_interaction)
{
  return check_interaction.import_object(*this);
}

food::food():whiffle_cost(0), energy_restoration(0)
{

}

food::food(food &toCopy): item(toCopy), whiffle_cost(toCopy.whiffle_cost), energy_restoration(toCopy.energy_restoration)
{}

food::food(string name, color itemColor, char displayChar, int wCost, int eRest):item(toCopy), whiffle_cost(wCost), energy_restoration(eRest)
{}

food::~food()
{}

//All food has the same cymbol for now
virtual char food::get_display_char()const
{
  return F;
}

virtual color food::get_char_color()const
{

}

virtual color food::get_background_color()const
{

}

virtual bool food::copy_object(const object & source)
{

}

virtual bool food::import_object(/*unknown args*/)
{

}

//The only thing ineracting with foos should be the hero, which will pick it up. 
virtual bool food::interact(const object & check_interaction)
{
  return check_interaction.import_object(*this);
}

