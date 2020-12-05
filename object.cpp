#include "object.h"

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


char object::get_display_char()const
{
      return display_char;
}

color object::get_char_color()const
{
      return char_color;
}

color object::get_background_color()const
{
      return background_color;
}

string object::get_name()const
{
    return name;
}

string object::get_description()const
{
    return description;

}

bool object::copy_object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i)
{
    name = name_i;
    description = description_i;
    display_char = display_char_i;
    char_color.copy(char_color_i);
    background_color.copy(background_color_i);

    return true;
}


bool object::copy_object(const object & source)
{
    name = source.name;
    description = source.description;
    display_char = source.display_char;
    char_color.copy(source.char_color);
    background_color.copy(source.background_color);
    return true;
}

hero::hero()
{
    inventory = new object*[Inventory_size];

}

hero::hero(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object* inventory_i[Inventory_size]):object(name_i, description_i, display_char_i, char_color_i, background_color_i), energy(energy_i),wiffle(wiffle_i)
{
    inventory = new object*[Inventory_size];
    if(inventory)
    {
        for(int i =0; i<Inventory_size; ++i)
        {
            inventory[i] = new object(*(inventory_i[i]));
        }
    }
}

hero::hero(const hero& source):object(source),energy(source.energy),wiffle(source.wiffle)
{

    inventory = new object*[Inventory_size];
    for(int i =0; i<Inventory_size; ++i)
    {
        inventory[i] = new object(*(source.inventory[i]));
    }
}

hero::~hero()
{
    for(int i =0; i<Inventory_size; ++i)
    {
       delete inventory[i];
    }
    delete inventory;
}

char hero::get_display_char()const
{
    return display_char;
}


color hero::get_char_color()const
{
    return char_color;
}


color hero::get_background_color()const 
{
    return background_color;
}

string hero::get_name()const
{
    return name;
}

string hero::get_description()const
{
    return description;

}

bool hero::copy_object(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object* inventory_i[Inventory_size])
{ 
    object::copy_object(name_i, description_i, display_char_i,char_color_i, background_color_i);
    energy = energy_i;
    wiffle = wiffle_i;
    if(inventory)
    {
        for(int i =0; i<Inventory_size; ++i)
        {
            inventory[i] = new object(*(inventory_i[i]));
        }
    }
    return true;
}

bool hero::copy_object(const hero & source)
{
    object::copy_object(source);
    for(int i =0; i<Inventory_size; ++i)
    {
        inventory[i] = new object(*(source.inventory[i]));
    }
    energy = source.energy;
    wiffle = source.wiffle;
    return true;
}


string* hero::get_inventory_list()const
{
    string* inventory_items = new string[Inventory_size];
    for(int i =0;i<Inventory_size;++i)
    {
        if(inventory[i])
        {
            inventory_items[i] = inventory[i]->get_name();
        }

    }

    return inventory_items;
}


object** hero::get_inventory_items()
{
    return inventory;
}

bool hero::add_to_inventory(object*& inventory_item)
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

bool hero::interact(const object & check_interaction)
{
      //incomplet
      return false;
}
  
grovnic::grovnic():energy_cost(0), inventory(NULL)
{}

grovnic::grovnic(grovnic &toCopy):object(toCopy), energy_cost(toCopy.energy_cost)
{
  if(toCopy.inventory)
  {
    inventory = new item(*(toCopy.inventory));
  }
}

grovnic::grovnic(string name, string content, string desc):object(name, NULL, '\0', color(), color())
{
  if (name == "meadow")
  {
    energy_cost = 1;

  }
  else if (name == "swamp")
  {
    energy_cost = 2;
  }
  else if (name == "water" || name =="wall")
  {
    energy_cost = 101;
  }

  if (!content.empty())
  {
    if (content == "axe")
      inventory = new tool(content, desc, color(), '\0', "tree", 2);
    else if (content == "hammer")
      inventory = new tool(content, desc, color(), '\0', "boulder", 4);
    else if (content == "tree")
      inventory = new obstacle(content, desc, color(), '\0', 19);
    else if (content == "boulder")
      inventory = new obstacle(content, desc, color(), '\0', 27);
    else if (content == "diamonds"|| content == "clue")
      inventory = new item(content, desc, '\0', color());
    else if (content == "food")
      inventory = new food(content, desc, color(), '\0', 50, 100);
  }
}

grovnic::grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar):object(name, desc, displayChar, displayColor, bgColor), energy_cost(cost), inventory(NULL)
{}

grovnic::grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar, tool & inv):object(name, desc, displayChar, displayColor, bgColor), energy_cost(cost)
{
  inventory = new tool(inv);
}

grovnic::grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar, food & inv):object(name, desc, displayChar, displayColor, bgColor), energy_cost(cost)
{
  inventory = new food(inv);
}

