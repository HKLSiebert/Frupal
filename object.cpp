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
      const object * temp = &check_interaction;
      const grovnic * ptr3 = dynamic_cast<const grovnic *>(temp);
      if (ptr3){
        if (strcmp(check_interaction.get_name(), inventory->effectiveAgainst) == 0){
          wiffle -= (energy_cost/inventory->get_multiplier());
          ptr3->interact(inventory);
          //display char cannot change here
          return true;
        }
      }
      const item * ptr4 = dynamic_cast<const item *>(temp);
      if (ptr4){
        const food * ptr = dynamic_cast<const food *>(temp);
        if (ptr) {
          int cost = ptr->get_cost();
          int rest = ptr->get_rest();
          if (wiffle >= cost){
            wiffle -= cost;
            energy += rest;
            return true;
          }
        }
        const tool * ptr2 = dynamic_cast<const tool *>(temp);
        if (ptr2){
          this->copy_object(&check_interaction);
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
    inventory = new tool(toCopy.inventory);
}

grovnic::grovnic(string name, color bgColor, int cost, color displayColor, char displayChar):object(/*TODO*/), energy_cost(cost), inventory(NULL)
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
    return inventory->get_display_char();
  return NULL;
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
}

bool grovnic::copy_object(const object & source)
{

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

bool grovnic::is_occupied()
{
  if (inventory) return true;
  else return false;
}

item::item():object()
{}

item::item(item &toCopy):object(toCopy)
{}

item::item(string name, color itemColor, char displayChar):object(/*TODO*/)
{}

item::~item()
{}

char item::get_display_char()const
{}

color item::get_char_color()const
{}

color item::get_background_color()const
{}

bool item::copy_object(const object & source)
{

}

tool::tool():effectiveAgainst(NULL), multiplier(1)
{}

tool::tool(tool &toCopy):item(toCopy), effectiveAgainst(toCopy.effectiveAgainst), multiplier(toCopy.multiplier)
{}

tool::~tool()
{
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

  oss << "Name: " << name << " Effective Against: " << effectiveAgainst << " Multiplier: " << multiplier; 
  string ret = oss.str();
  return ret;
}
food::food():wiffle_cost(0), energy_restoration(0)
{

}

food::food(food &toCopy): item(toCopy), wiffle_cost(toCopy.wiffle_cost), energy_restoration(toCopy.energy_restoration)
{}

food::food(string name, color itemColor, char displayChar, int wCost, int eRest):item(name, itemColor, displayChar), wiffle_cost(wCost), energy_restoration(eRest)
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

int food::get_cost() const{

  return wiffle_cost;

}

int food::get_rest() const{

  return energy_restoration;

}

string food::get_item_info() const
{
  stringstream oss;

  oss << "Name: " << name << " Wiffles cost: " << wiffle_cost << " Energy Restoration: " << energy_restoration; 
  string ret = oss.str();
  return ret;
}
