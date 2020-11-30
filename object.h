//first draft of object class
#include <string>
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
        virtual bool copy_object(const object & source);
        virtual string get_name()const;
        virtual string get_description()const;

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
        hero(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object inventory_i[Inventory_size]);
        hero(const object& source);
        virtual ~hero();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const; 
        virtual bool copy_object(const string name_i, const string description_i, const char display_char_i, const color char_color_i,const  color background_color_i,const int energy_i, const int wiffle_i, const object inventory_i[Inventory_size]);
        virtual bool copy_object(const object & source);
        virtual bool interact(const object & check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;

        string* get_inventory_list()const;
        object* get_inventory_items();
    protected:
        bool add_to_inventory(object*& inventory_item);//this will null whatever pointer is passed to the function if it returns true
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
        virtual ~grovnic();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);

        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;

    protected:
        int energy_cost;

    private:



};


class item: public object
{
    public:
        item();
        virtual ~item();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);

        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;

    protected:


};


class tool: public item
{
    public:
        tool();
        virtual ~tool();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);

        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;

    protected:        

};

class food: public item
{
    public:
        food();
        virtual ~food();
        virtual char get_display_char()const;
        virtual color get_char_color()const;
        virtual color get_background_color()const;
        virtual bool copy_object(const object & source);
        virtual bool copy_object(/*unknown args*/);
        virtual bool interact(const object & check_interaction);
        virtual string get_name()const;
        virtual string get_description()const;


    protected:
        int wiffle_cost;
        int energy_restoration;
};