grovnic::grovnic(string name, string desc, color bgColor, int cost):object(name, desc, '\0', color(), bgColor), energy_cost(cost), inventory(NULL)
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
    return inventory->get_display_char();
  return display_char;
}

color grovnic::get_char_color()const
{
  if(inventory)
    return inventory->get_char_color();
  color ret;
  ret.r = 0;
  ret.g = 0;
  ret.b = 0;
  return ret;
}

color grovnic::get_background_color()const
{
  return background_color;
}

string grovnic::get_item_info() const
{
  if (!inventory) return NULL;

  string ret = inventory->get_item_info();
  return ret;
}


item* grovnic::get_item()
{
  return inventory;  
}

bool grovnic::add_item(class item & toCopy)
{
  inventory = new item(toCopy);
  return true;
}

bool grovnic::is_occupied()
{
  if (inventory) return true;
  else return false;
}

bool grovnic::is_Seen()
{
  return isSeen; 
}

void grovnic::toggleSeen()
{
  if (!isSeen)
    isSeen = true;
  return;
}

//Call get_item() before this method in order to get inventory for "trash"
bool grovnic::empty_inventory()
{
  if (inventory)
  {
    inventory = NULL;
    return true;
  }
  return false;
}

string grovnic::get_name()const
{
  return name;
}

string grovnic::get_description()const
{
  return description;
}

int grovnic::get_total_energy_cost()const
{
  if (inventory){
    obstacle * ptr = dynamic_cast<obstacle *>(inventory);
    if (ptr)
    {
      return energy_cost + ptr->get_eCost();
    }
  }
  return energy_cost;
}

item::item():object()
{}

item::item(item &toCopy):object(toCopy)
{}

item::item(string name, string desc, char displayChar, color itemColor):object(name, desc, displayChar, itemColor, color())
{}

item::~item()
{}

char item::get_display_char()const
{
  return display_char;
}

color item::get_char_color()const
{
  return char_color;
}

color item::get_background_color()const
{
  return background_color;
}

string item::get_name()const
{
  return name;
}

string item::get_description()const
{
  return description;
}

string item::get_item_info()const
{
  
}

tool::tool():effectiveAgainst(NULL), multiplier(1)
{}

tool::tool(tool &toCopy):item(toCopy), effectiveAgainst(toCopy.effectiveAgainst), multiplier(toCopy.multiplier)
{}

tool::tool(string name, string desc, color itemColor, char displayChar, string eff, int mult):item(name, desc, displayChar, itemColor), effectiveAgainst(eff), multiplier(mult)
{}

tool::~tool()
{
}

//All toolds will be a lowercase t 
char tool::get_display_char()const
{
  return display_char;
}

color tool::get_char_color()const
{
  return char_color;
}

color tool::get_background_color()const
{
  return background_color;
}

string tool::get_effect()const
{
  return effectiveAgainst;
}

int tool::get_multiplier()const
{
  return multiplier;
}

string tool::get_item_info() const
{
  stringstream oss;

  oss << ">>Name: " << name << "\n>>Effective Against: " << effectiveAgainst << "\n>>Multiplier: " << multiplier; 
  string ret = oss.str();
  return ret;
}

food::food():wiffle_cost(0), energy_restoration(0)
{}

food::food(food &toCopy): item(toCopy), wiffle_cost(toCopy.wiffle_cost), energy_restoration(toCopy.energy_restoration)
{}

food::food(string name, string desc, color itemColor, char displayChar, int wCost, int eRest):item(name, desc, displayChar, itemColor), wiffle_cost(wCost), energy_restoration(eRest)
{}

food::~food()
{}

char food::get_display_char()const
{
  return display_char;
}

color food::get_char_color()const
{
  return char_color;
}

color food::get_background_color()const
{
  return background_color;
}

int food::get_cost() const{

  return wiffle_cost;

}

int food::get_rest() const{

  return energy_restoration;

}

string food::get_item_info() const
{
  stringstream oss;

  oss << ">>Name: " << name << "\n>>Wiffles cost: " << wiffle_cost << "\n>>Energy Restoration: " << energy_restoration; 
  string ret = oss.str();
  return ret;
}

obstacle::obstacle():eCost(0)
{}

obstacle::obstacle(obstacle &toCopy):item(toCopy), eCost(toCopy.eCost)
{}

obstacle::obstacle(string name, string desc, color itemColor, char displayChar, int cost):item(name, desc, displayChar, itemColor), eCost(eCost)
{}

obstacle::~obstacle()
{}

char obstacle::get_display_char()const
{
  return display_char;
}
color obstacle::get_char_color()const
{
  return char_color;
}

color obstacle::get_background_color()const
{
  return background_color;
}

int obstacle::get_eCost() const
{
  return eCost;
}

string obstacle::get_item_info() const
{
  stringstream oss;

  oss << ">>Name: " << name << "\n>>Energy Cost: " << eCost;
  string ret = oss.str();
  return ret; 
  
}
