//first draft of object class
#include <string.h>
#include <sstream.h>
using namespace std;


virtual class object
{
    public:
        object();
        ~object();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool import_object(/*unknown args*/);
        virtual bool copy_object(const object & source);
        
        //not sure how we are passing color yet. It could be a struct with the appropriate ints I think the display class can answer how color should be passed
        virtual bool interact(const object & check_interaction);

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
        hero();//constructor
        ~hero();
        char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const; 
        bool import_object(/*unknown args*/);
        bool copy_object(const object & source);
        bool interact(const object & check_interaction);
        string[] get_inventory_list()const;
        object* get_inventory_items();
    protected:
        object* inventory;
        int energy;
        int wiffle;

    private:
};

class grovnic: public object
{
    public:
        grovnic();
        grovnic(grovnic &toCopy);
        grovnik(string name, color bgColor, int cost, color displayColor, char displayChar);
        grovnic(string name, color bgColor, int cost);
        ~grovnic();
        char get_display_char()const;
        color get_char_color()const;
        /*color get_background_color()const;*/
        bool copy_object(const object & source);
        
        bool import_object(/*unknown args*/);
        bool interact(const object & check_interaction);
        string* get_item_info();
        item* get_item();
        
    protected:
        int energy_cost;
        item* inventory; //only one object can occupy a grovnik


    private:



};


virtual class item: public object
{
    public:
        item();
        item(item &toCopy);
        item(string name, color itemColor, char displayChar);
        ~item();
        /*virtual char get_display_char()const = 0;
        virtual color get_char_color()const = 0;
        virtual color get_background_color()const = 0;
        virtual bool copy_object(const object & source) =0;
        
        virtual bool import_object(/*unknown args*/) = 0;
        /*virtual bool interact(const object & check_interaction) = 0;*/
        
    protected:


};


class tool: public item
{
    public:
        tool();
        tool(tool &toCopy);
        ~tool();
        /*char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const;*/
        bool copy_object(const object & source);
        
        bool import_object(/*unknown args*/);
        bool interact(const object & check_interaction);
    protected:        
      string effectiveAgainst;
      int multiplier; 

}

class food: public item
{
    public:
        food();
        food(good &toCopy);
        food(string name, color itemColor, char displayChar, int wCost, int eRest);
        ~food();
        /*char get_display_char()const;
        color get_char_color()const;
        color get_background_color()const;*/
        bool copy_object(const object & source);
        bool import_object(/*unknown args*/);
        bool interact(const object & check_interaction);
        int* bool get_cost_rest();
        
    protected:
        int wiffle_cost;
        int energy_restoration;
}
