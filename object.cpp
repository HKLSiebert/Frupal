
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



