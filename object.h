//first draft of object class
#include <string.h>
#include <sstream>
using namespace std;

struct color{
    int r = 0;
    int g = 0;
    int b = 0;

    bool copy(const color&source)
    {
        r = source.r;
        g = source.g;
        b = source.b;

        return r==source.r && g==source.g&&b == source.b;

    }
};

const static int Inventory_size = 100;

class object
{
    public:
        object();
        object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i);
        object(const object& source);
        virtual ~object();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i);
        virtual bool copy_object(const object& source);
        virtual string get_name()const;
        virtual string get_description()const;

        //not sure how we are passing color yet. It could be a struct with the appropriate ints I think the display class can answer how color should be passed

    protected:
        string name;
        string description;
        char display_char;
        color char_color;
        color background_color;

    private:

};

class hero: public object
{
    public:
        hero();
        hero(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object* inventory_i[Inventory_size]);
        hero(const hero& source);
        virtual ~hero();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const; 
        virtual bool copy_object(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object* inventory_i[Inventory_size]);
        virtual bool copy_object(const hero & source);
        bool interact(const object& check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;
        bool check_binoculars()const;

        string* get_inventory_list()const;
        object** get_inventory_items();
    protected:
        int check_inventory(const string grov_obst_name);
        bool binoculars;
        bool add_to_inventory(object* & inventory_item);//this will null whatever pointer is passed to the function if it returns true
        object** inventory;
        int energy;
        int wiffle;

    private:
};

class grovnic: public object
{
    public:
        grovnic();
        grovnic(grovnic &toCopy);
        grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar);
        grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar, class tool &inv);
        grovnic(string name, string desc, color bgColor, int cost, color displayColor, char displayChar, class food &inv);
        grovnic(string name, string desc, color bgColor, int cost);
        ~grovnic();
        char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const;
        
        string get_item_info() const;
        class item* get_item();
        bool is_occupied();
        bool is_Seen();
        void toggleSeen();
        bool empty_inventory();
        
        string get_name()const;
        string get_description()const;

    protected:
        bool isSeen;
        int energy_cost;
        class item* inventory; //only one object can occupy a grovnik

    private:
};


class item: public object
{
    public:
        item();
        item(item &toCopy);
        item(string name, string desc, char displayChar, color charColor);
        virtual ~item();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        
        
        virtual string get_name()const;
        virtual string get_description()const;
        virtual string get_item_info() const;

    protected:


};


class tool: public item
{
    public:
        tool();
        tool(tool &toCopy);
        tool(string name, string desc, color itemColor, char displayChar, string eff, int mult);
        virtual ~tool();
        char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const;

        string get_item_info() const;
        string get_effect()const;
        int get_multiplier()const;

    protected:        
      string effectiveAgainst;
      int multiplier; 

};

class food: public item
{
    public:
        food();
        food(food &toCopy);
        food(string name, string desc, color itemColor, char displayChar, int wCost, int eRest);
        char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const;
        int get_cost() const;
        int get_rest() const;
        string get_item_info() const;
        
        virtual ~food();

    protected:
        int wiffle_cost;
        int energy_restoration;
};
