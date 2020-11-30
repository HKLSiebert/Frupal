
#include <object.h>

//object class

object::object()
{

}

object::object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i):name = name_i:description=description_i:display_char=display_char_i
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

virtual bool object::import_object(string name_i, string description_i, char display_char_i, color char_color_i, color background_color_i)
{
    //incomplete

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
virtual bool interact(const object & check_interaction)
{
    //incomplete
    return true;
}




hero::hero()
{

}

hero::hero()
{

}

hero::hero(const object& source)
{
    copy_object(source);
}

~hero::hero()
{
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

virtual bool hero::import_object(/*unknown args*/);
{
    //incomplete
    return true;
}
virtual bool hero::copy_object(const object & source);
{
    //incomplete
    return true;
}


virtual bool hero::interact(const object & check_interaction);
{
    //incomplete
    return true;
}

string[] hero::get_inventory_list()const;
{


}

object* hero::get_inventory_items();
{


}


