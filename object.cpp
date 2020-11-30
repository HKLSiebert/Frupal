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
virtual bool object::interact(const object & check_interaction)
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

bool hero::add_to_inventory(object& inventory_item);
{
    int i = 0;
    while(inventory[i++]);//finds first empty inventory spot
    inventory[i] = & inventory_item;
}

bool hero::interact(const object & check_interaction);
{
      //incomplet
      food * ptr = dynamic_cast<food *>(check_interaction);
      if (ptr) {
        if (wiffle >= check_interaction.wiffle_cost){
          wiffle -= check_interaction.wiffle_cost;
          energy += check_interaction.energy_restoration;
          return true;
        }
      }
      tool * ptr2 = dynamic_cast<tool *>(check_interaction);
      if (ptr2){
        this.copy_object(check_interaction);
        return true;
      }
      grovnic * pt3 = dynamic_cast<grovnic *>(check_interaction)
      if (ptr3){
        if (strcmp(check_interaction.name, inventory->effectiveAgainst) == 0){
          wiffle -= (check_interaction.energy_cost/inventory->multiplier);
          check_interaction.interact(inventory);
          //display char cannot change here
          return true;
        }
      }
      return false;
}
  
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

char grovnic::get_display_char()const
{
  if(inventory)
    return inventory.get_display_char();
  return NULL;
}

color grovnic::get_char_color()const
{
  if(inventory)
    return inventory.get_char_color();
  return NULL;
}

/*color grovnic::get_background_color()const
{
}
*/ 

bool grovnic::copy_object(const object & source)
{

}

//Takes an object and adds it to the grovnic's inventory
bool grovnic::import_object(/**/)
{
}

//Assumed to only be hero interacting to puck up tool/food
//TODP - obstacle RTTI
bool grovnic::interact(const object & check_interaction)
{
  //Needs to potentially remove the grocnik item as well as lower hero stats
  display_char = '\0';
  return true;
}

void grovnic::get_item_info() const
{
  if (!inventory) return NULL;

  osstringstream oss;

  food * ptr = dynamic_cast<food *> (inventory);
  if (ptr) {
    oss << "Name: " << inventory.name << " Wiffles cost: " << inventory.wiffle_cost << " Energy Restoration: " << inventory.energy_restoration; 
  }
  else {
    oss << "Name: " << inventory.name << " Effective Against: " << inventory.effectiveAgainst << " Multiplier: " << inventory.multiplier; 
  }
  string ret = oss.str();
  return ret;
}


item* grovnic::get_item()
{
  return inventory;  
}

bool grovnic::is_occupied()
{
  if (inventory) return true;
  else return false;
}

item::item():object()
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
//Interact with grovnic or tool? 
virtual bool item::interact(const object & check_interaction)
{

//  return check_interaction.import_object(*this);
  return false;

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
char tool::get_display_char()const
{}

color tool::get_char_color()const
{}

color tool::get_background_color()const
{}

bool tool::copy_object(const object & source)
{}

bool tool::import_object(/*unknown args*/)
{
  return true;
}

bool tool::interact(const object & check_interaction)
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

//All food has the same cymbofor now
char food::get_display_char()const
{
//  return F;
}

color food::get_char_color()const
{

}

color food::get_background_color()const
{

}

bool food::copy_object(const object & source)
{

}

bool food::import_object(/*unknown args*/)
{

}

//The only thing ineracting with foos should be the hero, which will pick it up. 
bool food::interact(const object & check_interaction)
{
  return check_interaction.import_object(*this);
}

int* bool food::get_cost_rest(){

  return [wiffle_cost, energy_restoration];

}
