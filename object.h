//first draft of object class
#include <string.h>
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
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const; 
        virtual bool import_object(/*unknown args*/);
        virtual bool copy_object(const object & source);
        virtual bool interact(const object & check_interaction);
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
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool import_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        
    protected:
        int energy_cost;
        object* inventory; //only one object can occupy a grovnik


    private:



};


virtual class item: public object
{
    public:
        item();
        item(item &toCopy);
        item(string name, color itemColor, char displayChar);
        ~item();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool import_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
    protected:


};


class tool: public item
{
    public:
        tool();
        tool(tool &toCopy);
        ~tool();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool import_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
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
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        virtual bool import_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        
    protected:
        int wiffle_cost;
        int energy_restoration;
}
