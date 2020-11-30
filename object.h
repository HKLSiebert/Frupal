//first draft of object class
#include <string.h>
using namespace std;

struct color{
    int r = 0;
    int g = 0;
    int b = 0;

    bool copy(const color&source)
    {
        this.r = source.r;
        this.g = source.g;
        this.b = source.b;
        
        return this.r==source.r && this.g==source.g&&this.b == source.b;

    }
};

virtual class object
{
    public:
        object();
        object(const object& source);
        ~object();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i);
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
        hero();
        hero(const hero& source);
        ~hero();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const; 
        virtual bool copy_object(/*unknown args*/);
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
        grovnic(const grovnic & source);
        ~grovnic();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
    protected:
        int energy_cost;

    private:



};


virtual class item: public object
{
    public:
        item();
        ~item();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
    protected:


};


class tool: public item
{
    public:
        tool();
        ~tool();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        
        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
    protected:        

}

class food: public item
{
    public:
        food();
        ~food();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        
    protected:
        int wiffle_cost;
        int energy_restoration;
}

        
